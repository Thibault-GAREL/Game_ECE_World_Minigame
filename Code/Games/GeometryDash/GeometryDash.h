//
// Created by garel on 06/05/2023.
//

#ifndef PROJET_GEOMETRYDASH_H
#define PROJET_GEOMETRYDASH_H

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"

#define CL_PATH ".."
#define PATH CL_PATH
#define X_player 500


typedef struct GeoData {
    ALLEGRO_BITMAP* image [1];
    int ay_player;
    int vy_player;
    int y_player;

    int sol;
}GeoData;

/*typedef struct GeoData {
    ALLEGRO_BITMAP* GDTextures[10];
    float Gravity;
    int y;
    int vy;

    int Velocity;


    int Jump;
    int JumpDuration;
    int Gamemode;

}GD_Gamedata, *pGD_Gamedata;*/


void Geo_Create(PGAME _pExemple);
void Geo_Update(PGAME _pExemple);
void Geo_TimedUpdate(PGAME _pExemple);
void Geo_Destroy(PGAME _pExemple);

#endif //PROJET_GEOMETRYDASH_H
