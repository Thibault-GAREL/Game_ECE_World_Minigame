#include "Map.h"
#include <string.h>

enum
{
    PAC = 4,
    TAB = 5,
    SNAK = 2,
    TDR = 3,
    DP=6,
};


void Map_Create(PMAP _pMap)                               // ECHELLE = 1.25 POUR LE MOMENT
{
    MapData* pMapData = malloc(sizeof (MapData));
    Images PositionImage[1000];
    pMapData->pimages=PositionImage;
    _pMap->MapData = pMapData;
    pMapData->image[0]= al_load_bitmap("..\\Textures/Map/MAP1.png");
    pMapData->image[1]= al_load_bitmap("..\\Textures/Map/MAP2.png");
    pMapData->image[2]= al_load_bitmap("..\\Textures/Map/MAP3.png");
    pMapData->image[3]= al_load_bitmap("..\\Textures/Map/MAP4.png");
    pMapData->image[4]= al_load_bitmap("..\\Textures/Map/MAP5.png");
    pMapData->image[5]= al_load_bitmap("..\\Textures/Map/MAP6.png");
    pMapData->image[6]= al_load_bitmap("..\\Textures/Map/MAP7.png");
    pMapData->image[7]= al_load_bitmap("..\\Textures/Map/MAP8.png");
    pMapData->image[8]= al_load_bitmap("..\\Textures/Map/MAP9.png");
    pMapData->image[9]= al_load_bitmap("..\\Textures/Map/MAP10.png");
    pMapData->image[10]= al_load_bitmap("..\\Textures/Map/MAP11.png");
    pMapData->image[11]= al_load_bitmap("..\\Textures/Map/MAP12.png");
    pMapData->image[12]= al_load_bitmap("..\\Textures/Map/minimap.png");
    pMapData->image[13]= al_load_bitmap("..\\Textures/Map/teteluke.png");
    pMapData->image[14]= al_load_bitmap("..\\Textures/Map/ping.png");
    pMapData->image[15]= al_load_bitmap("..\\Textures/Map/bonhommegauche.png");
    pMapData->image[16]= al_load_bitmap("..\\Textures/Map/bonhommedroite.png");
    pMapData->image[17]= al_load_bitmap("..\\Textures/Map/fumeegauche.png");
    pMapData->image[18]= al_load_bitmap("..\\Textures/Map/fumeedroite.png");
    pMapData->image[19]= al_load_bitmap("..\\Textures/Map/panneaumetal.png");
    pMapData->image[20]= al_load_bitmap("..\\Textures/Map/teteville.png");
    pMapData->image[21]= al_load_bitmap("..\\Textures/Map/ville1.png");
    pMapData->image[22]= al_load_bitmap("..\\Textures/Map/ville2.png");
    pMapData->image[23]= al_load_bitmap("..\\Textures/Map/ville3.png");
    pMapData->image[24]= al_load_bitmap("..\\Textures/Map/ville4.png");
    pMapData->image[25]= al_load_bitmap("..\\Textures/Map/testvaisseau.png");
    pMapData->image[26]= al_load_bitmap("..\\Textures/Map/vaisseaubondroite.png");
    pMapData->image[27]= al_load_bitmap("..\\Textures/Map/vaisseaubongauche.png");
    pMapData->image[28]= al_load_bitmap("..\\Textures/Map/MAP1COLI.png");
    pMapData->image[29]= al_load_bitmap("..\\Textures/Map/MAP2COLI.png");
    pMapData->image[30]= al_load_bitmap("..\\Textures/Map/MAP3COLI.png");
    pMapData->image[31]= al_load_bitmap("..\\Textures/Map/MAP4COLI.png");
    pMapData->image[32]= al_load_bitmap("..\\Textures/Map/MAP5COLI.png");
    pMapData->image[33]= al_load_bitmap("..\\Textures/Map/MAP6COLI.png");
    pMapData->image[34]= al_load_bitmap("..\\Textures/Map/MAP7COLI.png");
    pMapData->image[35]= al_load_bitmap("..\\Textures/Map/MAP8COLI.png");
    pMapData->image[36]= al_load_bitmap("..\\Textures/Map/MAP9COLI.png");
    pMapData->image[37]= al_load_bitmap("..\\Textures/Map/MAP10COLI.png");
    pMapData->image[38]= al_load_bitmap("..\\Textures/Map/MAP11COLI.png");
    pMapData->image[39]= al_load_bitmap("..\\Textures/Map/MAP12COLI.png");
    pMapData->image[40]= al_load_bitmap("..\\Textures/Map/scoreboard.png");
    pMapData->image[41]= al_load_bitmap("..\\Textures/Map/Scoreboardtext.png");
    pMapData->image[42]= al_load_bitmap("..\\Textures/Map/ticket.png");

    pMapData->pimages[0].x = 0;
    pMapData->pimages[0].y = -3240;
    pMapData->pimages[1].x = 1920;
    pMapData->pimages[1].y = -3240;
    pMapData->pimages[2].x = 3840;
    pMapData->pimages[2].y = -3240;
    pMapData->pimages[3].x = 0;
    pMapData->pimages[3].y = -2160;
    pMapData->pimages[4].x = 1920;
    pMapData->pimages[4].y = -2160;
    pMapData->pimages[5].x = 3840;
    pMapData->pimages[5].y = -2160;
    pMapData->pimages[6].x = 0;
    pMapData->pimages[6].y = -1080;
    pMapData->pimages[7].x = 1920;
    pMapData->pimages[7].y = -1080;
    pMapData->pimages[8].x = 3840;
    pMapData->pimages[8].y = -1080;
    pMapData->pimages[9].x = 0;
    pMapData->pimages[9].y = 0;
    pMapData->pimages[10].x = 1920;
    pMapData->pimages[10].y = 0;
    pMapData->pimages[11].x = 3840;
    pMapData->pimages[11].y = 0;




    pMapData->x = 0;
    pMapData->y = 0;

    pMapData->bonhommex=960;
    pMapData->bonhommey=540;

    pMapData->nbimages = 12;

    pMapData->deplacementhori=0;
    pMapData->deplacementverti=0;
    pMapData->speedverti=6;
    pMapData->speedhori=5;

    pMapData->a=0;
    pMapData->b=0;
    pMapData->c=0;
    pMapData->d=0;

    pMapData->jeusuivant = DP ;
    pMapData->sensbonhommex = 0;
    pMapData->sensbonhommey = 0;
    pMapData->compteurfumme =0;
    pMapData->fumeea=0;
    pMapData->fumeeb=0;
    pMapData->fumeec=0;
    pMapData->fumeed=0;
    pMapData->vetofumee=0;

    pMapData->compteurville=0;
    pMapData->zone1=0;
    pMapData->zone2=0;
    pMapData->zone3=0;
    pMapData->zone4=0;

    pMapData->compteurvaisseaubon=0;
    pMapData->imagebondroite = 16;
    pMapData->imagebongauche =15;
    pMapData->compteurcooldownvaiss=0;
    pMapData->compteurcooldownvaiss2=0;

    pMapData->compteurcolision=0;
    pMapData->vetoF=0;
    pMapData->vetoV=0;
    pMapData->vetoB=0;
    pMapData->vetoC=0;
    pMapData->compteurcolision2=0;

    pMapData->imageactuelle=0;
}

void Map_Update(PMAP _pMap)
{
    if (!_pMap->MapData)
    {
        Map_Create(_pMap);
    }

    MapData* pMapData = _pMap->MapData;

    if (_pMap->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pMapData->mouse.x = _pMap->pEvent->mouse.x*1.25;
        pMapData->mouse.y = _pMap->pEvent->mouse.y*1.25;
    }
    if ( _pMap->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        pMapData->click=1;
    }

    pMapData->imageactuelle = Get_Touch(_pMap->pEvent, ALLEGRO_KEY_TAB, pMapData->imageactuelle, 1, 0, pMapData->imageactuelle);


    if (pMapData->compteurvaisseaubon==0){
        if (pMapData->vetoF==0 && pMapData->deplacementverti==-1){
            pMapData->deplacementverti=0;
        }
        if (pMapData->vetoV==0 && pMapData->deplacementverti==1){
            pMapData->deplacementverti=0;
        }
        pMapData->deplacementverti=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_F, pMapData->deplacementverti, -pMapData->vetoF, 0, pMapData->deplacementverti);
        pMapData->deplacementverti=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_V, pMapData->deplacementverti, pMapData->vetoV, 0,pMapData->deplacementverti);

        if (pMapData->vetoC==0 && pMapData->deplacementhori==-1){
            pMapData->deplacementhori=0;
        }
        if (pMapData->vetoB==0 && pMapData->deplacementhori==1){
            pMapData->deplacementhori=0;
        }
        pMapData->deplacementhori=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_C, pMapData->deplacementhori, -pMapData->vetoC, 0, pMapData->deplacementhori);
        pMapData->deplacementhori=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_B, pMapData->deplacementhori, pMapData->vetoB, 0,pMapData->deplacementhori);
    }
    if (pMapData->compteurvaisseaubon==1){
        pMapData->deplacementverti=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_F, pMapData->deplacementverti, -1, 0, pMapData->deplacementverti);
        pMapData->deplacementhori= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_C,pMapData->deplacementhori,-1,0,pMapData->deplacementhori);
        pMapData->deplacementverti=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_V, pMapData->deplacementverti, 1, 0, pMapData->deplacementverti);
        pMapData->deplacementhori= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_B,pMapData->deplacementhori,1,0,pMapData->deplacementhori);
    }

    pMapData->a=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_F, pMapData->deplacementverti, -1, 0, pMapData->deplacementverti);
    pMapData->b= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_C,pMapData->deplacementhori,-1,0,pMapData->deplacementhori);
    pMapData->c=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_V, pMapData->deplacementverti, 1, 0, pMapData->deplacementverti);
    pMapData->d= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_B,pMapData->deplacementhori,1,0,pMapData->deplacementhori);

    if (_pMap->pEvent->keyboard.keycode == ALLEGRO_KEY_F){
        pMapData->sensbonhommey = 0;
    }
    if (_pMap->pEvent->keyboard.keycode == ALLEGRO_KEY_C){
        pMapData->sensbonhommex = 0;
    }
    if (_pMap->pEvent->keyboard.keycode == ALLEGRO_KEY_V){
        pMapData->sensbonhommey = 1;
    }
    if (_pMap->pEvent->keyboard.keycode == ALLEGRO_KEY_B){
        pMapData->sensbonhommex = 1;
    }
    if (_pMap->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        pMapData->click=0;
    }
}


void gestionbordure(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    if (pMapData->x <= 0 || pMapData->bonhommex < 960){
        pMapData->x = 0;
        pMapData->bonhommex+=pMapData->speedhori*pMapData->deplacementhori;
    }
    else if (pMapData->x >= 3840 || pMapData->bonhommex > 960){
        pMapData->x = 3840;
        pMapData->bonhommex+=pMapData->speedhori*pMapData->deplacementhori;
    }
    if (pMapData->y >= 0 || pMapData->bonhommey > 540){
        pMapData->y = 0;
        pMapData->bonhommey+=pMapData->speedverti*pMapData->deplacementverti;
    }
    else if (pMapData->y <=-3240 || pMapData->bonhommey < 540){
        pMapData->y = -3240;
        pMapData->bonhommey+=pMapData->speedverti*pMapData->deplacementverti;
    }
    if (pMapData->bonhommex < 0){
        pMapData->bonhommex=0;
    }
    if (pMapData->bonhommex > 5760){
        pMapData->bonhommex=5760;
    }
    if (pMapData->bonhommey > 1080){
        pMapData->bonhommey=1080;
    }
    if (pMapData->bonhommey < -3240){
        pMapData->bonhommey=-3240;
    }
    if (pMapData->bonhommex > 1920){
        pMapData->bonhommex = 1920;
    }
    if (pMapData->bonhommey < 0){
        pMapData->bonhommey=0;
    }
}

void affichageminimap(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    pMapData->i++;
    al_draw_bitmap(pMapData->image[12],1300,650,0);
    if (pMapData->jeusuivant == PAC){
        if (pMapData->pimages[10].x-pMapData->x+348 >= 0 && pMapData->pimages[10].x-pMapData->x+348 <=1920 && pMapData->pimages[10].y-pMapData->y+40 <= 1080 && pMapData->pimages[10].y-pMapData->y+59 >= 0 && pMapData->bonhommey>pMapData->pimages[10].y-pMapData->y+752 && pMapData->bonhommey<pMapData->pimages[10].y+752-pMapData->y+59 && pMapData->bonhommex>pMapData->pimages[10].x+348-pMapData->x && pMapData->bonhommex<pMapData->pimages[10].x+348+40-pMapData->x) {
            Map_Destroy(_pMap);
            return ;
        }
        else {
            al_draw_bitmap(pMapData->image[14],1600,900,0);
            al_draw_rectangle(1535+(pMapData->x)/19,930,1610,932, al_map_rgb(0,255,228),2);
            if (pMapData->y < 0){
                al_draw_rectangle(1535+(pMapData->x)/19,930+(pMapData->y)/20,1535+(pMapData->x)/19+2,932, al_map_rgb(0,255,228),2);
            }
        }
    }
    if (pMapData->jeusuivant == TAB){
        if (pMapData->pimages[0].x-pMapData->x+1496 >= 0 && pMapData->pimages[0].x-pMapData->x+1496 <=1920 && pMapData->pimages[0].y-pMapData->y+100 <= 1080 && pMapData->pimages[0].y-pMapData->y+108 >= 0 && pMapData->bonhommey>pMapData->pimages[0].y-pMapData->y+392 && pMapData->bonhommey<pMapData->pimages[0].y+392-pMapData->y+108 && pMapData->bonhommex>pMapData->pimages[0].x+1496-pMapData->x && pMapData->bonhommex<pMapData->pimages[0].x+1496+100-pMapData->x) {
            Map_Destroy(_pMap);
            return ;
        }
        else {
            al_draw_bitmap(pMapData->image[14],1565,750,0);
            if (pMapData->y > -3240+350 ){
                al_draw_rectangle(1535+(pMapData->x)/19,930+(pMapData->y)/20,1535+(pMapData->x)/19+2,780,al_map_rgb(0,255,228),2);
            }
            al_draw_rectangle(1573,782,1535+(pMapData->x)/19,784, al_map_rgb(0,255,228),2);
        }
    }
    if (pMapData->jeusuivant == SNAK){
        if (pMapData->pimages[8].x-pMapData->x+998 >= 0 && pMapData->pimages[8].x-pMapData->x+998 <=1920 && pMapData->pimages[8].y-pMapData->y+98 <= 1080 && pMapData->pimages[8].y-pMapData->y+90 >= 0 && pMapData->bonhommey>pMapData->pimages[8].y-pMapData->y+0 && pMapData->bonhommey<pMapData->pimages[8].y+0-pMapData->y+90 && pMapData->bonhommex>pMapData->pimages[8].x+998-pMapData->x && pMapData->bonhommex<pMapData->pimages[8].x+998+98-pMapData->x) {
            Map_Destroy(_pMap);
            return ;
        }
        else {
            al_draw_bitmap(pMapData->image[14],1735,822,0);
            al_draw_rectangle(1535+(pMapData->x)/19,850,1745,852, al_map_rgb(0,255,228),2);
            al_draw_rectangle(1535+(pMapData->x)/19,930+(pMapData->y)/20,1535+(pMapData->x)/19+2,850, al_map_rgb(0,255,228),2);
        }
    }
    if (pMapData->jeusuivant == TDR){
        if (pMapData->bonhommex > pMapData->pimages[5].x-pMapData->x+233 && pMapData->bonhommex < pMapData->pimages[5].x-pMapData->x+233+50 && pMapData->bonhommey > pMapData->pimages[5].y-pMapData->y+682 && pMapData->bonhommey < pMapData->pimages[5].y-pMapData->y+682+61){
            Map_Destroy(_pMap);
            return ;
        }
        else {
            al_draw_bitmap(pMapData->image[14],1695,805,0);
            al_draw_rectangle(1535+(pMapData->x)/19,930+(pMapData->y)/20,1535+(pMapData->x)/19+2,838, al_map_rgb(0,255,228),2);
            al_draw_rectangle(1535+(pMapData->x)/19,838,1707,840, al_map_rgb(0,255,228),2);
        }
    }
    if (pMapData->jeusuivant == DP){
        if (pMapData->bonhommex > pMapData->pimages[6].x-pMapData->x+873 && pMapData->bonhommex < pMapData->pimages[6].x-pMapData->x+927 && pMapData->bonhommey > pMapData->pimages[6].y-pMapData->y+618 && pMapData->bonhommey < pMapData->pimages[6].y-pMapData->y+690){
            Map_Destroy(_pMap);
            return ;
        }
        else {
            al_draw_bitmap(pMapData->image[14],1530,845,0);
            al_draw_rectangle(1535+(pMapData->x)/19,930+(pMapData->y)/20,1535+(pMapData->x)/19+2,880,al_map_rgb(0,255,228),2);
            al_draw_rectangle(1550,880,1535+(pMapData->x)/19,882, al_map_rgb(0,255,228),2);
        }
    }
    al_draw_bitmap(pMapData->image[13],pMapData->x /20 + 1530,pMapData->y / 20 + 920,0);
}

void affichagebonhomme(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    pMapData->fumeea=0;pMapData->fumeeb=0;pMapData->fumeec=0;pMapData->fumeed=0;
    srand(time(NULL));
    pMapData->compteurcooldownvaiss2++;
    if (pMapData->imagebondroite==16){
        pMapData->compteurcooldownvaiss=0;
    }
    if (pMapData->compteurvaisseaubon == 1){
        pMapData->imagebongauche=27;
        pMapData->imagebondroite=26;
        pMapData->compteurcooldownvaiss++;
        pMapData->vetofumee=1;
        if (pMapData->pimages[3].x+690-pMapData->x <= pMapData->bonhommex && pMapData->pimages[3].x+690-pMapData->x+220 >= pMapData->bonhommex && pMapData->pimages[3].y+1070-pMapData->y<= pMapData->bonhommey && pMapData->pimages[3].y+1070-pMapData->y+127 >= pMapData->bonhommey && pMapData->compteurcooldownvaiss>100){
            pMapData->compteurvaisseaubon=0;
            pMapData->imagebongauche=15;
            pMapData->imagebondroite=16;
            pMapData->compteurcooldownvaiss2=0;
        }
    }
    if (pMapData->compteurfumme%20==1){
        pMapData->fumeea=rand()%4;pMapData->fumeeb=rand()%4;pMapData->fumeec=rand()%4;pMapData->fumeed=rand()%4;
    }
    if (pMapData->sensbonhommey==0 && pMapData->sensbonhommex==1){
        al_draw_bitmap(pMapData->image[pMapData->imagebondroite],pMapData->bonhommex-40,pMapData->bonhommey-50,0);
        if (pMapData->vetofumee==0){
            if(pMapData->compteurfumme%25 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-60,pMapData->bonhommey+20,0);
            }
            if(pMapData->compteurfumme%24 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-65,pMapData->bonhommey+30,0);
            }
            if (pMapData->compteurfumme%23 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-70,pMapData->bonhommey+10,0);
            }
            if (pMapData->compteurfumme%22 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-75,pMapData->bonhommey+15,0);
            }
        }
    }
    if (pMapData->sensbonhommey==1 && pMapData->sensbonhommex==0) {
        al_draw_bitmap(pMapData->image[pMapData->imagebongauche],pMapData->bonhommex-60,pMapData->bonhommey-50,0);
        if (pMapData->vetofumee==0){
            if(pMapData->compteurfumme%25 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+40,pMapData->bonhommey+10,0);
            }
            if(pMapData->compteurfumme%24 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+45,pMapData->bonhommey+30,0);
            }
            if (pMapData->compteurfumme%23 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+45,pMapData->bonhommey+15,0);
            }
            if (pMapData->compteurfumme%22 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+30,pMapData->bonhommey+20,0);
            }
        }
    }
    if (pMapData->sensbonhommex == 0){
        al_draw_bitmap(pMapData->image[pMapData->imagebongauche],pMapData->bonhommex-60,pMapData->bonhommey-50,0);
        if (pMapData->vetofumee==0){
            if(pMapData->compteurfumme%25 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+40,pMapData->bonhommey+10,0);
            }
            if(pMapData->compteurfumme%24 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+45,pMapData->bonhommey+30,0);
            }
            if (pMapData->compteurfumme%23 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+45,pMapData->bonhommey+15,0);
            }
            if (pMapData->compteurfumme%22 != 1){
                al_draw_bitmap(pMapData->image[17],pMapData->bonhommex+30,pMapData->bonhommey+20,0);
            }
        }
    }
    if (pMapData->sensbonhommex == 1){
        al_draw_bitmap(pMapData->image[pMapData->imagebondroite],pMapData->bonhommex-40,pMapData->bonhommey-50,0);
        if (pMapData->vetofumee==0){
            if(pMapData->compteurfumme%25 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-60,pMapData->bonhommey+20,0);
            }
            if(pMapData->compteurfumme%24 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-65,pMapData->bonhommey+30,0);
            }
            if (pMapData->compteurfumme%23 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-70,pMapData->bonhommey+10,0);
            }
            if (pMapData->compteurfumme%22 != 1){
                al_draw_bitmap(pMapData->image[18],pMapData->bonhommex-75,pMapData->bonhommey+15,0);
            }
        }
    }
    if (pMapData->a==0 && pMapData->b==0 && pMapData->c==0 && pMapData->d==0){
        pMapData->vetofumee=1;
    }
    else {
        pMapData->vetofumee=0;
    }
    pMapData->compteurfumme++;
}


void affichageville(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    if (pMapData->x < 1920 && pMapData->y<-1080 && pMapData->zone1==0){
        al_draw_bitmap(pMapData->image[19],0,0,0);
        al_draw_bitmap(pMapData->image[20],120,100,0);
        al_draw_bitmap(pMapData->image[21],230,120,0);
        pMapData->compteurville++;
        pMapData->zone2=0;
        pMapData->zone3=0;
        pMapData->zone4=0;
        if (pMapData->compteurville >= 200){
            pMapData->compteurville=0;
            pMapData->zone1=1;
        }
    }
    if (pMapData->x > 1920 && pMapData->y <-1080  && pMapData->zone2==0){
        al_draw_bitmap(pMapData->image[19],0,0,0);
        al_draw_bitmap(pMapData->image[20],120,100,0);
        al_draw_bitmap(pMapData->image[22],230,120,0);
        pMapData->compteurville++;
        pMapData->zone1=0;
        pMapData->zone3=0;
        pMapData->zone4=0;
        if (pMapData->compteurville >= 200){
            pMapData->compteurville=0;
            pMapData->zone2=1;
        }
    }
    if (pMapData->x < 1920 && pMapData->y >-1080 && pMapData->zone3==0){
        al_draw_bitmap(pMapData->image[19],0,0,0);
        al_draw_bitmap(pMapData->image[20],120,100,0);
        al_draw_bitmap(pMapData->image[23],230,120,0);
        pMapData->compteurville++;
        pMapData->zone1=0;
        pMapData->zone2=0;
        pMapData->zone4=0;
        if (pMapData->compteurville >= 200){
            pMapData->compteurville=0;
            pMapData->zone3=1;
        }
    }
    if (pMapData->x > 1920 && pMapData->y > -1080 && pMapData->zone4==0){
        al_draw_bitmap(pMapData->image[19],0,0,0);
        al_draw_bitmap(pMapData->image[20],120,100,0);
        al_draw_bitmap(pMapData->image[24],230,120,0);
        pMapData->compteurville++;
        pMapData->zone1=0;
        pMapData->zone2=0;
        pMapData->zone3=0;
        if (pMapData->compteurville >= 200){
            pMapData->compteurville=0;
            pMapData->zone4=1;
        }
    }

}

void gestionvaisseau(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    if(pMapData->compteurvaisseaubon==0){
        al_draw_bitmap(pMapData->image[25],pMapData->pimages[3].x+635-pMapData->x,pMapData->pimages[3].y+955-pMapData->y,0);
        pMapData->speedverti=6;
        pMapData->speedhori=5;
    }
    if (pMapData->compteurvaisseaubon==0 && pMapData->pimages[3].x+690-pMapData->x <= pMapData->bonhommex && pMapData->pimages[3].x+690-pMapData->x+220 >= pMapData->bonhommex && pMapData->pimages[3].y+1070-pMapData->y<= pMapData->bonhommey && pMapData->pimages[3].y+1070-pMapData->y+127 >= pMapData->bonhommey && pMapData->compteurcooldownvaiss2>=200){
        pMapData->compteurvaisseaubon=1;
    }
}

void gestioncolision(PMAP _pMap,float x,float y,int indice){
    MapData* pMapData = _pMap->MapData;
    for (int i=0;i<12;i++){
        if (pMapData->pimages[i].x-pMapData->x >-1920 && pMapData->pimages[i].x-pMapData->x < 1920 && pMapData->pimages[i].y-pMapData->y > -1080 && pMapData->pimages[i].y-pMapData->y < 1080){
            if (al_get_pixel(pMapData->image[i+28],0-pMapData->pimages[i].x+pMapData->x+pMapData->bonhommex+x,0-pMapData->pimages[i].y+pMapData->y+pMapData->bonhommey+y).r>=0.929411 && al_get_pixel(pMapData->image[i+28],0-pMapData->pimages[i].x+pMapData->x+pMapData->bonhommex+x,0-pMapData->pimages[i].y+pMapData->y+pMapData->bonhommey+y).r<0.92942){
                pMapData->compteurcolision2++;
                if (indice==0){
                    pMapData->vetoF=0;
                }
                else if (indice==1){
                    pMapData->vetoV=0;
                }
                else if(indice==2){
                    pMapData->vetoB=0;
                }
                else if (indice==3) {
                    pMapData->vetoC=0;
                }
            }
        }
    }
    if (pMapData->compteurcolision2==0 && indice==0){
        pMapData->vetoF=1;
    }
    if (pMapData->compteurcolision2==0 && indice==1){
        pMapData->vetoV=1;
    }
    if (pMapData->compteurcolision2==0 && indice==2){
        pMapData->vetoB=1;
    }
    if (pMapData->compteurcolision2==0 && indice==3){
        pMapData->vetoC=1;
    }
    pMapData->compteurcolision2=0;
}

void tableaudescore(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    al_draw_bitmap(pMapData->image[40],750,380,0);
    al_draw_bitmap(pMapData->image[41],900,410,0);
    al_draw_scaled_bitmap(pMapData->image[42],0,0,250,250,1140,490,80,80,0);
    al_draw_scaled_bitmap(pMapData->image[42],0,0,250,250,1140,560,80,80,0);
}

void Map_TimedUpdate(PMAP _pMap)
{
    MapData* pMapData = _pMap->MapData;
    ALLEGRO_DISPLAY* ecran=al_get_current_display();
    al_hide_mouse_cursor(ecran);
    pMapData->x+=pMapData->speedhori*pMapData->deplacementhori;
    pMapData->y+=pMapData->speedverti*pMapData->deplacementverti;
    gestionbordure(_pMap);
    for (int j=28;j<40;j++){
        al_draw_bitmap(pMapData->image[j],pMapData->pimages[j-28].x-pMapData->x,pMapData->pimages[j-28].y-pMapData->y,0);
    }
    for (int i=0;i<pMapData->nbimages;i++){
        al_draw_bitmap(pMapData->image[i],pMapData->pimages[i].x-pMapData->x,pMapData->pimages[i].y-pMapData->y,0);
        al_draw_rectangle(-10000,-10000,-10000,-10000, al_map_rgb(0,0,0),2);      // obligé de l'avoir pour faire afficher le bonhomme ????
    }
    affichageminimap(_pMap);
    gestionvaisseau(_pMap);
    affichagebonhomme(_pMap);
    affichageville(_pMap);
    if (pMapData->compteurcolision%6==1){
        gestioncolision(_pMap,5,-45,0);
        gestioncolision(_pMap,-35,40,3);
    }
    if (pMapData->compteurcolision%8==1 && pMapData->compteurcolision%6!=1){
        gestioncolision(_pMap,40,40,2);
        gestioncolision(_pMap,5,50,1);
    }
    pMapData->compteurcolision++;
    if (pMapData->imageactuelle==1){
        tableaudescore(_pMap);
    }
}

void Map_Destroy(PMAP _pMap)
{
    MapData* pMapData = _pMap->MapData;
    *_pMap->pCurrentGameId = pMapData->jeusuivant;
    _pMap->MapData = NULL;
    free(_pMap->MapData);
}

