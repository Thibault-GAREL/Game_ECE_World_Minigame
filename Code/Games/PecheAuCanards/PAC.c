#include "PAC.h"

char *KeyEquivalent[21] = {
        "",
        "A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N",
        "O",
        "P",
        "Q",
        "R",
        "S",
        "T"
};

void PAC_Reinit(PGAME _pPAC){
    pPacGameData gameData = _pPAC->gameData;

    for (int i = 0; i < 12; ++i) {
        gameData->Fishingstate[i] = 0;
    }

    PAC_Coordinates_create(_pPAC);
}

void PAC_Create(PGAME _pPAC)
{
    pPacGameData gameData = malloc(sizeof (PacGameData));

    _pPAC->gameData = gameData;

    gameData->background = al_load_bitmap("..\\Textures/PAC/Background.png");
    gameData->End = al_load_bitmap("..\\Textures/PAC/PAC End (Grand).png");
    gameData->DuckTextures[0] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    gameData->DuckTextures[1] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2 (Personnalisé).png");
    gameData->DuckTextures[2] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");
    gameData->DuckTextures[3] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2 (Personnalisé).png");
    gameData->DuckTextures[4] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    gameData->DuckTextures[5] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");
    gameData->DuckTextures[6] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2 (Personnalisé).png");
    gameData->DuckTextures[7] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    gameData->DuckTextures[8] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    gameData->DuckTextures[9] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    gameData->DuckTextures[10] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");
    gameData->DuckTextures[11] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");

    gameData->font = al_load_ttf_font("..\\Textures/Fonts/StarWars Font.TTF", 30, 0);
    gameData->fontColor = al_map_rgb(255, 0, 0);
    gameData->timer = 0;
    gameData->PlayerID = 1;

    gameData->KeyPress[0] = ALLEGRO_KEY_A;
    gameData->KeyPress[1] = ALLEGRO_KEY_B;
    gameData->KeyPress[2] = ALLEGRO_KEY_C;
    gameData->KeyPress[3] = ALLEGRO_KEY_D;
    gameData->KeyPress[4] = ALLEGRO_KEY_E;
    gameData->KeyPress[5] = ALLEGRO_KEY_F;
    gameData->KeyPress[6] = ALLEGRO_KEY_G;
    gameData->KeyPress[7] = ALLEGRO_KEY_H;
    gameData->KeyPress[8] = ALLEGRO_KEY_I;
    gameData->KeyPress[9] = ALLEGRO_KEY_J;
    gameData->KeyPress[10] = ALLEGRO_KEY_K;
    gameData->KeyPress[11] = ALLEGRO_KEY_L;
    gameData->KeyPress[12] = ALLEGRO_KEY_M;
    gameData->KeyPress[13] = ALLEGRO_KEY_N;
    gameData->KeyPress[14] = ALLEGRO_KEY_O;
    gameData->KeyPress[15] = ALLEGRO_KEY_P;
    gameData->KeyPress[16] = ALLEGRO_KEY_Q;
    gameData->KeyPress[17] = ALLEGRO_KEY_R;
    gameData->KeyPress[18] = ALLEGRO_KEY_S;
    gameData->KeyPress[19] = ALLEGRO_KEY_T;

    for (int i = 0; i < 12; ++i) {
        gameData->Fishingstate[i] = 0;
        gameData->DuckInfos[i] = malloc(sizeof (DuckInfos));
        gameData->DuckInfos[i]->KEYCodeDuck = gameData->KeyPress[rand() % 19];
    }

    gameData->CurrentDuckFished =  -1;
    gameData->score1 = 0;
    gameData->score2 = 0;

    gameData->Player1_Timer = 0;
    gameData->Player2_Timer = 0;

    PAC_Coordinates_create(_pPAC);

    for (int i = 0; i < 12; ++i) {
        gameData->DuckInfos[i]->Points = (gameData->DuckInfos[i]->vx) * (gameData->DuckInfos[i]->vy);
        printf ("Les points valent %d \n", gameData->DuckInfos[i]->Points);
    }
}

void PAC_Update(PGAME _pPAC)
{


    if (_pPAC->gameData == NULL)
    {
        PAC_Create(_pPAC);
    }

    pPacGameData gameData = _pPAC->gameData;

    if (_pPAC->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        gameData->mouse.x = _pPAC->pEvent->mouse.x*1;
        gameData->mouse.y = _pPAC->pEvent->mouse.y*1;
    }
    if ( _pPAC->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        gameData->click=1;
        printf("click \n");
        printf("%d \n", gameData->click);
    }
    if (_pPAC->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        gameData->click=0;
    }
    if (Get_Touch( _pPAC->pEvent, ALLEGRO_KEY_W,0,0,1,0)){
        PAC_Destroy(_pPAC);
    }

    if (gameData->CurrentDuckFished >= 0) {
        if (gameData->Fishingstate[gameData->CurrentDuckFished] == 1) {
            Was_Key_Pressed(_pPAC, gameData->CurrentDuckFished);
        }
    }
}

void PAC_Coordinates_create(PGAME _pPAC){

    srand(time(NULL));

    pPacGameData gamedata = _pPAC->gameData;

    for (int i = 0; i < 12; i++)
    {
        gamedata->DuckInfos[i]->vx = rand() % 3+1;
        gamedata->DuckInfos[i]->vy = rand() % 3+1;
    }

    for (int i = 0; i < 12; ++i) {
        gamedata->DuckInfos[i]->x = rand() % 1700 +100;
        gamedata->DuckInfos[i]->y = rand() % 900 + 100;
    }
}

void Check_Duck_Collisions(PGAME _pPAC){

    pPacGameData gamedata = _pPAC->gameData;

    for (int i = 0; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x,gamedata->DuckInfos[i]->y}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                if(gamedata->Fishingstate[j] != 2 && gamedata->Fishingstate[i] != 2) {
                    gamedata->DuckInfos[i]->vx *= -1;
                    gamedata->DuckInfos[i]->vy *= -1;
                    gamedata->DuckInfos[i]->x += (gamedata->DuckInfos[i]->vx) * 2;
                    gamedata->DuckInfos[i]->y += (gamedata->DuckInfos[i]->vy) * 2;
                    gamedata->DuckInfos[j]->vx *= -1;
                    gamedata->DuckInfos[j]->vy *= -1;
                    gamedata->DuckInfos[j]->x += (gamedata->DuckInfos[j]->vx) * 2;
                    gamedata->DuckInfos[j]->y += (gamedata->DuckInfos[j]->vy) * 2;
                }
            }
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x + al_get_bitmap_width(gamedata->DuckTextures[i]),gamedata->DuckInfos[i]->y}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                if(gamedata->Fishingstate[j] != 2 && gamedata->Fishingstate[i] != 2) {
                    gamedata->DuckInfos[i]->vx *= -1;
                    //gamedata->DuckInfos[i]->vy*=-1;
                    gamedata->DuckInfos[i]->x += (gamedata->DuckInfos[i]->vx) * 2;
                    gamedata->DuckInfos[i]->y += (gamedata->DuckInfos[i]->vy) * 2;
                    gamedata->DuckInfos[j]->vx *= -1;
                    //gamedata->DuckInfos[j]->vy*=-1;
                    gamedata->DuckInfos[j]->x += (gamedata->DuckInfos[j]->vx) * 2;
                    gamedata->DuckInfos[j]->y += (gamedata->DuckInfos[j]->vy) * 2;
                }
            }
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x,gamedata->DuckInfos[i]->y+ al_get_bitmap_height(gamedata->DuckTextures[i])}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                if(gamedata->Fishingstate[j] != 2 && gamedata->Fishingstate[i] != 2) {
                    //gamedata->DuckInfos[i]->vx*=-1;
                    gamedata->DuckInfos[i]->vy *= -1;
                    gamedata->DuckInfos[i]->x += (gamedata->DuckInfos[i]->vx) * 2;
                    gamedata->DuckInfos[i]->y += (gamedata->DuckInfos[i]->vy) * 2;
                    //gamedata->DuckInfos[j]->vx*=-1;
                    gamedata->DuckInfos[j]->vy *= -1;
                    gamedata->DuckInfos[j]->x += (gamedata->DuckInfos[j]->vx) * 2;
                    gamedata->DuckInfos[j]->y += (gamedata->DuckInfos[j]->vy) * 2;
                }
            }
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x + al_get_bitmap_width(gamedata->DuckTextures[i]),gamedata->DuckInfos[i]->y+ al_get_bitmap_height(gamedata->DuckTextures[i])}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])})) {
                if (gamedata->Fishingstate[j] != 2 && gamedata->Fishingstate[i] != 2) {
                    gamedata->DuckInfos[i]->vx *= -1;
                    gamedata->DuckInfos[i]->vy *= -1;
                    gamedata->DuckInfos[i]->x += (gamedata->DuckInfos[i]->vx) * 2;
                    gamedata->DuckInfos[i]->y += (gamedata->DuckInfos[i]->vy) * 2;
                    gamedata->DuckInfos[j]->vx *= -1;
                    gamedata->DuckInfos[j]->vy *= -1;
                    gamedata->DuckInfos[j]->x += (gamedata->DuckInfos[j]->vx) * 2;
                    gamedata->DuckInfos[j]->y += (gamedata->DuckInfos[j]->vy) * 2;
                }
            }
        }
    }


    for (int i = 0; i < 11; i++){
        if(gamedata->DuckInfos[i]->y <= 0 || gamedata->DuckInfos[i]->y >= 930){

            gamedata->DuckInfos[i]->vy*=-1;
            gamedata->DuckInfos[i]->y +=gamedata->DuckInfos[i]->vy;
        }
        if(gamedata->DuckInfos[i]->x <= 0 || gamedata->DuckInfos[i]->x >= 1780){
            gamedata->DuckInfos[i]->vx*=-1;
            gamedata->DuckInfos[i]->x +=gamedata->DuckInfos[i]->vx;
        }
        else{
            gamedata->DuckInfos[i]->x += gamedata->DuckInfos[i]->vx;
            gamedata->DuckInfos[i]->y += gamedata->DuckInfos[i]->vy;

            gamedata->DuckInfos[i+1]->x += gamedata->DuckInfos[i+1]->vx;
            gamedata->DuckInfos[i+1]->y += gamedata->DuckInfos[i+1]->vy;
        }
    }
}


void Was_Key_Pressed(PGAME _pPAC, int DuckID){
    pPacGameData gameData = _pPAC->gameData;
    printf ("%d \n", gameData->DuckInfos[DuckID]->KEYCodeDuck);
    if (gameData->PlayerID == 1){
        if(Get_Touch(_pPAC->pEvent, gameData->DuckInfos[DuckID]->KEYCodeDuck, 0, 0, 1, 0)) {
            gameData->Fishingstate[DuckID] = 2;
            gameData->score1 += gameData->DuckInfos[DuckID]->Points;
            sprintf(gameData->Score1, "%d", (int) gameData->score1);
            printf("valeur passée à 2 \n");
        }
    }
    if (gameData->PlayerID == 2){
        if(Get_Touch(_pPAC->pEvent, gameData->DuckInfos[DuckID]->KEYCodeDuck, 0, 0, 1, 0)) {
            gameData->Fishingstate[DuckID] = 2;
            gameData->score2 += gameData->DuckInfos[DuckID]->Points;
            sprintf(gameData->Score2, "%d", (int) gameData->score2);
            printf("valeur passée à 2 \n");
        }
    }
}


void Check_Click_on_Duck(PGAME _pPAC){
    pPacGameData gameData = _pPAC->gameData;
    if (gameData->click == 1){
        for (int i = 0; i < 12; ++i) {
            if (Point_In_Rectangle((Vector2D){gameData->mouse.x, gameData->mouse.y}, (Vector2D){gameData->DuckInfos[i]->x ,gameData->DuckInfos[i]->y }, (Vector2D){gameData->DuckInfos[i]->x + al_get_bitmap_width(gameData->DuckTextures[i]),gameData->DuckInfos[i]->y+al_get_bitmap_height(gameData->DuckTextures[i])})){
                gameData->Fishingstate[i] = 1;
                gameData->CurrentDuckFished = i;
            }
        }
    }
}

void PAC_TimedUpdate(PGAME _pPAC)
{
    pPacGameData gameData = _pPAC->gameData;

    //ALLEGRO_DISPLAY * display = al_get_current_display();

    Check_Click_on_Duck(_pPAC);

    if (gameData->Player1_Timer <= 3000){
        al_draw_bitmap(gameData->background, 0,0,0);
        gameData->Player1_Timer++;
        for (int i = 0; i < 12; ++i) {
            if (gameData->Fishingstate[i] != 2){
                al_draw_bitmap(gameData->DuckTextures[i],gameData->DuckInfos[i]->x,gameData->DuckInfos[i]->y,0);
            }
            /*if (gameData->Fishingstate[i] == 1){
                al_draw_text(gameData->font, gameData->fontColor, 960, 540, 1, KeyEquivalent[gameData->DuckInfos[i]->KEYCodeDuck]);
                //printf("%c \n", gameData->KeyPress[i]);
            }*/
            if (gameData->timer <= 200 && gameData->Fishingstate[i] == 1){
                gameData->timer ++;
                al_draw_text(gameData->font, gameData->fontColor, 960, 540, 1, KeyEquivalent[gameData->DuckInfos[i]->KEYCodeDuck]);
                //printf("entree dans le timer \n");
            }
            if (gameData->timer >200){
                gameData->timer = 0;
                gameData->Fishingstate[i] = 0;
                //printf("sorti du timer");
            }
            sprintf(gameData->RemainingTime,"%d",(int)(3000 - gameData->Player1_Timer) / 100);
            al_draw_text(gameData->font, gameData->fontColor, 1920, 10, 2, (const char *)(gameData->RemainingTime));
            al_draw_text(gameData->font, gameData->fontColor, 1900, 50, 2, "Player 1");
            al_draw_text(gameData->font, gameData->fontColor, 10, 50, 0, (const char *)(gameData->Score1));
            al_draw_text(gameData->font,gameData->fontColor, 10, 10, 0, "Score");
        }
    }

    if (gameData->Player1_Timer == 3000) {
        PAC_Reinit(_pPAC);
        gameData->Player1_Timer = 3001;
        gameData->PlayerID = 2;
    }
    if (gameData->Player1_Timer >= 3000) {
        if (gameData->Player2_Timer <= 3000) {
            al_draw_bitmap(gameData->background, 0,0,0);
            gameData->Player2_Timer++;
            for (int i = 0; i < 12; ++i) {
                if (gameData->Fishingstate[i] != 2) {
                    al_draw_bitmap(gameData->DuckTextures[i], gameData->DuckInfos[i]->x, gameData->DuckInfos[i]->y, 0);
                }
                /*if (gameData->Fishingstate[i] == 1){
                    al_draw_text(gameData->font, gameData->fontColor, 960, 540, 1, KeyEquivalent[gameData->DuckInfos[i]->KEYCodeDuck]);
                    //printf("%c \n", gameData->KeyPress[i]);
                }*/
                if (gameData->timer <= 200 && gameData->Fishingstate[i] == 1) {
                    gameData->timer++;
                    al_draw_text(gameData->font, gameData->fontColor, 960, 540, 1,
                                 KeyEquivalent[gameData->DuckInfos[i]->KEYCodeDuck]);
                    //printf("entree dans le timer \n");
                }
                if (gameData->timer > 200) {
                    gameData->timer = 0;
                    gameData->Fishingstate[i] = 0;
                    //printf("sorti du timer");
                }
                sprintf(gameData->RemainingTime, "%d", (int) (3000 - gameData->Player2_Timer) / 100);
                al_draw_text(gameData->font, gameData->fontColor, 1920, 10, 2,(const char *) (gameData->RemainingTime));
                al_draw_text(gameData->font, gameData->fontColor, 1900, 50, 2, "Player 2");
                al_draw_text(gameData->font, gameData->fontColor, 10, 50, 0, (const char *) (gameData->Score2));
                al_draw_text(gameData->font,gameData->fontColor, 10, 10, 0, "Score");
            }
        }
    }

    if (gameData->Player2_Timer >= 3000){
        gameData->Player2_Timer++;
        al_draw_bitmap(gameData->End, 0, 0, 0);
        al_draw_text(gameData->font,gameData->fontColor, 900, 500, 1, "Player 1");
        al_draw_text(gameData->font, gameData->fontColor, 1060, 500, 1, (const char *) (gameData->Score1));
        al_draw_text(gameData->font,gameData->fontColor, 900, 600, 1, "Player 2");
        al_draw_text(gameData->font, gameData->fontColor, 1060, 600, 1, (const char *) (gameData->Score2));
    }

    Check_Duck_Collisions(_pPAC);
}

void PAC_Destroy(PGAME _pPAC)
{
    printf("Destruction du jeu...\n");

    pPacGameData pPAC = _pPAC->gameData;

    for (int i = 0; i < 12; ++i) {
        al_destroy_bitmap(pPAC->DuckTextures[i]);
        free(pPAC->DuckInfos[i]);
    }

    free(_pPAC->gameData);
    _pPAC->gameData = NULL;

    printf("Jeu detruit\n");

    *_pPAC->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}