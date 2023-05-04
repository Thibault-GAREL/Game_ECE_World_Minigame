#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Vector.h"

#define DISABLE 0
#define ENABLE 1

#define ANIMATION_STATE_STOP -1
#define ANIMATION_STATE_REPLAY 0

typedef struct _ANIMATION
{
    //BASIC SETTINGS: 
    
    VECTOR2D_INT position;
    int bitmapDuration;
    int deltaStep;
    int pBitmapsCount;
    ALLEGRO_BITMAP** pBitmaps;


    //ADVANCED SETTINGS:

    int currentStep;
    
    PVECTOR2D_INT positionTarget;
    char isPositionTargetEnable;

    Vector2D scaleFactor;
    char isScaleFactorEnable;
    
    int startState;
    char isStartStateEnable;

    int* pStartTriggerBOOL;
    char isStartTriggerBOOLEnable;

}ANIMATION, *PANIMATION;

PANIMATION Animation_Create(VECTOR2D_INT _position, int _bitmapDuration, int _deltaStep, int _pBitmapsCount, ALLEGRO_BITMAP** _pBitmaps);
void Animation_Destroy(PANIMATION _pAnimation);

void Animation_Draw(PANIMATION _pAnimation);
void Animation_Update_Step(PANIMATION _pAnimation);

void Animation_Enable_PositionTarget(PANIMATION _pAnimation, PVECTOR2D_INT _positionTarget);
void Animation_Enable_ScaleFactor(PANIMATION _pAnimation, Vector2D _scaleFactor);
void Animation_Enable_StartState(PANIMATION _pAnimation, int _startStepValue);
void Animation_Enable_StartTrigger(PANIMATION _pAnimation, int* _pStartTriggerBOOL);
