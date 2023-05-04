#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\Magical.h"
#include "..\\..\\Utils\\UI.h"

#define CORDE_NB 4

#define NOTE_START_POSITION -10
#define NOTE_OFFSET_X 500
#define NOTE_ECART_X 10
#define NOTE_W 200
#define NOTE_MIN_SIZE 50
#define NOTE_MAX_SIZE 250
#define NOTE_PROBA 400

#define LINE_VALUE 800
#define FLECHE_OFFSET_X NOTE_OFFSET_X + 50

#define START_SPEED 0.8f
#define ACCELERATION 0.001f
#define MAX_SPEED 10

#define ERROR_MAX 4

#define NOTE_PP 10

typedef struct _NOTE
{
    float top;
    float bottom;
    struct _NOTE* pNext;
    float isTouch;
    int isErrored;
}NOTE, *PNOTE;

typedef struct _DP_UI
{
    ALLEGRO_BITMAP* pBackground;
    ALLEGRO_FONT* pFont50;

    ALLEGRO_BITMAP* pFlecheIdle;
    ALLEGRO_BITMAP* pFlecheAppuyee;
    ALLEGRO_BITMAP* pFalse;
}DP_UI, *PDP_UI;

typedef struct _DP_DATA
{
    PNOTE corde[CORDE_NB];
    DP_UI ui;
    int score; 
    int cordeInput[CORDE_NB];
    float speed;
    int error;
    int playerCurrent;
}DP_DATA, *PDP_DATA;

void DarkPiano_Create(PGAME _pExemple);
void DarkPiano_Update(PGAME _pExemple);
void DarkPiano_TimedUpdate(PGAME _pExemple);
void DarkPiano_Destroy(PGAME _pExemple);
void DarkPiano_DrawUI(PGAME _pExemple);

void Note_Add(PNOTE* _ppFirstNote);
void Note_Destroy(PNOTE _pNote);
void Note_Move(PNOTE _pNote, float _delta);
void Note_Draw(PNOTE _pNote, int _x1, int _x2);
int Note_Get_MaxTop(PNOTE _pNote);

int Note_IsTouch(PNOTE* _ppFirstNote, int _isPressed);
void Note_Update(PNOTE* _ppFirstNote, int* _pError);

void GameStateChecker(PGAME _pGame);