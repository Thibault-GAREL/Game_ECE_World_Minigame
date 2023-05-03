#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\\Game.h"
#include "..\\Utils\\allegroutils.h"
#include "..\Utils\\Vector.h"

typedef struct _MenuAnimation{
    ALLEGRO_BITMAP *LoadingTextures[140];
    char LoadingCount[140];

}Menu_Animation, *pMenu_Animation;

Menu_Animation* Init_Game_Loading();