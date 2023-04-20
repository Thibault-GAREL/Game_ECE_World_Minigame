#include "GameExemple.h"

void Exemple_Create(PGAME _pExemple)
{
    GameData* pGameData = malloc(sizeof (GameData));
    pGameData->police[0]= al_load_ttf_font(PATH"\\police.ttf",150,0);
    pGameData->police[1]= al_load_ttf_font(PATH"\\police.ttf",100,0);
    pGameData->police[2]= al_load_ttf_font(PATH"\\police.ttf",30,0);
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
    pGameData->image[12]= al_load_bitmap(PATH"\\viseur.png");
    pGameData->image[13]= al_load_bitmap(PATH"\\horloge.png");
    pGameData->image[14]= al_load_bitmap(PATH"\\ballonscore.png");
    pGameData->image[15]= al_load_bitmap(PATH"\\fondtatawin.jpg");
    pGameData->image[16]= al_load_bitmap(PATH"\\scorepartie.png");
    pGameData->image[17]= al_load_bitmap(PATH"\\meilleurscore.png");
    pGameData->image[18]= al_load_bitmap(PATH"\\ticket.png");
    pGameData->image[19]= al_load_bitmap(PATH"\\chiffreun.png");
    pGameData->image[20]= al_load_bitmap(PATH"\\chiffrezero.png");
    pGameData->image[21]= al_load_bitmap(PATH"\\boutonscore.png");
    pGameData->image[22]= al_load_bitmap(PATH"\\fondscore.jpg");
    pGameData->image[23]= al_load_bitmap(PATH"\\croix.png");

    pGameData->image[24]= al_load_bitmap(PATH"\\hit1.png");
    pGameData->image[25]= al_load_bitmap(PATH"\\hit2.png");
    pGameData->image[26]= al_load_bitmap(PATH"\\hit3.png");
    pGameData->image[27]= al_load_bitmap(PATH"\\hit4.png");
    pGameData->image[28]= al_load_bitmap(PATH"\\hit5.png");
    pGameData->image[29]= al_load_bitmap(PATH"\\hit6.png");
    pGameData->image[30]= al_load_bitmap(PATH"\\hit7.png");
    pGameData->image[31]= al_load_bitmap(PATH"\\hit8.png");
    pGameData->image[32]= al_load_bitmap(PATH"\\hit9.png");
    pGameData->image[33]= al_load_bitmap(PATH"\\hit10.png");
    pGameData->image[34]= al_load_bitmap(PATH"\\hit11.png");
    pGameData->image[35]= al_load_bitmap(PATH"\\hit12.png");
    pGameData->image[36]= al_load_bitmap(PATH"\\hit13.png");
    pGameData->image[37]= al_load_bitmap(PATH"\\hit14.png");
    pGameData->image[38]= al_load_bitmap(PATH"\\hit15.png");
    pGameData->image[39]= al_load_bitmap(PATH"\\hit16.png");
    pGameData->image[40]= al_load_bitmap(PATH"\\hit17.png");
    pGameData->image[41]= al_load_bitmap(PATH"\\hit18.png");
    pGameData->image[42]= al_load_bitmap(PATH"\\hit19.png");
    pGameData->image[43]= al_load_bitmap(PATH"\\hit20.png");
    pGameData->image[44]= al_load_bitmap(PATH"\\hit21.png");
    pGameData->image[45]= al_load_bitmap(PATH"\\hit22.png");
    pGameData->image[46]= al_load_bitmap(PATH"\\hit23.png");
    pGameData->image[47]= al_load_bitmap(PATH"\\hit24.png");
    pGameData->image[48]= al_load_bitmap(PATH"\\hit25.png");
    pGameData->image[49]= al_load_bitmap(PATH"\\hit26.png");
    pGameData->image[50]= al_load_bitmap(PATH"\\hit27.png");
    pGameData->image[51]= al_load_bitmap(PATH"\\hit28.png");
    pGameData->image[52]= al_load_bitmap(PATH"\\hit29.png");
    pGameData->image[53]= al_load_bitmap(PATH"\\hit30.png");
    pGameData->image[54]= al_load_bitmap(PATH"\\hit31.png");
    pGameData->image[55]= al_load_bitmap(PATH"\\hit32.png");
    pGameData->image[56]= al_load_bitmap(PATH"\\hit33.png");
    pGameData->image[57]= al_load_bitmap(PATH"\\hit34.png");
    pGameData->image[58]= al_load_bitmap(PATH"\\hit35.png");
    pGameData->image[59]= al_load_bitmap(PATH"\\hit36.png");
    pGameData->image[60]= al_load_bitmap(PATH"\\hit37.png");
    pGameData->image[61]= al_load_bitmap(PATH"\\hit38.png");
    pGameData->image[62]= al_load_bitmap(PATH"\\hit39.png");
    pGameData->image[63]= al_load_bitmap(PATH"\\hit40.png");
    pGameData->image[64]= al_load_bitmap(PATH"\\hit41.png");
    pGameData->image[65]= al_load_bitmap(PATH"\\hit42.png");
    pGameData->image[66]= al_load_bitmap(PATH"\\hit43.png");
    pGameData->image[67]= al_load_bitmap(PATH"\\hit44.png");
    pGameData->image[68]= al_load_bitmap(PATH"\\hit45.png");

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
    pGameData->ballondetruit=0;
    pGameData->timeur = 0;
    pGameData->tempsrestant = 30;
    pGameData->tourfait=0;
    pGameData->ticketJ2=0;
    pGameData->ticketJ1=0;
    pGameData->compteursauvegarde=0;
    pGameData->compteurimage=24;
    pGameData->animation_x=-100;
    pGameData->animation_y=-100;
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
        if (posy>600){
            posy-=100;
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


void reset(PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
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
    pGameData->compteurassignation=0;
    pGameData->compteurdroite=0;
    pGameData->ballondetruit=0;
    pGameData->timeur = 0;
    pGameData->tempsrestant = 30;
}


void traitementmeilleurscore(PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    if (pGameData->pointJ1 >= pGameData->meilleurscore1){
        pGameData->meilleurscore3=pGameData->meilleurscore2;
        pGameData->meilleurscore2=pGameData->meilleurscore1;
        pGameData->meilleurscore1=pGameData->pointJ1;
    }
    if (pGameData->pointJ2 >= pGameData->meilleurscore1){
        pGameData->meilleurscore3=pGameData->meilleurscore2;
        pGameData->meilleurscore2=pGameData->meilleurscore1;
        pGameData->meilleurscore1=pGameData->pointJ2;
    }
    else if (pGameData->pointJ1 >= pGameData->meilleurscore2 && pGameData->pointJ1 <= pGameData->meilleurscore1){
        pGameData->meilleurscore3 = pGameData->meilleurscore2 ;
        pGameData->meilleurscore2 = pGameData->pointJ1;
    }
    else if (pGameData->pointJ2 >= pGameData->meilleurscore2 && pGameData->pointJ2 <= pGameData->meilleurscore1){
        pGameData->meilleurscore3 = pGameData->meilleurscore2 ;
        pGameData->meilleurscore2 = pGameData->pointJ2;
    }
    else if (pGameData->pointJ1 >= pGameData->meilleurscore3 && pGameData->pointJ1 <= pGameData->meilleurscore2){
        pGameData->meilleurscore3=pGameData->pointJ1;
    }
    else if (pGameData->pointJ2 >= pGameData->meilleurscore3 && pGameData->pointJ2 <= pGameData->meilleurscore2){
        pGameData->meilleurscore3=pGameData->pointJ2;
    }
}




void Exemple_TimedUpdate(PGAME _pExemple)
{
    char nomjeu[] = "Tir Au Jeday";
    char nomJ1[] = "Joueur 1";
    char nomJ2[] = "Joueur 2";
    char ecriturescore[] = "Score : ";
    char deuxpoint[] = " : ";
    char tour[] = "turn";

    GameData* pGameData = _pExemple->gameData;
    if (pGameData->gamemode==0){
        ALLEGRO_DISPLAY * ecran=al_get_current_display();
        al_show_mouse_cursor(ecran);
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
        int a=0;
        al_draw_bitmap(pGameData->image[3],0,0,0);
        ALLEGRO_DISPLAY*ecran= al_get_current_display();
        al_hide_mouse_cursor(ecran);
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
        al_draw_bitmap(pGameData->image[12],pGameData->mouse.x,pGameData->mouse.y,0);
        for (int i=0;i<pGameData->nbballon+1;i++){
            if (pGameData->mouse.x+26 >= pGameData->pballon[i].x+5 && pGameData->mouse.x+26 <= pGameData->pballon[i].x+48 && pGameData->mouse.y+24 >= pGameData->pballon[i].y+2 && pGameData->mouse.y+24 <= pGameData->pballon[i].y+47 && pGameData->click == 1){
                pGameData->animation_x=pGameData->pballon[i].x;
                pGameData->animation_y=pGameData->pballon[i].y;
                pGameData->pballon[i].x = -100000;
                pGameData->pballon[i].y = -100000;
                pGameData->click=0;
                pGameData->ballondetruit++;
            }
        }
        pGameData->timeur++;
        if (pGameData->timeur%100==1){
            pGameData->tempsrestant-=1;
        }
        sprintf(pGameData->score,"%d",(int)pGameData->ballondetruit);
        sprintf(pGameData->timmeur,"%d",(int)pGameData->tempsrestant);
        al_draw_text(pGameData->police[1], al_map_rgb(27,52,100),100,800,0,ecriturescore);
        al_draw_text(pGameData->police[1], al_map_rgb(234,231,39),650,800,0,pGameData->score);
        al_draw_bitmap(pGameData->image[13],1300,100,0);
        al_draw_text(pGameData->police[0], al_map_rgb(0,0,0),1450,100,0,deuxpoint);
        al_draw_text(pGameData->police[0], al_map_rgb(255,255,255),1550,100,0,pGameData->timmeur);
        if (pGameData->tempsrestant <= 0 && pGameData->tourfait==0){
            pGameData->gamemode=2;
            pGameData->pointJ1=pGameData->ballondetruit;
        }
        if (pGameData->tempsrestant <= 0 && pGameData->tourfait==1){
            pGameData->gamemode=3;
            pGameData->pointJ2=pGameData->ballondetruit;
        }
        if (pGameData->ballondetruit == 91 && pGameData->tourfait==0){
            pGameData->gamemode=2;
            pGameData->pointJ1=pGameData->ballondetruit;
        }
        if (pGameData->ballondetruit == 91 && pGameData->tourfait==1){
            pGameData->gamemode=2;
            pGameData->pointJ2=pGameData->ballondetruit;
        }
        al_draw_scaled_bitmap(pGameData->image[pGameData->compteurimage],0,0,50,28,pGameData->animation_x-2,pGameData->animation_y+2,100,48,0);
        pGameData->compteurimage++;
        if (pGameData->compteurimage >= 67){
            pGameData->compteurimage=24;
            pGameData->animation_y=-1000;
            pGameData->animation_x=-1000;
        }
    }
    if (pGameData->gamemode==2){
        ALLEGRO_DISPLAY * ecran=al_get_current_display();
        al_show_mouse_cursor(ecran);
        al_draw_bitmap(pGameData->image[0],0,0,0);
        al_draw_scaled_bitmap(pGameData->image[2],0,0,288,89,600,750,700,150,0);
        al_draw_text(pGameData->police[0], al_map_rgb(216,236,53),200,200,0,nomJ1);
        al_draw_text(pGameData->police[0], al_map_rgb(216,236,53),1150,200,0,deuxpoint);
        al_draw_bitmap(pGameData->image[14],1500,200,0);
        al_draw_text(pGameData->police[0], al_map_rgb(0,0,0),1270,200,0,pGameData->score);
        al_draw_text(pGameData->police[1], al_map_rgb(255,0,0),400,600,0,nomJ2);
        al_draw_text(pGameData->police[1], al_map_rgb(255,0,0),1100,600,0,tour);
        pGameData->tourfait=1;
        if (Point_In_Rectangle(pGameData->mouse, (Vector2D){600,750}, (Vector2D){1300,900}) == 1 && pGameData->click==1)
        {
            pGameData->gamemode=1;
            pGameData->click=0;
            reset(_pExemple);
        }
    }
    if (pGameData->gamemode==3){
        al_draw_bitmap(pGameData->image[15],0,0,0);
        al_draw_bitmap(pGameData->image[21],350,900,0);
        al_draw_bitmap(pGameData->image[23],1800,0,0);
        if (Point_In_Rectangle(pGameData->mouse, (Vector2D){1800,0}, (Vector2D){1872,82}) == 1 && pGameData->click==1){
            pGameData->click=0;
            pGameData->gamemode=5;
        }
        if (Point_In_Rectangle(pGameData->mouse, (Vector2D){350,900}, (Vector2D){639,989}) == 1 && pGameData->click==1){
            pGameData->gamemode=4;
            pGameData->click=0;
        }
        FILE* fichier=NULL;
        fichier= fopen(PATH"\\sauvegarde.txt","r");
        fscanf(fichier,"%d\n%d\n%d\n",&pGameData->meilleurscore1,&pGameData->meilleurscore2,&pGameData->meilleurscore3);
        fclose(fichier);
        if (pGameData->compteursauvegarde==0){
            traitementmeilleurscore(_pExemple);
            pGameData->compteursauvegarde=1;
        }
        fichier = fopen(PATH"\\sauvegarde.txt","w");
        fprintf(fichier,"%d\n%d\n%d",pGameData->meilleurscore1,pGameData->meilleurscore2,pGameData->meilleurscore3);
        fclose(fichier);
        fichier=NULL;
        sprintf(pGameData->scoreJ1,"%d",pGameData->pointJ1);
        sprintf(pGameData->scoreJ2,"%d",pGameData->pointJ2);
        if (pGameData->pointJ1 > pGameData->pointJ2){
            ALLEGRO_DISPLAY * ecran=al_get_current_display();
            al_show_mouse_cursor(ecran);
            al_draw_bitmap(pGameData->image[16],0,0,0);
            al_draw_text(pGameData->police[2], al_map_rgb(255,0,0),450,280,0,nomJ1);
            al_draw_text(pGameData->police[2], al_map_rgb(255,0,0),450,510,0,nomJ2);
            al_draw_text(pGameData->police[2], al_map_rgb(0,0,0),450,375,0,pGameData->scoreJ1);
            al_draw_text(pGameData->police[2], al_map_rgb(0,0,0),450,610,0,pGameData->scoreJ2);
            al_draw_text(pGameData->police[1], al_map_rgb(216,236,53),900,200,0,nomJ1);
            al_draw_text(pGameData->police[1], al_map_rgb(216,236,53),900,600,0,nomJ2);
            al_draw_bitmap(pGameData->image[18],1200,300,0);
            al_draw_bitmap(pGameData->image[18],1200,700,0);
            al_draw_bitmap(pGameData->image[19],900,300,0);
            al_draw_bitmap(pGameData->image[20],900,700,0);
            pGameData->ticketJ1=1;
            pGameData->ticketJ2=0;
        }
        else if (pGameData->pointJ2 > pGameData->pointJ1){
            ALLEGRO_DISPLAY * ecran=al_get_current_display();
            al_show_mouse_cursor(ecran);
            al_draw_bitmap(pGameData->image[16],0,0,0);
            al_draw_text(pGameData->police[2], al_map_rgb(255,0,0),450,280,0,nomJ2);
            al_draw_text(pGameData->police[2], al_map_rgb(255,0,0),450,510,0,nomJ1);
            al_draw_text(pGameData->police[2], al_map_rgb(0,0,0),450,375,0,pGameData->scoreJ2);
            al_draw_text(pGameData->police[2], al_map_rgb(0,0,0),450,610,0,pGameData->scoreJ1);
            al_draw_text(pGameData->police[1], al_map_rgb(216,236,53),900,200,0,nomJ2);
            al_draw_text(pGameData->police[1], al_map_rgb(216,236,53),900,600,0,nomJ1);
            al_draw_bitmap(pGameData->image[18],1200,300,0);
            al_draw_bitmap(pGameData->image[18],1200,700,0);
            al_draw_bitmap(pGameData->image[20],900,700,0);
            al_draw_bitmap(pGameData->image[19],900,300,0);
            pGameData->ticketJ1=0;
            pGameData->ticketJ2=1;
        }
        else {
            ALLEGRO_DISPLAY * ecran=al_get_current_display();
            al_show_mouse_cursor(ecran);
            al_draw_bitmap(pGameData->image[16],0,0,0);
            al_draw_text(pGameData->police[2], al_map_rgb(255,0,0),450,280,0,nomJ1);
            al_draw_text(pGameData->police[2], al_map_rgb(255,0,0),450,510,0,nomJ2);
            al_draw_text(pGameData->police[2], al_map_rgb(0,0,0),450,375,0,pGameData->scoreJ1);
            al_draw_text(pGameData->police[2], al_map_rgb(0,0,0),450,610,0,pGameData->scoreJ2);
            al_draw_text(pGameData->police[1], al_map_rgb(216,236,53),900,200,0,nomJ1);
            al_draw_text(pGameData->police[1], al_map_rgb(216,236,53),900,600,0,nomJ2);
            al_draw_bitmap(pGameData->image[18],1200,300,0);
            al_draw_bitmap(pGameData->image[18],1200,700,0);
            al_draw_bitmap(pGameData->image[19],900,300,0);
            al_draw_bitmap(pGameData->image[19],900,700,0);
            pGameData->ticketJ1=1;
            pGameData->ticketJ2=1;
        }
    }
    if (pGameData->gamemode==4){
        al_draw_bitmap(pGameData->image[22],0,0,0);
        al_draw_bitmap(pGameData->image[17],500,-100,0);
        al_draw_bitmap(pGameData->image[23],1800,0,0);
        sprintf(pGameData->score1,"%d",pGameData->meilleurscore1);
        sprintf(pGameData->score2,"%d",pGameData->meilleurscore2);
        sprintf(pGameData->score3,"%d",pGameData->meilleurscore3);
        al_draw_text(pGameData->police[1], al_map_rgb(0,0,0),1080,520,0,pGameData->score1);
        al_draw_text(pGameData->police[1], al_map_rgb(0,0,0),1080,670,0,pGameData->score2);
        al_draw_text(pGameData->police[1], al_map_rgb(0,0,0),1080,820,0,pGameData->score3);
        if (Point_In_Rectangle(pGameData->mouse, (Vector2D){1800,0}, (Vector2D){1872,82}) == 1 && pGameData->click==1){
            pGameData->click=0;
            pGameData->gamemode=3;
        }
    }
    if (pGameData->gamemode==5){
        exit(0);
    }
}
//////////////////////////////////////////////////   // ANIMATION BALLON DETRUIT
void Exemple_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    free(_pExemple->gameData);
    _pExemple->gameData = NULL;

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}

