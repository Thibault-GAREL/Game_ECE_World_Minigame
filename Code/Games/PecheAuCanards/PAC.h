#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"

#define HighBoundaryX 1920
#define HighBoundary 1080
#define LowBoundaryX 0
#define LowBoundaryY 0

typedef struct _DuckInfos{
    float x, y;
    bool IsDuckFished;
}DuckInfos, *PDuckInfos;

typedef struct _GAMEDATA
{
    ALLEGRO_BITMAP* textures[15];
    ALLEGRO_FONT* police;
    DuckInfos *pDuckInfo1;
    DuckInfos *pDuckInfo2;
    DuckInfos *pDuckInfo3;
    DuckInfos *pDuckInfo4;
    DuckInfos *pDuckInfo5;
    DuckInfos *pDuckInfo6;
    DuckInfos *pDuckInfo7;
    DuckInfos *pDuckInfo8;
    DuckInfos *pDuckInfo9;
    DuckInfos *pDuckInfo10;
    DuckInfos *pDuckInfo11;
    DuckInfos *pDuckInfo12;
}GameData, *pGameData;

void PAC_Create(PGAME _pExemple);
void PAC_Update(PGAME _pExemple);
void PAC_TimedUpdate(PGAME _pExemple);
void PAC_Destroy(PGAME _pExemple);

pGameData InitDuck();