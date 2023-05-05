#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\Utils\\Vector.h"



typedef struct _BALLON
{
    float x;
    float y;
    int numimg;
    float vx;
    float vy;
}Ballon;

typedef struct _TABGAMEDATA
{
    ALLEGRO_BITMAP* image[70];
    ALLEGRO_BITMAP* danse[60];
    ALLEGRO_FONT* police[3];
    ALLEGRO_SAMPLE* sons[1];
    ALLEGRO_SAMPLE_INSTANCE* soninstance;
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
    int ballondetruit;
    char score[100];
    int timeur;
    char timmeur[100];
    int tempsrestant;
    int tourfait;
    int pointJ1;
    int pointJ2;
    int ticketJ1;
    int ticketJ2;
    char scoreJ1[100];
    char scoreJ2[100];
    int meilleurscore1;
    int meilleurscore2;
    int meilleurscore3;
    int compteursauvegarde;
    char score1[100];
    char score2[100];
    char score3[100];
    int compteurimage;
    float animation_x;
    float animation_y;
    char chiffre[100];
    int compteurmusique;
    int compteurmusique2;
    int compteurtickets;
}TABGameData;



void TAB_Create(PGAME _pExemple);
void TAB_Update(PGAME _pExemple);
void assigner_pos_ballon(PGAME _pExemple);
void dessinerballon(PGAME _pExemple);
void pointsdroite(float x1,float y1,float x2,float y2,int xpoint,int ypoint,PGAME _pExemple,int indice);
void danse(PGAME _pExemple);
void TAB_TimedUpdate(PGAME _pExemple);
void TAB_Destroy(PGAME _pExemple);
