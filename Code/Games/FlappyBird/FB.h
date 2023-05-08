#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"


#define Distance_btw_2_pipes 1500

typedef struct _FBGamedata{
    int Gamemode;
    double BirdSpeed;
    
    char Jump;
    int JumpTimer;
    int Y_Position;
    double vY_Fall;

    int PipeRow1_X;
    int PipeRow2_X;
    int PipeRow3_X;
    int PipeRow4_X;
    int PipeRow5_X;
    int PipeRow6_X;


    int Top_pipe_Y_1;
    int Top_pipe_Y_2;
    int Top_pipe_Y_3;
    int Top_pipe_Y_4;
    int Top_pipe_Y_5;
    int Top_pipe_Y_6;
    
    ALLEGRO_BITMAP *Bird;
    ALLEGRO_BITMAP *Background;
    ALLEGRO_BITMAP *LightSaber;
    ALLEGRO_BITMAP *LightSaberRotated;

}FB_gamedata, *pFB_gamedata;

void FB_Create(PGAME _pFB);
void FB_Update(PGAME _pFB);
void FB_TimedUpdate(PGAME _pFB);
void FB_Destroy(PGAME _pFB);
void Generate_Pipes(PGAME _pFB);