#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "allegroutils.h"
#include "vector.h"

#define CL_PATH ".."
#define PATH CL_PATH

typedef struct _BALLON
{
    float x;
    float y;
    int numimg;
    float vx;
    float vy;
}Ballon;

typedef struct _GAMEDATA
{
    ALLEGRO_BITMAP* image[20];
    ALLEGRO_FONT* police[2];
    int gamemode;
    Vector2D mouse;
    int click;
    int nbballon;
    Ballon* pballon;
    int compteurassignation;
    int compteurdroite;
    int compteurvaisseau;
    int yvaiseeau;
    int vaisseaumenu1x;
    int vaisseaumenu2x;
    int vaisseaumenu2y;
    int vaisseaumenu1y;
    int vaisseaumenu3x;
    int vaisseaumenu4x;
    int vaisseaumenu4y;
    int vaisseaumenu3y;
    float pointsx1[1000];
    float pointsy1[1000];
    float pointsx2[2000];
    float pointsy2[2000];
    float pointsx3[2000];
    float pointsy3[2000];
    float pointsx4[2000];
    float pointsy4[2000];
}GameData;



void Exemple_Create(PGAME _pExemple);
void Exemple_Update(PGAME _pExemple);
void assigner_pos_ballon(PGAME _pExemple);
void dessinerballon(PGAME _pExemple);
void pointsdroite(float x1,float y1,float x2,float y2,int xpoint,int ypoint,PGAME _pExemple,int indice);
void Exemple_TimedUpdate(PGAME _pExemple);
void Exemple_Destroy(PGAME _pExemple);

