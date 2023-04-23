//
// Created by garel on 20/04/2023.
//

#ifndef PROJET_TRAVERSE_CODE_H
#define PROJET_TRAVERSE_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"

#define CL_PATH ".."
#define PATH CL_PATH

typedef struct Maillion {
    int numero;
    //indication des obstacles ici
    struct Maillion* next;
}Maillion;

typedef struct Obstacle
{
    float x;
    float y;
    float vx;
    float vy;
    bool vient_droite;
}Obstacle;


typedef struct GameData {
    ALLEGRO_BITMAP* image [1];
    Maillion* liste;
}GameData;

void ajouterfinLSC (Maillion** p, int numero);
void liberation (Maillion** m);

void TDLR_Create(PGAME _pExemple);
void TDLR_Update(PGAME _pExemple);
void TDLR_TimedUpdate(PGAME _pExemple);
void TDLR_Destroy(PGAME _pExemple);


#endif //PROJET_TRAVERSE_CODE_H
