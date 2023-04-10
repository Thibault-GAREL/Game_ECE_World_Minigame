#include "GameExemple.h"

void Exemple_Create(PGAME _pExemple)
{
    GameData* pGameData = malloc(sizeof (GameData));
    pGameData->police[0]= al_load_ttf_font(PATH"\\police.ttf",150,0);
    pGameData->police[1]= al_load_ttf_font(PATH"\\police.ttf",100,0);
    pGameData->image[0]= al_load_bitmap(PATH"\\fondmenu.jpg");
    pGameData->image[1]= al_load_bitmap(PATH"\\sabrelaser.png");
    pGameData->image[2]= al_load_bitmap(PATH"\\boutonplay.png");
    pGameData->image[3]= al_load_bitmap(PATH"\\batiment1.jpg");
    pGameData->image[4]= al_load_bitmap(PATH"\\tete_strom.png");
    pGameData->image[5]= al_load_bitmap(PATH"\\tete_yoda.png");
    pGameData->image[6]= al_load_bitmap(PATH"\\tete_vador.png");
    pGameData->image[7]= al_load_bitmap(PATH"\\armegauche.png");
    pGameData->image[8]= al_load_bitmap(PATH"\\armedroite.png");
    pGameData->image[9]= al_load_bitmap(PATH"\\vaisseau.png");
    pGameData->image[10]= al_load_bitmap(PATH"\\vaisseaumenu.png");
    pGameData->image[11]= al_load_bitmap(PATH"\\vaisseaumenu2.png");
    pGameData->gamemode = 0;
    pGameData->nbballon = 90;
    pGameData->compteurvaisseau=2000;
    pGameData->yvaiseeau = 400;
    pGameData->vaisseaumenu1x = -100;
    pGameData->vaisseaumenu1y = -100;
    pGameData->vaisseaumenu2x = 2000;
    pGameData->vaisseaumenu2y = -100;
    pGameData->vaisseaumenu3x = -100;
    pGameData->vaisseaumenu3y = 900;
    pGameData->vaisseaumenu4x = 2000;
    pGameData->vaisseaumenu4y = 900;
    Ballon PositionBallon[1000]={0};
    pGameData->pballon=PositionBallon;
    _pExemple->gameData = pGameData;
    pGameData->compteurassignation=0;
    pGameData->compteurdroite=0;
    for (int i=0;i<pGameData->nbballon+1;i++){
        if (i%2 == 1){
            pGameData->pballon[i].vx=2;
            pGameData->pballon[i].vy=2;
        }
        else if (i%3 == 1){
            pGameData->pballon[i].vx=3;
            pGameData->pballon[i].vy=3;
        }
        else if (i%5 == 1){
            pGameData->pballon[i].vx=3;
            pGameData->pballon[i].vy=3;
        }
        else {
            pGameData->pballon[i].vx=2;
            pGameData->pballon[i].vy=2;
        }
    }
}

void Exemple_Update(PGAME _pExemple)
{
    if (!_pExemple->gameData)
    {
        Exemple_Create(_pExemple);
    }

    GameData* pGameData = _pExemple->gameData;

    if (_pExemple->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pGameData->mouse.x = _pExemple->pEvent->mouse.x*1.25;   // METTRE UNE ECHELLE APRES
        pGameData->mouse.y = _pExemple->pEvent->mouse.y*1.25;
    }
    if ( _pExemple->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        pGameData->click=1;
    }
    if (_pExemple->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        pGameData->click=0;
    }
}

void assigner_pos_ballon(PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    pGameData->compteurassignation++;
    srand(time(NULL));
    float posx=0;
    float posy=0;
    int randimg=0;
    for (int i=0;i<pGameData->nbballon/3;i++){
        posx=rand()%325+325;
        posy=rand()%340+350;
        if(posx>600 && posx<620 && posy>580){
            posy=rand()%230+350;
        }
        if(posx>620 && posx<670 && posy>500){
            posy=rand()%150+350;
        }
        if(posy>580 && posy<750 && posx>600){
            posx=rand()%275+325;
        }
        if(posy>500 && posy<580 && posx>620){
            posx=rand()%195+325;
        }
        if (posx>550){
            posx-=100;
        }
        if (posy>650){
            posy-=70;
        }
        pGameData->pballon[i].x=posx;
        pGameData->pballon[i].y=posy;
        randimg=rand()%3;
        pGameData->pballon[i].numimg=randimg;

    }
    for (int i=pGameData->nbballon/3;i<2*(pGameData->nbballon)/3;i++){
        posx=rand()%510+720;
        posy=rand()%340+350;
        if ((posx>720 && posx<800) || (posx>1200 && posx<1230)){
            posy=rand()%250+500;
        }
        if (posy>350 && posy<500){
            posx=rand()%400+800;
        }
        if (posy>680){
            posy-=40;
        }
        if (posx>1150){
            posx-=50;
        }
        if (posx<750){
            posx+=50;
        }
        if (posy < 450){
            posy += 80;
        }
        pGameData->pballon[i].x=posx;
        pGameData->pballon[i].y=posy;
        randimg=rand()%3;
        pGameData->pballon[i].numimg=randimg;
    }
    for (int i=2*(pGameData->nbballon)/3;i<pGameData->nbballon+1;i++){
        posx=rand()%360+1300;
        posy=rand()%340+350;
        if (posx>1300 && posx<1350){
            posy=rand()%200+350;
        }
        if (posx>1350 && posx<1400){
            posy=rand()%280+350;
        }
        if (posy>630 && posy<750){
            posx=rand()%260+1400;
        }
        if (posy>500 && posy<630){
            posx=rand()%360+1350;
        }
        if (posx>1600){
            posx-=100;
        }
        if (posy>650){
            posy-=80;
        }
        if (posx<1400){
            posx += 50;
        }
        pGameData->pballon[i].x=posx;
        pGameData->pballon[i].y=posy;
        randimg=rand()%3;
        pGameData->pballon[i].numimg=randimg;
    }
}


void dessinerballon(PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    for (int i=0;i<pGameData->nbballon+1;i++){
        al_draw_bitmap(pGameData->image[4+pGameData->pballon[i].numimg],pGameData->pballon[i].x,pGameData->pballon[i].y,0);
    }
}

void pointsdroite(float x1,float y1,float x2,float y2,int xpoint,int ypoint,PGAME _pExemple,int indice){
    GameData* pGameData = _pExemple->gameData;
    if (indice==1){
        for (int i=x1;i<x2+1;i++){
            pGameData->pointsx1[i]=i;
            pGameData->pointsy1[i]=(((y1-y2)/(x1-x2))*i)+y2-(x2*((y1-y2)/(x1-x2)));
        }
    }
    if (indice==2){
        for (int i=x1;i<x2+1;i++){
            pGameData->pointsx2[i]=i;
            pGameData->pointsy2[i]=((y1-y2)/(x1-x2))*i+y2-x2*((y1-y2)/(x1-x2));
        }
    }
    if (indice==3){
        for (int i=x1;i<x2+1;i++){
            pGameData->pointsx3[i]=i;
            pGameData->pointsy3[i]=((y1-y2)/(x1-x2))*i+y2-x2*((y1-y2)/(x1-x2));
        }
    }
    if (indice==4){
        for (int i=x1;i<x2+1;i++){
            pGameData->pointsx4[i]=i;
            pGameData->pointsy4[i]=((y1-y2)/(x1-x2))*i+y2-x2*((y1-y2)/(x1-x2));
        }
    }
    pGameData->compteurdroite++;
}


void mouvementballon(PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    pGameData->compteurdroite++;
    for (int i=0;i<pGameData->nbballon/3;i++) {
        for (int j = 580; j < 716; j++) {
            if (pGameData->pointsx1[j] >= pGameData->pballon[i].x && pGameData->pointsx1[j] <= pGameData->pballon[i].x+47 && pGameData->pointsy1[j] >= pGameData->pballon[i].y-7  && pGameData->pointsy1[j] <= pGameData->pballon[i].y+55) {
                pGameData->pballon[i].vx *=-1;
                pGameData->pballon[i].vy *=-1;
            }
        }
        if (pGameData->pballon[i].y+3 < 350) {
            pGameData->pballon[i].vy *=-1;
            if (rand()%2==1){
                pGameData->pballon[i].vx *=-1;
            }
        }
        if (pGameData->pballon[i].x+7 <= 325) {
            pGameData->pballon[i].vx *=-1;
        }
        if (pGameData->pballon[i].y+43 >= 750){
            pGameData->pballon[i].vy *=-1;
            if (rand()%2==1){
                pGameData->pballon[i].vx *=-1;
            }
        }
    }

    for (int i=pGameData->nbballon/3;i<2*(pGameData->nbballon)/3;i++){
        for (int j=650;j<801;j++){
            if (pGameData->pointsx2[j] >= pGameData->pballon[i].x && pGameData->pointsx2[j] <= pGameData->pballon[i].x+47 && pGameData->pointsy2[j] >= pGameData->pballon[i].y-7  && pGameData->pointsy2[j] <= pGameData->pballon[i].y+55) {
                pGameData->pballon[i].vx *=-1;
                pGameData->pballon[i].vy *=-1;
            }
        }
        for (int j=1200;j<1341;j++){
            if (pGameData->pointsx3[j] >= pGameData->pballon[i].x && pGameData->pointsx3[j] <= pGameData->pballon[i].x+47 && pGameData->pointsy3[j] >= pGameData->pballon[i].y-7  && pGameData->pointsy3[j] <= pGameData->pballon[i].y+55) {
                pGameData->pballon[i].vx *=-1;
                pGameData->pballon[i].vy *=-1;
            }
        }
        if (pGameData->pballon[i].y+43 >= 750){
            pGameData->pballon[i].vy *=-1;
            if (rand()%2==1){
                pGameData->pballon[i].vx *=-1;
            }
        }
        if (pGameData->pballon[i].y+3 <= 350){
            pGameData->pballon[i].vy *=-1;
            if (rand()%2==1){
                pGameData->pballon[i].vx *=-1;
            }
        }
    }
    for (int i=2*(pGameData->nbballon)/3;i<pGameData->nbballon+1;i++){
        for (int j=1260;j<1401;j++){
            if (pGameData->pointsx4[j] >= pGameData->pballon[i].x && pGameData->pointsx4[j] <= pGameData->pballon[i].x+47 && pGameData->pointsy4[j] >= pGameData->pballon[i].y-7  && pGameData->pointsy4[j] <= pGameData->pballon[i].y+55) {
                pGameData->pballon[i].vx *=-1;
                pGameData->pballon[i].vy *=-1;
            }
        }
        if (pGameData->pballon[i].x+42 >= 1710){
            pGameData->pballon[i].vx *=-1;
            if (rand()%2==1){
                pGameData->pballon[i].vy *=-1;
            }
        }
        if (pGameData->pballon[i].y+43 >= 750){
            pGameData->pballon[i].vy *=-1;
            if (rand()%2==1){
                pGameData->pballon[i].vx *=-1;
            }
        }
        if (pGameData->pballon[i].y+3 <= 350){
            pGameData->pballon[i].vy *=-1;
        }
    }
    for (int i=0;i<pGameData->nbballon+1;i++){
        pGameData->pballon[i].x+=pGameData->pballon[i].vx;
        pGameData->pballon[i].y+=pGameData->pballon[i].vy;
    }


}


void Exemple_TimedUpdate(PGAME _pExemple)
{
    char nomjeu[] = "Tir Au Jeday";
    char nomJ1[] = "Joueur 1";
    char nomJ2[] = "Joueur 2";

    GameData* pGameData = _pExemple->gameData;
    if (pGameData->gamemode==0){
        al_draw_bitmap(pGameData->image[0],0,0,0);
        al_draw_bitmap(pGameData->image[10],pGameData->vaisseaumenu1x,pGameData->vaisseaumenu1y,0);
        al_draw_bitmap(pGameData->image[11],pGameData->vaisseaumenu2x,pGameData->vaisseaumenu2y,0);
        al_draw_bitmap(pGameData->image[10],pGameData->vaisseaumenu3x,pGameData->vaisseaumenu3y,0);
        al_draw_bitmap(pGameData->image[11],pGameData->vaisseaumenu4x,pGameData->vaisseaumenu4y,0);
        al_draw_bitmap(pGameData->image[1],800,400,0);
        al_draw_scaled_bitmap(pGameData->image[2],0,0,288,89,600,750,700,150,0);
        al_draw_text(pGameData->police[0], al_map_rgb(255,228,54),300,100,0,nomjeu);
        al_draw_text(pGameData->police[1], al_map_rgb(18,87,200),200,480,0,nomJ1);
        al_draw_text(pGameData->police[1], al_map_rgb(234,39,48),1100,480,0,nomJ2);
        pGameData->vaisseaumenu1x += 2;
        pGameData->vaisseaumenu1y += 2;
        pGameData->vaisseaumenu2x -= 3;
        pGameData->vaisseaumenu2y += 3;
        pGameData->vaisseaumenu3x += 2;
        pGameData->vaisseaumenu3y -= 2;
        pGameData->vaisseaumenu4x -= 3;
        pGameData->vaisseaumenu4y -= 3;
        if (pGameData->vaisseaumenu2y >=1080){pGameData->vaisseaumenu2y=-100;pGameData->vaisseaumenu2x=2500;}
        if (pGameData->vaisseaumenu1y >= 1080){pGameData->vaisseaumenu1y=-100;pGameData->vaisseaumenu1x=-500;}
        if (pGameData->vaisseaumenu4y < -100){pGameData->vaisseaumenu4y=900;pGameData->vaisseaumenu4x=2000;}
        if (pGameData->vaisseaumenu3y < -100){pGameData->vaisseaumenu3y=900;pGameData->vaisseaumenu3x=-100;}
        if (Point_In_Rectangle(pGameData->mouse, (Vector2D){600,750}, (Vector2D){1300,900}) == 1 && pGameData->click==1)
        {
            pGameData->gamemode=1;
            pGameData->click=0;
        }
    }
    if (pGameData->gamemode==1){
        al_draw_bitmap(pGameData->image[3],0,0,0);
        if (pGameData->compteurvaisseau > 320 && pGameData->compteurvaisseau+80 < 1720){
            if((pGameData->compteurvaisseau > 1280 || pGameData->compteurvaisseau+80 < 1220) && (pGameData->compteurvaisseau > 780 || pGameData->compteurvaisseau+80 < 700)){
                al_draw_bitmap(pGameData->image[9],pGameData->compteurvaisseau,pGameData->yvaiseeau,0);
            }
        }
        if (pGameData->mouse.x < 980){
            al_draw_bitmap(pGameData->image[7],800,750,0);
        }
        else {
            al_draw_bitmap(pGameData->image[8],800,750,0);
        }
        if (pGameData->compteurdroite==0){
            pointsdroite(580,750,715,350,0,0,_pExemple,1);
            pointsdroite(650,750,800,350,0,0,_pExemple,2);
            pointsdroite(1200,350,1340,750,0,0,_pExemple,3);
            pointsdroite(1260,340,1400,750,0,0,_pExemple,4);
        }
        if (pGameData->compteurassignation==0){
            assigner_pos_ballon(_pExemple);
        }
        mouvementballon(_pExemple);
        dessinerballon(_pExemple);
        pGameData->compteurvaisseau-=1;
        if ((pGameData->compteurvaisseau > 700 && pGameData->compteurvaisseau < 780) || (pGameData->compteurvaisseau > 1220 && pGameData->compteurvaisseau < 1280)){
            pGameData->compteurvaisseau-=2;
        }
        if (pGameData->compteurvaisseau <= -500){
            pGameData->compteurvaisseau=2000;
            pGameData->yvaiseeau = 400;
        }





    }
}

void Exemple_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    free(_pExemple->gameData);
    _pExemple->gameData = NULL;

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}

