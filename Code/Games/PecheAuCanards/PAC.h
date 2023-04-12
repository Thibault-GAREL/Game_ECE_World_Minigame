#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"

typedef struct _GAMEDATA
{
    ALLEGRO_BITMAP* textures[15];
    ALLEGRO_FONT* police;

}GameData;

void PAC_Create(PGAME _pExemple);
void PAC_Update(PGAME _pExemple);
void PAC_TimedUpdate(PGAME _pExemple);
void PAC_Destroy(PGAME _pExemple);