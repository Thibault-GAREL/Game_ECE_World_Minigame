#include "map.h"


enum
{
    PAC = 1,
    TAB = 2,
    SNAK = 3,
    TDR = 4,
};


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
    pMapData->image[12]= al_load_bitmap(PATH"\\minimap.png");
    pMapData->image[13]= al_load_bitmap(PATH"\\teteluke.png");
    pMapData->image[14]= al_load_bitmap(PATH"\\ping.png");

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

    pMapData->jeusuivant = PAC ;
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
    pMapData->a=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_F, pMapData->deplacementverti, -1, 0, pMapData->deplacementverti);
    pMapData->b= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_C,pMapData->deplacementhori,-1,0,pMapData->deplacementhori);
    pMapData->c=Get_Touch(_pMap->pEvent, ALLEGRO_KEY_V, pMapData->deplacementverti, 1, 0, pMapData->deplacementverti);
    pMapData->d= Get_Touch(_pMap->pEvent,ALLEGRO_KEY_B,pMapData->deplacementhori,1,0,pMapData->deplacementhori);
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

void rect(PMAP _pMap,float x,float y,float taillex,float tailley,int i){
    MapData* pMapData = _pMap->MapData;
    if (pMapData->pimages[i].x-pMapData->x+x >= 0 && pMapData->pimages[i].x-pMapData->x+x <=1920 && pMapData->pimages[i].y-pMapData->y+y <= 1080 && pMapData->pimages[i].y-pMapData->y+y >= 0){
        if(pMapData->y <= -3240){
            if (pMapData->bonhommey>pMapData->pimages[i].y-pMapData->y+y && pMapData->bonhommey<pMapData->pimages[i].y+y-pMapData->y+tailley){
                if (pMapData->bonhommex >= pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex < pMapData->pimages[i].x+x+10-pMapData->x){
                    pMapData->bonhommex=pMapData->pimages[i].x+x-pMapData->x;
                    pMapData->x-=pMapData->speedhori*pMapData->d;
                }
                else if (pMapData->bonhommex <= pMapData->pimages[i].x+x+taillex-pMapData->x && pMapData->bonhommex > pMapData->pimages[i].x+x+taillex-10-pMapData->x){
                    pMapData->bonhommex=pMapData->pimages[i].x+x+taillex-pMapData->x;
                    pMapData->x-=pMapData->speedhori*pMapData->b;
                }
            }
            if (pMapData->bonhommex>pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex<pMapData->pimages[i].x+x+taillex-pMapData->x){
                if (pMapData->bonhommey >= pMapData->pimages[i].y+y-pMapData->y && pMapData->bonhommey < pMapData->pimages[i].y+y+10-pMapData->y){
                    if (pMapData->bonhommey < 450){
                        pMapData->bonhommey=pMapData->pimages[i].y+y-pMapData->y;
                        pMapData->y-=pMapData->speedverti*pMapData->c;
                    }
                    else if (pMapData->bonhommey >= 450){
                        pMapData->bonhommey = 450;
                    }
                }
                else if (pMapData->bonhommey <= pMapData->pimages[i].y+y+tailley-pMapData->y && pMapData->bonhommey > pMapData->pimages[i].y+y+tailley-10-pMapData->y){
                    if (pMapData->bonhommey < 450){
                        pMapData->bonhommey=pMapData->pimages[i].y+y+tailley-pMapData->y;
                        pMapData->y-=pMapData->speedverti*pMapData->a;
                    }
                    else if (pMapData->bonhommey >= 450){
                        pMapData->bonhommey = 450;
                    }
                }
            }
        }
        if(pMapData->x >= 3840){
            if (pMapData->bonhommey>pMapData->pimages[i].y-pMapData->y+y && pMapData->bonhommey<pMapData->pimages[i].y+y-pMapData->y+tailley){
                if (pMapData->bonhommex >= pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex < pMapData->pimages[i].x+x+10-pMapData->x){
                    if (pMapData->bonhommex > 960){
                        pMapData->bonhommex=pMapData->pimages[i].x+x-pMapData->x;
                        pMapData->x-=pMapData->speedhori*pMapData->d;
                    }
                    else if (pMapData->bonhommex <= 960){
                        pMapData->bonhommex = 960;
                    }
                }
                else if (pMapData->bonhommex <= pMapData->pimages[i].x+x+taillex-pMapData->x && pMapData->bonhommex > pMapData->pimages[i].x+x+taillex-10-pMapData->x){
                    if (pMapData->bonhommex > 960){
                        pMapData->bonhommex=pMapData->pimages[i].x+x+taillex-pMapData->x;
                        pMapData->x-=pMapData->speedhori*pMapData->b;
                    }
                    else if (pMapData->bonhommex <= 960){
                        pMapData->bonhommex = 960;
                    }
                }
            }
            if (pMapData->bonhommex>pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex<pMapData->pimages[i].x+x+taillex-pMapData->x){
                if (pMapData->bonhommey >= pMapData->pimages[i].y+y-pMapData->y && pMapData->bonhommey < pMapData->pimages[i].y+y+10-pMapData->y){
                    pMapData->bonhommey=pMapData->pimages[i].y+y-pMapData->y;
                    pMapData->y-=pMapData->speedverti*pMapData->c;
                }
                else if (pMapData->bonhommey <= pMapData->pimages[i].y+y+tailley-pMapData->y && pMapData->bonhommey > pMapData->pimages[i].y+y+tailley-10-pMapData->y){
                    pMapData->bonhommey=pMapData->pimages[i].y+y+tailley-pMapData->y;
                    pMapData->y-=pMapData->speedverti*pMapData->a;
                }
            }
        }
        if (pMapData->y >= 0){
            if (pMapData->bonhommey>pMapData->pimages[i].y-pMapData->y+y && pMapData->bonhommey<pMapData->pimages[i].y+y-pMapData->y+tailley){
                if (pMapData->bonhommex >= pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex < pMapData->pimages[i].x+x+10-pMapData->x){
                    pMapData->bonhommex=pMapData->pimages[i].x+x-pMapData->x;
                    pMapData->x-=pMapData->speedhori*pMapData->d;
                }
                else if (pMapData->bonhommex <= pMapData->pimages[i].x+x+taillex-pMapData->x && pMapData->bonhommex > pMapData->pimages[i].x+x+taillex-10-pMapData->x){
                    pMapData->bonhommex=pMapData->pimages[i].x+x+taillex-pMapData->x;
                    pMapData->x-=pMapData->speedhori*pMapData->b;
                }
            }
            if (pMapData->bonhommex>pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex<pMapData->pimages[i].x+x+taillex-pMapData->x){
                if (pMapData->bonhommey >= pMapData->pimages[i].y+y-pMapData->y && pMapData->bonhommey < pMapData->pimages[i].y+y+10-pMapData->y){
                    if (pMapData->bonhommey > 540){
                        pMapData->bonhommey=pMapData->pimages[i].y+y-pMapData->y;
                        pMapData->y-=pMapData->speedverti*pMapData->c;
                    }
                    else if (pMapData->bonhommey <= 540){
                        pMapData->bonhommey = 540;
                    }
                }
                else if (pMapData->bonhommey <= pMapData->pimages[i].y+y+tailley-pMapData->y && pMapData->bonhommey > pMapData->pimages[i].y+y+tailley-10-pMapData->y){
                    if (pMapData->bonhommey > 540){
                        pMapData->bonhommey=pMapData->pimages[i].y+y+tailley-pMapData->y;
                        pMapData->y-=pMapData->speedverti*pMapData->a;
                    }
                    else if (pMapData->bonhommey <= 540){
                        pMapData->bonhommey = 540;
                    }
                }
            }
        }
        if (pMapData->x <= 0){
            if (pMapData->bonhommey>pMapData->pimages[i].y-pMapData->y+y && pMapData->bonhommey<pMapData->pimages[i].y+y-pMapData->y+tailley){
                if (pMapData->bonhommex >= pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex < pMapData->pimages[i].x+x+10-pMapData->x){
                    if (pMapData->bonhommex < 960){
                        pMapData->bonhommex=pMapData->pimages[i].x+x-pMapData->x;
                        pMapData->x-=pMapData->speedhori*pMapData->d;
                    }
                    else if (pMapData->bonhommex >= 960){
                        pMapData->bonhommex = 960;
                    }
                }
                else if (pMapData->bonhommex <= pMapData->pimages[i].x+x+taillex-pMapData->x && pMapData->bonhommex > pMapData->pimages[i].x+x+taillex-10-pMapData->x){
                    if (pMapData->bonhommex < 960){
                        pMapData->bonhommex=pMapData->pimages[i].x+x+taillex-pMapData->x;
                        pMapData->x-=pMapData->speedhori*pMapData->b;
                    }
                    else if (pMapData->bonhommex >= 960){
                        pMapData->bonhommex = 960;
                    }
                }
            }
            if (pMapData->bonhommex>pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex<pMapData->pimages[i].x+x+taillex-pMapData->x){
                if (pMapData->bonhommey >= pMapData->pimages[i].y+y-pMapData->y && pMapData->bonhommey < pMapData->pimages[i].y+y+10-pMapData->y){
                    pMapData->bonhommey=pMapData->pimages[i].y+y-pMapData->y;
                    pMapData->y-=pMapData->speedverti*pMapData->c;
                }
                else if (pMapData->bonhommey <= pMapData->pimages[i].y+y+tailley-pMapData->y && pMapData->bonhommey > pMapData->pimages[i].y+y+tailley-10-pMapData->y){
                    pMapData->bonhommey=pMapData->pimages[i].y+y+tailley-pMapData->y;
                    pMapData->y-=pMapData->speedverti*pMapData->a;
                }
            }
        }
        /*if(pMapData->y > -3240 && pMapData->y <0 && pMapData->x > 0 && pMapData->x <3840){
            if (pMapData->bonhommey>pMapData->pimages[i].y-pMapData->y+y && pMapData->bonhommey<pMapData->pimages[i].y+y-pMapData->y+tailley){
                if (pMapData->bonhommex >= pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex < pMapData->pimages[i].x+x+10-pMapData->x){
                    pMapData->bonhommex=pMapData->pimages[i].x+x-pMapData->x;
                    pMapData->x-=pMapData->speedhori*pMapData->d;
                }
                else if (pMapData->bonhommex <= pMapData->pimages[i].x+x+taillex-pMapData->x && pMapData->bonhommex > pMapData->pimages[i].x+x+taillex-10-pMapData->x){
                    pMapData->bonhommex=pMapData->pimages[i].x+x+taillex-pMapData->x;
                    pMapData->x-=pMapData->speedhori*pMapData->b;
                }
            }
            if (pMapData->bonhommex>pMapData->pimages[i].x+x-pMapData->x && pMapData->bonhommex<pMapData->pimages[i].x+x+taillex-pMapData->x){
                if (pMapData->bonhommey >= pMapData->pimages[i].y+y-pMapData->y && pMapData->bonhommey < pMapData->pimages[i].y+y+10-pMapData->y){
                    pMapData->bonhommey=pMapData->pimages[i].y+y-pMapData->y;
                    pMapData->y-=pMapData->speedverti*pMapData->c;
                }
                else if (pMapData->bonhommey <= pMapData->pimages[i].y+y+tailley-pMapData->y && pMapData->bonhommey > pMapData->pimages[i].y+y+tailley-10-pMapData->y){
                    pMapData->bonhommey=pMapData->pimages[i].y+y+tailley-pMapData->y;
                    pMapData->y-=pMapData->speedverti*pMapData->a;
                }
            }
        }*/
    }
}

void gestioncolision(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    rect(_pMap,32,28,152,99,0);
    rect(_pMap,1,73,53,117,0);
    rect(_pMap,177,4,168,59,0);
    rect(_pMap,324,34,258,87,0);
    rect(_pMap,269,71,30,94,0);
    rect(_pMap,559,0,308,63,0);
    rect(_pMap,857,0,195,9,0);
    rect(_pMap,890,37,221,33,0);
    rect(_pMap,110,0,62,77,0);
    rect(_pMap,971,72,142,58,0);
    rect(_pMap,1360,0,186,19,0);
    rect(_pMap,1550,0,27,49,0);
    rect(_pMap,7,222,42,84,0);
    rect(_pMap,50,278,106,41,0);
    rect(_pMap,222,222,29,81,0);
    rect(_pMap,257,159,36,82,0);
    rect(_pMap,298,218,48,31,0);
    rect(_pMap,296,155,340,37,0);
    rect(_pMap,611,93,27,57,0);
    rect(_pMap,635,93,282,33,0);
    rect(_pMap,375,220,283,171,0);
    rect(_pMap,670,282,134,109,0);
    rect(_pMap,7,572,137,110,0);
    rect(_pMap,220,571,77,103,0);
    rect(_pMap,274,457,75,104,0);
    rect(_pMap,321,405,116,47,0);
    rect(_pMap,303,622,144,37,0);
    rect(_pMap,0,934,44,101,0);
    rect(_pMap,44,995,100,58,0);
    rect(_pMap,291,719,140,172,0);
    rect(_pMap,366,890,71,144,0);
    rect(_pMap,458,410,647,91,0);
    rect(_pMap,1004,510,39,48,0);
    rect(_pMap,453,509,30,546,0);
    rect(_pMap,500,557,78,167,0);
    rect(_pMap,498,730,29,71,0);
    rect(_pMap,501,917,61,132,0);
    rect(_pMap,594,628,235,293,0);
    rect(_pMap,449,1050,663,30,0);
    rect(_pMap,926,933,39,47,0);
    rect(_pMap,929,632,38,48,0);
    rect(_pMap,1078,504,35,155,0);
    rect(_pMap,1074,858,39,191,0);
    rect(_pMap,1116,989,41,55,0);
    rect(_pMap,1127,861,25,81,0);
}

void affichageminimap(PMAP _pMap){
    MapData* pMapData = _pMap->MapData;
    pMapData->i++;
    al_draw_bitmap(pMapData->image[12],1300,650,0);
    al_draw_bitmap(pMapData->image[13],pMapData->x /20 + 1530,pMapData->y / 20 + 930,0);
    if (pMapData->jeusuivant == PAC){
        if (pMapData->pimages[10].x-pMapData->x+198 >= 0 && pMapData->pimages[10].x-pMapData->x+198 <=1920 && pMapData->pimages[10].y-pMapData->y+323 <= 1080 && pMapData->pimages[10].y-pMapData->y+319 >= 0 && pMapData->bonhommey>pMapData->pimages[10].y-pMapData->y+490 && pMapData->bonhommey<pMapData->pimages[10].y+490-pMapData->y+319 && pMapData->bonhommex>pMapData->pimages[10].x+198-pMapData->x && pMapData->bonhommex<pMapData->pimages[10].x+198+323-pMapData->x) {
            // QUAND ON RENTRE DANS LA MAISON
        }
        else {
            al_draw_bitmap(pMapData->image[14],1600,900,0);
        }
        al_draw_rectangle(1530,930,1610,932, al_map_rgb(0,255,228),2);
    }
}

void Map_TimedUpdate(PMAP _pMap)
{
    MapData* pMapData = _pMap->MapData;
    pMapData->x+=pMapData->speedhori*pMapData->deplacementhori;
    pMapData->y+=pMapData->speedverti*pMapData->deplacementverti;
    //gestioncolision(_pMap);
    gestionbordure(_pMap);
    for (int i=0;i<pMapData->nbimages;i++){
        al_draw_bitmap(pMapData->image[i],pMapData->pimages[i].x-pMapData->x,pMapData->pimages[i].y-pMapData->y,0);
        al_draw_rectangle(pMapData->bonhommex,pMapData->bonhommey,pMapData->bonhommex+5,pMapData->bonhommey+5, al_map_rgb(255,0,0),5);
    }
    affichageminimap(_pMap);
    printf("%f %f\n",pMapData->bonhommex,pMapData->bonhommey);
    printf("%f %f\n",pMapData->x,pMapData->y);
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

