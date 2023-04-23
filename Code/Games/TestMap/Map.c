#include "map.h"

void Map_Create(PMAP _pMap)                               // ECHELLE = 1.25 POUR LE MOMENT
{
    MapData* pMapData = malloc(sizeof (MapData));
    Images PositionImage[1000];
    pMapData->pimages=PositionImage;
    _pMap->MapData = pMapData;
    pMapData->image[0]= al_load_bitmap(PATH"\\MAP1.png");
    pMapData->image[1]= al_load_bitmap(PATH"\\MAP2.png");
    pMapData->image[2]= al_load_bitmap(PATH"\\MAP3.png");
    pMapData->image[3]= al_load_bitmap(PATH"\\MAP4.png");
    pMapData->image[4]= al_load_bitmap(PATH"\\MAP5.png");
    pMapData->image[5]= al_load_bitmap(PATH"\\MAP6.png");
    pMapData->image[6]= al_load_bitmap(PATH"\\MAP7.png");
    pMapData->image[7]= al_load_bitmap(PATH"\\MAP8.png");
    pMapData->image[8]= al_load_bitmap(PATH"\\MAP9.png");
    pMapData->image[9]= al_load_bitmap(PATH"\\MAP10.png");
    pMapData->image[10]= al_load_bitmap(PATH"\\MAP11.png");
    pMapData->image[11]= al_load_bitmap(PATH"\\MAP12.png");


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
    pMapData->deplacementverti=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_F, pMapData->deplacementverti, -1, 0, pMapData->deplacementverti);
    pMapData->deplacementhori= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_C,pMapData->deplacementhori,-1,0,pMapData->deplacementhori);
    pMapData->deplacementverti=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_V, pMapData->deplacementverti, 1, 0, pMapData->deplacementverti);
    pMapData->deplacementhori= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_B,pMapData->deplacementhori,1,0,pMapData->deplacementhori);
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
}

void rect(PMAP _pMap,float x,float y,float taillex,float tailley,int i){
    MapData* pMapData = _pMap->MapData;
    if (pMapData->pimages[i].x-pMapData->x+x >= 0 && pMapData->pimages[i].x-pMapData->x+x <=1920 && pMapData->pimages[i].y-pMapData->y+y <= 1080 && pMapData->pimages[i].y-pMapData->y+y >= 0){
        if (pMapData->bonhommey>pMapData->pimages[i].y-pMapData->y+y && pMapData->bonhommey<pMapData->pimages[i].y+y-pMapData->y+tailley){
            if (pMapData->bonhommex >= pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex < pMapData->pimages[i].x+x+10-pMapData->x){
                pMapData->bonhommex=pMapData->pimages[i].x+x-pMapData->x;
            }
            else if (pMapData->bonhommex <= pMapData->pimages[i].x+x+taillex-pMapData->x && pMapData->bonhommex > pMapData->pimages[i].x+x+taillex-10-pMapData->x){
                pMapData->bonhommex=pMapData->pimages[i].x+x+taillex-pMapData->x;
            }
        }
        if (pMapData->bonhommex>pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex<pMapData->pimages[i].x+x+taillex-pMapData->x){
            if (pMapData->bonhommey >= pMapData->pimages[i].y+y-pMapData->y && pMapData->bonhommey < pMapData->pimages[i].y+y+10-pMapData->y){
                pMapData->bonhommey=pMapData->pimages[i].y+y-pMapData->y;
            }
            else if (pMapData->bonhommey <= pMapData->pimages[i].y+y+tailley-pMapData->y && pMapData->bonhommey > pMapData->pimages[i].y+y+tailley-10-pMapData->y){
                pMapData->bonhommey=pMapData->pimages[i].y+y+tailley-pMapData->y;
            }
        }
    }
}

void gestioncolision(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    rect(_pMap,32,28,152,99,0);
}


void Map_TimedUpdate(PMAP _pMap)
{
    MapData* pMapData = _pMap->MapData;
    pMapData->x+=pMapData->speedhori*pMapData->deplacementhori;
    pMapData->y+=pMapData->speedverti*pMapData->deplacementverti;
    gestionbordure(_pMap);
    for (int i=0;i<pMapData->nbimages;i++){
        al_draw_bitmap(pMapData->image[i],pMapData->pimages[i].x-pMapData->x,pMapData->pimages[i].y-pMapData->y,0);
        al_draw_rectangle(pMapData->bonhommex,pMapData->bonhommey,pMapData->bonhommex+5,pMapData->bonhommey+5, al_map_rgb(255,0,0),5);
    }
    gestioncolision(_pMap);
    printf("%f %f\n",pMapData->bonhommex,pMapData->bonhommey);
}

void Map_Destroy(PMAP _pMap)
{
    printf("Destruction du jeu...\n");

    free(_pMap->MapData);
    _pMap->MapData = NULL;

    printf("Jeu detruit\n");

    *_pMap->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}

