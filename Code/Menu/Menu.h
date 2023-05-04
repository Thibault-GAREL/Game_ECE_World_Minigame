#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
#include "..\\Utils\\Vector.h"

typedef struct _MenuGameData {
    Vector2D mouse;
    int click;
    int GameLaunched;
    int Main_Menu_Select;
    ALLEGRO_BITMAP *Menu_Bitmap[10];
}MenuGameData, *pMenuGameData;

void Menu_Create(PGAME _pMenu);
void Menu_Update(PGAME _pMenu);
void Menu_TimedUpdate(PGAME _pMenu);
void Menu_Destroy(PGAME _pMenu);
