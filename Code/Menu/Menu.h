#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _MenuAnimation{
    ALLEGRO_BITMAP *LoadingTextures[120];
    char *LoadingCount;

}Menu_Animation, *pMenu_Animation;