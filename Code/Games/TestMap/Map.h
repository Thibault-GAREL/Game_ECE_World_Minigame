#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\Utils\\Vector.h"

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
    ALLEGRO_BITMAP* image[45];
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
    int a;
    int b;
    int c;
    int d;
    int i;
    int jeusuivant;
    int sensbonhommex;
    int sensbonhommey;
    int compteurfumme;
    int fumeea;
    int fumeeb;
    int fumeec;
    int fumeed;
    int vetofumee;
    int compteurville;
    int zone1;
    int zone2;
    int zone3;
    int zone4;
    int compteurvaisseaubon;
    int imagebondroite;
    int imagebongauche;
    int compteurcooldownvaiss;
    int compteurcooldownvaiss2;
    int imageactuelle;
    int compteurcolision;
    int vetoF;
    int vetoV;
    int vetoB;
    int vetoC;
    int compteurcolision2;
}MapData;



void Map_Create(PMAP _pMap);
void Map_Update(PMAP _pMap);
void gestionbordure(PMAP _pMap);
void affichageminimap(PMAP _pMap);
void affichagebonhomme(PMAP _pMap);
void affichageville(PMAP _pMap);
void gestionvaiseeau(PMAP _pMap);
void gestioncolision(PMAP _pMap,float x,float y,int indice);
void Map_TimedUpdate(PMAP _pMap);
void Map_Destroy(PMAP _pMap);