//
// Created by garel on 06/05/2023.
//

#ifndef PROJET_GEOMETRYDASH_H
#define PROJET_GEOMETRYDASH_H

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\Vector.h"

#define CL_PATH ".."
#define PATH CL_PATH
#define X_player 500
#define y_debut_player 800


typedef struct GeoData {
    ALLEGRO_BITMAP* image [10];
    int ay_player;
    int vy_player;
    int y_player;

    int sol;
    int avancement_fond;
    int x_fond;
    int timer;
    int click;
    Vector2D mouse_position;

    int gamemode;
}GeoData;

/*typedef struct GeoData {
    ALLEGRO_BITMAP* GDTextures[10];
    float Gravity;
    int y;
    int vy;
    int Velocity;
    int Jump;
    int JumpDuration;

    int GroundLevel;
    int Gamemode;

}GD_Gamedata, *pGD_Gamedata;*/


void Geo_Create(PGAME _pExemple);
void Geo_Update(PGAME _pExemple);
void Geo_TimedUpdate(PGAME _pExemple);
void Geo_Destroy(PGAME _pExemple);

#endif //PROJET_GEOMETRYDASH_H
