#include "Snake.h"

/*
gcc -g -Wall *.c .\Utils\*.c .\Games\Exemple\*.c .\Games\Snake\*.c -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf -lallegro_acodec -lallegro_audio  -oExemple
*/

void SnakeGame_Create(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = malloc(sizeof(SNAKE_DATA));
    _pSnake->gameData = pSnakeData;
    pSnakeData->pSnake = calloc(1, sizeof(SNAKE));
    Snake_Add_Part(&pSnakeData->pSnake->pHead, &pSnakeData->pSnake->size);
    pSnakeData->pSnake->speed = 1;
    pSnakeData->pSnake->pClone = al_load_bitmap("..\\Textures\\Snake\\Clone.png");
}

void SnakeGame_Update(PGAME _pSnake)
{ 
    if (_pSnake->gameData == NULL)
    {
        SnakeGame_Create(_pSnake);
    }

    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        SnakeGame_Destroy(_pSnake);
    }
}

void SnakeGame_TimedUpdate(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;

    Snake_Move(pSnakeData->pSnake->pHead, pSnakeData->pSnake->speed, pSnakeData->pSnake->step);
    pSnakeData->pSnake->step = (pSnakeData->pSnake->step >= PART_SIZE)? 0 : pSnakeData->pSnake->step + 1;
    Snake_Draw(pSnakeData->pSnake->pHead, pSnakeData->pSnake);
}

void SnakeGame_Destroy(PGAME _pSnake)
{
    PSNAKE_DATA pSnakeData = (PSNAKE_DATA)_pSnake->gameData;
    Snake_Destroy_AllParts(pSnakeData->pSnake->pHead);
    al_destroy_bitmap(pSnakeData->pSnake->pClone);
    free(pSnakeData->pSnake);
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
        (*_ppSnakePart)->direction.x = 1;
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
    al_draw_bitmap(_pSnake->pClone, _pSnakePart->position.x, _pSnakePart->position.y, 0);

    if (_pSnakePart->previous)
    {
        Snake_Draw(_pSnakePart->previous, _pSnake);
    }
}

void Snake_Move(PSNAKE_PART _pSnakePart, int _speed, int _step)
{
    if (!_pSnakePart)
    {
        return;
    }
    
    if (_step * _speed >= PART_SIZE)
    {
        if (_pSnakePart->previous)
        {
            Snake_Move(_pSnakePart->previous, _speed, _step);
            _pSnakePart->previous->direction = _pSnakePart->direction;
        }
    }
    else
    {
        _pSnakePart->position.x += _speed * _pSnakePart->direction.x;
        _pSnakePart->position.y += _speed * _pSnakePart->direction.y;
    }
}
