//
// Created by garel on 20/04/2023.
//

#ifndef PROJET_TRAVERSE_CODE_H
#define PROJET_TRAVERSE_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\Vector.h"

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
    float x_transi;
    float vx;
    float vx_ajout;
    float x2;
    float x_transi2;
    float vx2;
}Obstacle;


typedef struct GameData {
    ALLEGRO_BITMAP* image [8];
    ALLEGRO_FONT* police[3];
    int Strat [1000];
    int compteur_strat;
    int pixel_avance;
    Obstacle position_obstacle [1000];
    int life;
    int gamemode;
    int score_player1;
    int score_player2;
    int gagnant;
    char* nom_player1;
    char* nom_player2;

    Vector2D mouse_position;
    int click;
}GameData;

//void ajouterfinLSC (Maillion** p, int numero);
//void afficherLSC (Maillion* liste_debut);
//void liberation (Maillion** m);


int inverse (int num, int pixel_avance);
void generation_strat (PGAME _pExemple);
void position_alleatoire (PGAME _pExemple);
void affichage_strat (PGAME _pExemple, int numero);
bool colision (PGAME _pExemple, int numero);

void TDLR_Create(PGAME _pExemple);
void TDLR_Update(PGAME _pExemple);
void TDLR_TimedUpdate(PGAME _pExemple);
void TDLR_Destroy(PGAME _pExemple);


#endif //PROJET_TRAVERSE_CODE_H
