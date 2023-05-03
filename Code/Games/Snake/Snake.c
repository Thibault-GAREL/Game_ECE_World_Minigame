#include "Snake.h"

/*
gcc -g -Wall *.c .\Utils\*.c .\Games\Exemple\*.c .\Games\PecheAuCanards\*.c .\Games\Snake\*.c .\Games\Traverse_de_la_riviere\*.c  -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf -lallegro_acodec -lallegro_audio  -oExemple
*/

void SnakeGame_Create(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = malloc(sizeof(SNAKE_DATA));

    _pSnake->gameData = pSnakeData;
    pSnakeData->pSnake = calloc(1, sizeof(SNAKE));

    Snake_Add_Part(&pSnakeData->pSnake->pHead, &pSnakeData->pSnake->size);
    
    pSnakeData->pSnake->pHead->position.x = 1920 / 2;
    pSnakeData->pSnake->pHead->position.y = 1080 / 2;

    pSnakeData->pSnake->speed = SNAKE_SPEED_START;
    pSnakeData->pSnake->direction = (VECTOR2D_INT) {1,0};
    pSnakeData->pSnake->pClone = al_load_bitmap("..\\Textures\\Snake\\Clone.png");

    pSnakeData->foodCount = 0;
    pSnakeData->pFood1 = al_load_bitmap("..\\Textures\\Snake\\food1.png");
    pSnakeData->currentPlayer = 0;
    pSnakeData->gameState = GAME_STATE_RUNNING;
    pSnakeData->pScoreFont50 = al_load_font("..\\Textures\\Fonts\\police.TTF", 50, 0);
    pSnakeData->pScoreFont16 = al_load_font("..\\Textures\\Fonts\\police.TTF", 16, 0);

    Load_DarkVadorHolo(pSnakeData->DarkVadorHolo);
    pSnakeData->pDarkVador = Animation_Create((VECTOR2D_INT){20,910}, 30, 1, 7, pSnakeData->DarkVadorHolo);
    Animation_Enable_ScaleFactor(pSnakeData->pDarkVador, (Vector2D){0.1f, 0.1f});
    Animation_Enable_StartState(pSnakeData->pDarkVador, ANIMATION_STATE_STOP);

    pSnakeData->desert = al_load_bitmap("..\\Textures\\Snake\\Desert.png");
}

void SnakeGame_Update(PGAME _pSnake)
{
    if (_pSnake->gameData == NULL)
    {
        SnakeGame_Create(_pSnake);
    }

    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_Q,0, 1, 0, 0))
    {
        pSnakeData->pSnake->direction.x = -1;
        pSnakeData->pSnake->direction.y = 0;
    }

    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_D,0, 1, 0, 0))
    {
        pSnakeData->pSnake->direction.x = 1;
        pSnakeData->pSnake->direction.y = 0;
    }
     
    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_Z, 0, 1, 0, 0))
    {
        pSnakeData->pSnake->direction.x = 0;
        pSnakeData->pSnake->direction.y = -1;
    }

    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_S,0, 1, 0, 0))
    {
        pSnakeData->pSnake->direction.x = 0;
        pSnakeData->pSnake->direction.y = 1;
    }
    
    Food_CheckCollision(_pSnake);
    Food_Generation(_pSnake);

    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        SnakeGame_Destroy(_pSnake);
    }
}

void SnakeGame_TimedUpdate(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    pSnakeData->pSnake->step += pSnakeData->pSnake->speed;
    pSnakeData->pSnake->speed = SNAKE_SPEED_START + pSnakeData->pSnake->size * SNAKE_SPEED_INCREASE;
    
    if (pSnakeData->pSnake->step > SNAKE_STEP_TIME)
    {
        VECTOR2D_INT newPos;
        newPos.x = pSnakeData->pSnake->pHead->position.x + pSnakeData->pSnake->direction.x * CLONE_SIZE;
        newPos.y = pSnakeData->pSnake->pHead->position.y + pSnakeData->pSnake->direction.y * CLONE_SIZE;
        Snake_Move(pSnakeData->pSnake->pHead, newPos);
        pSnakeData->pSnake->step = 0;
    }

    al_draw_bitmap(pSnakeData->desert, -100, -100, 0);

    Snake_Draw(pSnakeData->pSnake->pHead, pSnakeData->pSnake);

    for (int i = 0; i < pSnakeData->foodCount; i++)
    {
        al_draw_scaled_bitmap(pSnakeData->pFood1, 0, 0, FOOD_ORIGINAL_SIZE, FOOD_ORIGINAL_SIZE, pSnakeData->foods[i].foodPos.x, pSnakeData->foods[i].foodPos.y, FOOD_SIZE, FOOD_SIZE, 0);
        
        /*Vector2D foodPos1 = {pSnakeData->foods[i].foodPos.x, pSnakeData->foods[i].foodPos.y};
        Vector2D foodPos2 = {pSnakeData->foods[i].foodPos.x + FOOD_SIZE, pSnakeData->foods[i].foodPos.y + FOOD_SIZE};

        al_draw_rectangle(foodPos1.x, foodPos1.y, foodPos2.x, foodPos2.y, al_map_rgb(255, 0, 0), 5);*/
    }

    Draw_UI(*pSnakeData);

    if (Snake_EatSelf(pSnakeData->pSnake->pHead->previous, pSnakeData->pSnake->pHead->position))
    {
        NextPlayer(_pSnake);
    }

    //Snake collide size
    if (pSnakeData->pSnake->pHead->position.x <= 0 || pSnakeData->pSnake->pHead->position.y <= 0 || pSnakeData->pSnake->pHead->position.x >= 1920 || pSnakeData->pSnake->pHead->position.y >= 1080)
    {
        NextPlayer(_pSnake);
    }
    
    //al_draw_circle(pSnakeData->pSnake->pHead->position.x, pSnakeData->pSnake->pHead->position.y, 8, al_map_rgb(0, 255, 0), 3);
}

void SnakeGame_Destroy(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    Snake_Destroy_AllParts(pSnakeData->pSnake->pHead);
    al_destroy_bitmap(pSnakeData->pSnake->pClone);

    free(pSnakeData->pSnake);
    al_destroy_font(pSnakeData->pScoreFont50);
    al_destroy_font(pSnakeData->pScoreFont16);
    Animation_Destroy(pSnakeData->pDarkVador);
    al_destroy_bitmap(pSnakeData->desert);
    
    free(pSnakeData);
    
    _pSnake->gameData = NULL;
    *_pSnake->pCurrentGameId = GAME_NONE;
}


void Snake_Add_Part(PSNAKE_PART* _ppSnakePart, int* _pSize) 
{
    if (*_ppSnakePart)
    {
        Snake_Add_Part(&(*_ppSnakePart)->previous, _pSize);
    }
    else
    {
        *_ppSnakePart = (PSNAKE_PART)calloc(1, sizeof(SNAKE_PART));
        (*_ppSnakePart)->position.x = - 100;
        (*_pSize)++;
    }
}

void Snake_Destroy_AllParts(PSNAKE_PART _pSnakePart)
{
    if (_pSnakePart->previous)
    {
        Snake_Destroy_AllParts(_pSnakePart->previous);
    }
    
    free(_pSnakePart);
}

void Snake_Draw(PSNAKE_PART _pSnakePart, PSNAKE _pSnake)
{
    float scaleFactor = (float)CLONE_SIZE / CLONE_ORIGINAL_SIZE;
    al_draw_scaled_rotated_bitmap(_pSnake->pClone, CLONE_ORIGINAL_SIZE / 2, CLONE_ORIGINAL_SIZE / 2, _pSnakePart->position.x, _pSnakePart->position.y, scaleFactor, scaleFactor, _pSnakePart->directionAngle, 0);

    if (_pSnakePart->previous)
    {
        Snake_Draw(_pSnakePart->previous, _pSnake);
    }
}

void Snake_Move(PSNAKE_PART _pSnakePart, VECTOR2D_INT _position)
{
    if (!_pSnakePart)
    {
        return;
    }

    if (_pSnakePart->previous)
    {
        Snake_Move(_pSnakePart->previous, _pSnakePart->position);
    }

    VECTOR2D_INT deltaPosition = {_position.x - _pSnakePart->position.x, _position.y - _pSnakePart->position.y};
    _pSnakePart->directionAngle = Vector2D_Get_Angle((Vector2D){deltaPosition.x, deltaPosition.y});
    //printf("(%d;%d) angle=%f\n", deltaPosition.x, deltaPosition.y, _pSnakePart->directionAngle);
    
    _pSnakePart->position.x = _position.x;
    _pSnakePart->position.y = _position.y;
}

int Snake_EatSelf(PSNAKE_PART _pSnakePart, VECTOR2D_INT _headPosition)
{
    if (!_pSnakePart)
    {
        return 0;
    }
    
    if (_pSnakePart->position.x == _headPosition.x && _pSnakePart->position.y == _headPosition.y)
    {
        return 1;
    }

    return Snake_EatSelf(_pSnakePart->previous, _headPosition);
}


void Food_Generation(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    if (pSnakeData->foodCount >= FOOD_COUNT_MAX)
    {
        return;
    }
    
    if (rand() % FOOD_PROBA)
    {
        return;
    }
    
    pSnakeData->foodCount++;
    pSnakeData->foods[pSnakeData->foodCount - 1].foodPos.x = rand() % (1870 - 2 * FOOD_SIZE) + 2 * FOOD_SIZE;
    pSnakeData->foods[pSnakeData->foodCount - 1].foodPos.y = rand() % (1030 - 2 * FOOD_SIZE) + 2 * FOOD_SIZE;
}

void Food_CheckCollision(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    for (int i = 0; i < pSnakeData->foodCount; i++)
    {
        Vector2D foodPos1 = {pSnakeData->foods[i].foodPos.x, pSnakeData->foods[i].foodPos.y};
        Vector2D foodPos2 = {pSnakeData->foods[i].foodPos.x + FOOD_SIZE, pSnakeData->foods[i].foodPos.y + FOOD_SIZE};

        if (Point_In_Rectangle((Vector2D){pSnakeData->pSnake->pHead->position.x, pSnakeData->pSnake->pHead->position.y}, foodPos1, foodPos2))
        {
            Snake_Add_Part(&pSnakeData->pSnake->pHead, &pSnakeData->pSnake->size);
            pSnakeData->foodCount--;
            
            for (int j = i; j < pSnakeData->foodCount; j++)
            {
                pSnakeData->foods[j] = pSnakeData->foods[j + 1];
            }
            
            return;
        }
    }
}


void Draw_UI(SNAKE_DATA _snakeData)
{
    int score = _snakeData.pSnake->size;

    int scoreDec[4] = {0, 0, 0, 0};
    scoreDec[0] = score / 1000;
    scoreDec[1] = (score - scoreDec[0] * 1000) / 100;
    scoreDec[2] = (score - scoreDec[0] * 1000 - scoreDec[1]  * 100) / 10;
    scoreDec[3] = (score - scoreDec[0] * 1000 - scoreDec[1] * 100 - scoreDec[2] * 10);

    char zero = '0';
    char scoreStr[5] = "0000\0";

    for (size_t i = 0; i < 4; i++)
    {
        scoreStr[i] = scoreDec[i] + zero;
    }

    al_draw_text(_snakeData.pScoreFont50, al_map_rgba(100, 100, 100, 254), 806, 106, 0, scoreStr);
    al_draw_text(_snakeData.pScoreFont50, al_map_rgb(200, 110, 100), 800, 100, 0, scoreStr);

    char joueurNo[3] = "J0\0";
    joueurNo[1] += _snakeData.currentPlayer + 1;

    al_draw_text(_snakeData.pScoreFont50, al_map_rgba(100, 100, 100, 254), 106, 106, 0, joueurNo);
    al_draw_text(_snakeData.pScoreFont50, al_map_rgb(200, 110, 100), 100, 100, 0, joueurNo);

    int commentProgress0 = _snakeData.pDarkVador->currentStep < 56 ? _snakeData.pDarkVador->currentStep : 56;
    char darkVadorComment0[] = "Enrolez le plus de clone que possible dans mon armée !";
    darkVadorComment0[commentProgress0] = '\0';
    
    al_draw_text(_snakeData.pScoreFont16, al_map_rgb(200, 255, 255), 200, 960, 0, darkVadorComment0);
    
    int commentProgress1 = _snakeData.pDarkVador->currentStep > 56 ? _snakeData.pDarkVador->currentStep - 56 : 0;
    commentProgress1 = commentProgress1 > 12 ? 12 : commentProgress1; 
    char darkVadorComment1[] = "Plus vite !";
    darkVadorComment1[commentProgress1] = '\0';
    
    al_draw_text(_snakeData.pScoreFont16, al_map_rgb(200, 255, 255), 200, 980, 0, darkVadorComment1);

    Animation_Update_Step(_snakeData.pDarkVador);
    Animation_Draw(_snakeData.pDarkVador);
}


void NextPlayer(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    if (++pSnakeData->currentPlayer >= _pSnake->playersCount)
    {
        SnakeGame_Destroy(_pSnake);
    }
    else
    {
        pSnakeData->foodCount = 0;

        Snake_Destroy_AllParts(pSnakeData->pSnake->pHead);
        pSnakeData->pSnake->pHead = NULL;
        pSnakeData->pSnake->size = 0;

        Snake_Add_Part(&pSnakeData->pSnake->pHead, &pSnakeData->pSnake->size);
        pSnakeData->pSnake->pHead->position.x = 1920 / 2;
        pSnakeData->pSnake->pHead->position.y = 1080 / 2;

        pSnakeData->pDarkVador->currentStep = ANIMATION_STATE_REPLAY;
    }
}


void Load_DarkVadorHolo(ALLEGRO_BITMAP* DarkVadorHolo[7])
{
    DarkVadorHolo[0] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic0.png");
    DarkVadorHolo[1] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic1.png");
    DarkVadorHolo[2] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic2.png");
    DarkVadorHolo[3] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic3.png");
    DarkVadorHolo[4] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic4.png");
    DarkVadorHolo[5] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic5.png");
    DarkVadorHolo[6] = al_load_bitmap("..\\Textures\\Snake\\DarkVadorAnimation\\DarkVadorHolographic6.png");
}
