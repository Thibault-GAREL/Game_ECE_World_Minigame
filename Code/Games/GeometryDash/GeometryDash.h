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
#define y_debut_player 900
#define triangle 1
#define rectangle 2


typedef struct GeoData {
    ALLEGRO_BITMAP* image [10];
    float ay_player;
    float vy_player;
    float y_player;

    int x;
    float vx;
    int onGround;

    int sol;
    int avancement_fond;
    int x_fond;

    int obstacles [1000];
    int id_obstacles [1000];

    int timer;
    int click;
    Vector2D mouse_position;

    int gamemode;

    int x_triangle1;

    int x_rectangle1;
}GeoData;


void Geo_Create(PGAME _pExemple);
void Geo_Update(PGAME _pExemple);
void Geo_TimedUpdate(PGAME _pExemple);
void Geo_Destroy(PGAME _pExemple);

#endif //PROJET_GEOMETRYDASH_H
