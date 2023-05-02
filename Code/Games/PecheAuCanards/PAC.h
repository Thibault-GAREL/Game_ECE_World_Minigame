#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\Utils\\Vector.h"
#include "math.h"

#define DuckCount 12

typedef struct _DuckInfos{
    float x, y;
    float vx, vy;
    char KEYCodeDuck;
    int Points;
    int Picked;
    ALLEGRO_COLOR DuckColor;
}DuckInfos, *pDuckInfos;

typedef struct _GAMEDATA
{
    ALLEGRO_FONT* font;
    ALLEGRO_COLOR fontColor;
    DuckInfos *DuckInfos[DuckCount];
    ALLEGRO_BITMAP *Menu;
    ALLEGRO_BITMAP *DuckTextures[DuckCount];
    ALLEGRO_BITMAP *background;
    ALLEGRO_BITMAP *End;
    Vector2D mouse;
    int click;
    int Fishingstate[DuckCount];
    int score1;
    char Score1[100];
    int score2;
    char Score2[100];
    char KeyPress[21];
    int CurrentDuckFished;
    int timer;
    int PlayerID;
    int Player1_Timer;
    int Player2_Timer;
    char RemainingTime[100];
    int GameLaunched;
    int IntervalTime;
    ALLEGRO_COLOR PickedColor;
    ALLEGRO_COLOR NormalColor;
}PacGameData, *pPacGameData;

void PAC_Create(PGAME _pPAC);
void PAC_Update(PGAME _pPAC);
void PAC_Reinit(PGAME _pPAC);
void PAC_TimedUpdate(PGAME _pPAC);
void PAC_Destroy(PGAME _pPAC);
void PAC_Coordinates_create(PGAME _pPAC);
void Check_Duck_Collisions(PGAME _pPAC);
void Check_Click_on_Duck(PGAME _pPAC);
void Was_Key_Pressed(PGAME _pPAC, int DuckID);