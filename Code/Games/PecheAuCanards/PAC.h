#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\Utils\\Vector.h"

#define DuckCount 12

typedef struct _DuckInfos{
    float x, y;
    float vx, vy;
}DuckInfos, *pDuckInfos;

typedef struct _GAMEDATA
{
    ALLEGRO_BITMAP* textures[15];
    ALLEGRO_FONT* police;
    DuckInfos *DuckInfos[DuckCount];
    ALLEGRO_BITMAP *DuckTextures[DuckCount];
    Vector2D mouse;
    int click;
    int Fishingstate[DuckCount];
}PacGameData, *pPacGameData;

void PAC_Create(PGAME _pExemple);
void PAC_Update(PGAME _pExemple);
void PAC_TimedUpdate(PGAME _pExemple);
void PAC_Destroy(PGAME _pExemple);
void PAC_Coordinates_create(PGAME _pPAC);
void Check_Duck_Colisions(PGAME _pPAC);