#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"


#define MAX_POS_X 1920
#define MAX_POS_Y 1080
#define DuckThreshold 50           //defines the minimum distance between two ducks
#define DuckCount 12

typedef struct _DuckInfos{
    int x, y;
    int vx, vy;
    bool IsDuckFished;
}DuckInfos, *pDuckInfos;

typedef struct _GAMEDATA
{
    ALLEGRO_BITMAP* textures[15];
    ALLEGRO_FONT* police;
    DuckInfos *DuckInfos[DuckCount];
}GameData, *pGameData;

void PAC_Create(PGAME _pExemple);
void PAC_Update(PGAME _pExemple);
void PAC_TimedUpdate(PGAME _pExemple);
void PAC_Destroy(PGAME _pExemple);
pGameData InitDuck();
pGameData PAC_Coordinates_create(pGameData gamedata);
