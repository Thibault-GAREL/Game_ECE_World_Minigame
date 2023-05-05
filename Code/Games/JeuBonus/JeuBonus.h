#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\Utils\\Vector.h"

#define CL_PATH ".."
#define PATH CL_PATH


typedef struct _BONUSDATA
{
    Vector2D mouse;
    int click;
    ALLEGRO_BITMAP* image[30];
    float x1;
    float y1;
    float x2;
    float y2;
    float xballon;
    float yballon;
    int sensbonhomme1;
    int sensbonhomme2;
    int deplacementx1;
    int deplacementx2;
    int compteursautJ1;
    int compteursautJ2;
    int compteurfinsautJ1;
    int compteurfinsautJ2;
    int eligibilitesautJ1;
    int eligibilitesautJ2;
    int tirJ1;
    int tirJ2;
    int compteuranimJ1;
    int compteuranimJ2;
    int compteurfinanimJ1;
    int compteurfinanimJ2;
    int a;
    int b;
    int c;
    int d;
}BonusData;


void Bonus_Create(PGAME _pBonus);
void Bonus_Update(PGAME _pBonus);
void gestionbordurebonhommes(PGAME _pBonus);
void affichagebonhommes(PGAME _pBonus);
void Bonus_TimedUpdate(PGAME _pBonus);
void Bonus_Destroy(PGAME _pBonus);




























//
// Created by Antoine on 05/05/2023.
//

#ifndef PROJET_JEUBONUS_H
#define PROJET_JEUBONUS_H

#endif //PROJET_JEUBONUS_H
