#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
#include "..\\Utils\\Vector.h"
#include "..\\Utils\\allegroutils.h"

typedef struct _MenuBitmap{
    int x;
    int y;
    int vx;
    int vy;
    int MouseIsOver;
    int BitmapClicked;
}MenuBitmapInfo, *pMenuBitmapInfo;

typedef struct _MenuGameData {
    Vector2D mouse;
    int click;
    int GameLaunched;
    int Main_Menu_Select;
    int RefreshRate;

    double MusicGain;
    double SFXGain;

    double ResolutionScale;

    char GetName1[10];
    char GetName2[10];
    int CurrentCharPos;
    ALLEGRO_FONT *GetNameFont;
    int GetNameState;
    ALLEGRO_KEYBOARD_STATE keyboard_state;

    pMenuBitmapInfo MB_Infos[20];
    ALLEGRO_BITMAP *Menu_Bitmap[10];
}MenuGameData, *pMenuGameData;

void Menu_Create(PGAME _pMenu);
void Menu_Update(PGAME _pMenu);
void Menu_TimedUpdate(PGAME _pMenu);
void Menu_Destroy(PGAME _pMenu);