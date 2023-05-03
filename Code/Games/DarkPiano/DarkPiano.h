#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\Magical.h"
#include "..\\..\\Utils\\UI.h"

#define CORDE_NB 4

#define NOTE_START_POSITION -10
#define NOTE_MIN_SIZE 20
#define NOTE_MAX_SIZE 250
#define NOTE_PROBA 100

#define LINE_VALUE 800

#define DELTA 0.8f

typedef struct _NOTE
{
    float top;
    float bottom;
    struct _NOTE* pNext;
}NOTE, *PNOTE;

typedef struct _DP_UI
{
    ALLEGRO_BITMAP* pBackground;
    ALLEGRO_FONT* pFont50;
}DP_UI, *PDP_UI;

typedef struct _DP_DATA
{
    PNOTE corde[CORDE_NB];
    DP_UI ui;
    int score; 
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

int Note_UpdateANDIsTouch(PNOTE* _ppFirstNote, int _isPressed);
