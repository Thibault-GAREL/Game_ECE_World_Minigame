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
    ALLEGRO_BITMAP* image[38];
    ALLEGRO_FONT* police[4];
    ALLEGRO_BITMAP* goal[30];
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
    int colision1;
    int colision2;
    int colision3;
    int colision4;
    int colision5;
    int colision6;
    int compteurchoc;
    int compteurfinchoc;
    int compteurchoc2;
    int compteurfinchoc2;
    int compteurchoc3;
    int compteurfinchoc3;
    int compteurchoc4;
    int compteurfinchoc4;
    float gravity;
    float friction;
    float speedballon;
    int compteurchutteballon;
    int compteurfinvit;
    float speedballonx;
    int timer;
    int compteurtimer;
    char tempsrestant[100];
    int butJ1;
    int butJ2;
    char scoreJ1[100];
    char scoreJ2[100];
    int compteurdixJ1;
    int compteurdixJ2;
    int compteurbut;
    int compteurbut2;
    char animgoal[100];
    int compteuranimation;
    int compteuranimation2;
    int vetodeplacement;
    int compteurdecompte;
    int compteurunbut;
    int gamemode;
    char scorefinalJ1[100];
    char scorefinalJ2[100];
    int buttotalJ1;
    int buttotalJ2;
    int compteuratribution;
}BonusData;


void Bonus_Create(PGAME _pBonus);
void Bonus_Update(PGAME _pBonus);
void gestionbordurebonhommes(PGAME _pBonus);
void affichagebonhommes(PGAME _pBonus);
void gestioncolisions(PGAME _pBonus);
void gestionballe(PGAME _pBonus);
void animationbut(PGAME _pBonus);
void affichagescore(PGAME _pBonus);
void menu(PGAME _pBonus);
void Bonus_TimedUpdate(PGAME _pBonus);
void Bonus_Destroy(PGAME _pBonus);




























//
// Created by Antoine on 05/05/2023.
//

#ifndef PROJET_JEUBONUS_H
#define PROJET_JEUBONUS_H

#endif //PROJET_JEUBONUS_H
