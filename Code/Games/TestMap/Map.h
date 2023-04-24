#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\vector.h"

#define CL_PATH ".."
#define PATH CL_PATH


typedef struct _IMAGES
{
    float x;
    float y;
}Images;


typedef struct _MAPDATA
{
    Vector2D mouse;
    int click;
    ALLEGRO_BITMAP* image[15];
    Images* pimages;
    float x;
    float y;
    int nbimages;
    int deplacementhori;
    int deplacementverti;
    float speedhori;
    float speedverti;
    float bonhommex;
    float bonhommey;
}MapData;



void Map_Create(PMAP _pMap);
void Map_Update(PMAP _pMap);
void gestionbordure(PMAP _pMap);
void rect(PMAP _pMap,float x,float y,float taillex,float tailley,int i);
void gestioncolision(PMAP _pMap);
void Map_TimedUpdate(PMAP _pMap);
void Map_Destroy(PMAP _pMap);

