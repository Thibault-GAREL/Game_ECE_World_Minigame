#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
#include "..\\Utils\\Vector.h"

typedef struct _MenuBitmap{
    int x;
    int y;
    int vx;
    int vy;
    int MouseIsOver;
}MenuBitmapInfo, *pMenuBitmapInfo;

typedef struct _MenuGameData {
    Vector2D mouse;
    int click;
    int GameLaunched;
    int Main_Menu_Select;

    char GetName1[256];
    int CurrentCharPos;
    ALLEGRO_FONT *GetNameFont;
    int GetNameState;
    ALLEGRO_KEYBOARD_STATE keyboard_state;

    pMenuBitmapInfo MB_Infos[10];
    ALLEGRO_BITMAP *Menu_Bitmap[10];
}MenuGameData, *pMenuGameData;

void Menu_Create(PGAME _pMenu);
void Menu_Update(PGAME _pMenu);
void Menu_TimedUpdate(PGAME _pMenu);
void Menu_Destroy(PGAME _pMenu);
void Get_Player_Name(PGAME _pMenu);