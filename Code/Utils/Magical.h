#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>



typedef struct _VECTOR2D_FLOAT
{
    float x;
    float y;
}VECTOR2D_FLOAT, *PVECTOR2D_FLOAT;

typedef struct _VECTOR2D_INT
{
    int x;
    int y;
}VECTOR2D_INT, *PVECTOR2D_INT;

typedef struct _ANIMATION
{
    //BASIC SETTINGS: 
    
    VECTOR2D_INT position;
    int stepInterval;
    int deltaStep;
    int pBitmapsCount;
    ALLEGRO_BITMAP** pBitmaps;


    //ADVANCED SETTINGS:

    int stepCurrent;
    
    PVECTOR2D_INT positionTarget;
    char isPositionTargetEnabled;

    VECTOR2D_FLOAT scaleFactor;
    char isScaleFactorEnabled;

}ANIMATION, *PANIMATION;

PANIMATION Animation_Create(VECTOR2D_INT _position, int _stepInterval, int _deltaStep, int _pBitmapsCount, ALLEGRO_BITMAP** _pBitmaps);
void Animation_Destroy(PANIMATION _pAnimation);

void Animation_Draw(PANIMATION _pAnimation);
void Animation_Update_Step(PANIMATION _pAnimation);

void Animation_Enable_PositionTarget(PANIMATION _pAnimation, PVECTOR2D_INT _positionTarget);
void Animation_Enable_ScaleFactor(PANIMATION _pAnimation, VECTOR2D_FLOAT _scaleFactor);
