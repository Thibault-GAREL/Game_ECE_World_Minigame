//
// Created by garel on 06/05/2023.
//


#include "GeometryDash.h"

void Geo_Create(PGAME _pGeoDash)
{
    pGD_Gamedata GameData = malloc(sizeof(GD_Gamedata));

    _pGeoDash->gameData = GameData;

    GameData ->GDTextures[0] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\GDa.png");

    GameData->Jump = 0;
    GameData->Velocity = -10;
    GameData->Gravity = 0.5;
    GameData->y = 400;
    GameData->JumpDuration = 0;
}


void Geo_Update(PGAME _pGeoDash){


    if (_pGeoDash->gameData == NULL)
    {
        Geo_Create(_pGeoDash);
    }

    pGD_Gamedata GameData = _pGeoDash->gameData;

    if (Get_Touch(_pGeoDash->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){  // attention au gamemode
        GameData->Jump = 1;
    }
    if (GameData->JumpDuration == 20){
        GameData->Jump = -1;
    }
}

void Geo_TimedUpdate(PGAME _pGeoDash) {

    pGD_Gamedata gameData = _pGeoDash->gameData;

    gameData->vy += gameData->Gravity;

    gameData->y += gameData->vy;

    if (gameData->y >400){
        gameData->y = 400;
        gameData->vy = 0;
        gameData->Jump = 0;
        gameData->JumpDuration = 0;
    }
    if (gameData->vy > 50){
        gameData->vy = 50;
    }

    if (gameData->Jump == 1){
        gameData->JumpDuration++;
        gameData->vy = gameData->Velocity;
    }
    if (gameData->Jump == -1){
        gameData->JumpDuration++;
        gameData->vy = -gameData->Velocity;
    }
    al_draw_bitmap(gameData->GDTextures[0],0, gameData->y,0);
}

void Geo_Destroy(PGAME _pGeoDash) {
    printf("Destruction du jeu...\n");

    free(_pGeoDash->gameData);
    _pGeoDash->gameData = NULL;
    *_pGeoDash->pCurrentGameId = GAME_MAP;
}
