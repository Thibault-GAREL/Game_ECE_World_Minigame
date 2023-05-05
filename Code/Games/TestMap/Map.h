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
    ALLEGRO_BITMAP* image[55];
    ALLEGRO_BITMAP* transi[122];
    ALLEGRO_FONT* police[2];
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
    char ticketJ1[sizeof (int)];
    char ticketJ2[sizeof (int)];
    int compteurfin;
    int compteurchoixjeu;
    char animation[100];
    int compteuranim1;
    int compteuranim2;
}MapData;



void Map_Create(PGAME _pMap);
void Map_Update(PGAME _pMap);
void gestionbordure(PGAME _pMap);
void affichageminimap(PGAME _pMap);
void affichagebonhomme(PGAME _pMap);
void affichageville(PGAME _pMap);
void gestionvaiseeau(PGAME _pMap);
void gestioncolision(PGAME _pMap,float x,float y,int indice);
void animation(PGAME _pMap);
void Map_TimedUpdate(PGAME _pMap);
void Map_Destroy(PGAME _pMap);