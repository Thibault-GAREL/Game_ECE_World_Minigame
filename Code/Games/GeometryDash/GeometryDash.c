//
// Created by garel on 06/05/2023.
//


#include "GeometryDash.h"

void Geo_Create(PGAME _pGeoDash)
{
    GeoData * pGeoData = (GeoData *) malloc (sizeof (GeoData));
    _pGeoDash->gameData = pGeoData;

    pGeoData->image [0] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\GDa.png");
    pGeoData->image [1] = al_load_bitmap(PATH "\\Textures\\TDLR\\boutonplay.png");
    pGeoData->image [2] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\Fond.png");
    pGeoData->image [3] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\Rectangle2.png");


    pGeoData->ay_player = 1;
    pGeoData->vy_player = 0;
    pGeoData->y_player = y_debut_player;
    pGeoData->sol = 1000;
    pGeoData->x = 0;
    pGeoData->vx = 6;
    pGeoData->x_fond = 0;
    pGeoData->timer = 0;
    pGeoData->onGround = 0;

    pGeoData->click = 0;

    //pGeoData->pBackground = al_load_bitmap("..\\Textures\\DarkPiano\\Bk.png");
    pGeoData->pFont50 = al_load_font("..\\Textures\\Fonts\\police.TTF", 50, 0);
    
    pGeoData->playerCurrent = 0;

    //pGeoData->desert = al_load_bitmap("..\\Textures\\Snake\\Desert.png");
    pGeoData->menubk = pGeoData->image[2];
    pGeoData->buttonPlay = al_load_bitmap("..\\Textures\\Snake\\BouttonPlay.png");
    pGeoData->buttonMap = al_load_bitmap("..\\Textures\\Snake\\MapImage.png");
    pGeoData->isMenuEnable = 1;

    pGeoData->scores[0] = 0;
    pGeoData->scores[1] = 0;
    pGeoData->isDead = 0;
    pGeoData->score = 0;

    for (int i = 0; i < 1000; ++i) 
    {
        pGeoData->obstacles [i] = i*100 + 2000;
    }
    
    int newType = 0;
    int count = 0;

    for (int i = 0; i < 1000; ++i) 
    {
        newType = rand()%3;

        if (newType != rectangle)
        {
            if (++count > 3)
            {
                newType = rectangle;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
        
        pGeoData->id_obstacles [i] = newType;
    }
    pGeoData->id_obstacles [0] = rectangle;
}


void Geo_Update(PGAME _pGeoDash){

    if (_pGeoDash->gameData == NULL)
    {
        Geo_Create(_pGeoDash);
    }

    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;

    if (pGeoData->isMenuEnable)
    {
        MenuG_UpdateEvent(_pGeoDash);
        return;
    }

    GameGStateChecker(_pGeoDash);

    if (_pGeoDash->pEvent->mouse.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pGeoData->mouse_position.x = _pGeoDash->pEvent->mouse.x;
        pGeoData->mouse_position.y = _pGeoDash->pEvent->mouse.y;
    }
    if (_pGeoDash->pEvent->mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && _pGeoDash->pEvent->mouse.button == 1){
        pGeoData->click =1;
    }
    if (_pGeoDash->pEvent->mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && _pGeoDash->pEvent->mouse.button == 1){
        pGeoData->click =0;
    }

    if (Get_Touch(_pGeoDash->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0))
    {  
        if (pGeoData->onGround)
        {
            pGeoData->vy_player = -20;
            pGeoData->onGround = 0;
        }
    }

}

void Geo_TimedUpdate(PGAME _pGeoDash) {

    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;

    if (pGeoData->isMenuEnable)
    {
        MenuG_Draw(_pGeoDash);
        return;
    }
    
    pGeoData->vy_player += pGeoData ->ay_player;
    pGeoData->y_player += pGeoData ->vy_player;
    pGeoData->score = pGeoData->x;

    for (int i = 0; i < 1000; ++i) 
    {
        if (pGeoData->x + X_player < pGeoData->obstacles[i] - 100)
        {
            break;
        }
        if (pGeoData->x + X_player > pGeoData->obstacles [i] + 100)
        {
            continue;
        }
        
        if (pGeoData->y_player < pGeoData->sol - 100) 
        {
            break;
        }

        if (pGeoData->id_obstacles [i] == 0)
        {
            continue;
        }
        else if (pGeoData->id_obstacles [i] == triangle)
        {
            if (pGeoData->y_player > pGeoData->sol - 90)
            {           
                printf("Mort 2 \n");
                pGeoData->isDead = 1;
            }

            continue;
        }
        else if (pGeoData->id_obstacles [i] == rectangle)
        {
            if (pGeoData->y_player < pGeoData->sol - 100)
            {
                continue;
            }

            if (pGeoData->y_player > pGeoData->sol - 70)
            {
                printf("Mort 1\n");
                pGeoData->isDead = 1;
                continue;
            }
            
            pGeoData->y_player = pGeoData->sol - 100;
            pGeoData->onGround = 1;
                
            if (pGeoData->vy_player > 0)
            {
                pGeoData->vy_player = 0;
            }
        }
    }

    al_draw_bitmap(pGeoData->image [2], -pGeoData->x % 3840, 0, 0);
    al_draw_bitmap(pGeoData->image [2], 3840 -pGeoData->x % 3840, 0, 0);

    char strValue[8] = "0000000";
    sprintf(strValue, "%d", pGeoData->score);
    al_draw_text(pGeoData->pFont50, al_map_rgb(0, 250, 0), 900, 100, 0, strValue);
    //al_draw_filled_circle(X_player, pGeoData->y_player, 5, al_map_rgb(0,255,0));

    for (int i = 0; i < 1000; ++i) 
    {
        if (pGeoData->obstacles [i] < pGeoData->x -500) 
        {
            continue;
        }
        
        if (pGeoData->obstacles [i] >= pGeoData->x + 2000) 
        {
            break;
        }
        
        if (pGeoData->id_obstacles [i] == 0)
        {
                continue;
        }
        else if (pGeoData->id_obstacles [i] == triangle) 
        {
            al_draw_filled_triangle(pGeoData->obstacles[i] - pGeoData->x, y_debut_player + 100, pGeoData->obstacles [i]  - pGeoData->x + 100, y_debut_player + 100, pGeoData->obstacles [i] - pGeoData->x + 50, y_debut_player, al_map_rgb(255, 0, 0));
        }
        else if (pGeoData->id_obstacles [i] == rectangle) 
        {
            al_draw_bitmap(pGeoData->image [3], pGeoData->obstacles[i] - pGeoData->x, y_debut_player, 0);
            //al_draw_filled_rectangle(pGeoData->obstacles[i] - pGeoData->x, y_debut_player, pGeoData->obstacles[i] - pGeoData->x + 100, y_debut_player + 100, al_map_rgb(100, 100, 100));
        }
    }

    //printf("py=%d\n", pGeoData->y_player);

    if (pGeoData->y_player >= pGeoData->sol) 
    {
        if (pGeoData->x + X_player >= pGeoData->obstacles[0])
        {
            printf("Mort 0 \n");
            pGeoData->isDead = 1;
        }
        else
        {
            pGeoData->y_player = pGeoData->sol;
            pGeoData->onGround = 1;
            
            if (pGeoData->vy_player > 0)
            {
                pGeoData->vy_player = 0;
            }
        }
    }

    //printf("py2=%d\n", pGeoData->y_player);

    al_draw_bitmap(pGeoData->image[0], X_player, pGeoData->y_player - 100, 0);

    pGeoData->x = pGeoData->x + pGeoData->vx;
}

void Geo_Destroy(PGAME _pGeoDash) {
    printf("Destruction du jeu...\n");

    free(_pGeoDash->gameData);
    _pGeoDash->gameData = NULL;
    *_pGeoDash->pCurrentGameId = GAME_MAP;
}

void GameGStateChecker(PGAME _pGeoDash)
{
    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;

    if (pGeoData->isDead)
    {
        pGeoData->isMenuEnable = 1;

        pGeoData->scores[pGeoData->playerCurrent] = pGeoData->score;
        
        if (++pGeoData->playerCurrent >= _pGeoDash->playersCount)
        {
            if (pGeoData->scores[0] > pGeoData->scores[1])
            {
                _pGeoDash->pPlayers[0]->tickets+=1;
            }
            else if (pGeoData->scores[0] < pGeoData->scores[1])
            {
                _pGeoDash->pPlayers[1]->tickets+=1;
            }
            else
            {
                _pGeoDash->pPlayers[0]->tickets+=1;
                _pGeoDash->pPlayers[1]->tickets+=1;
            }
            //printf("P0ticket=%d\n", _pGeoDash->pPlayers[0]->tickets);
            //printf("P1ticket=%d\n", _pGeoDash->pPlayers[1]->tickets);
            //DarkPiano_Destroy(_pGeoDash);
            return;
        }

        pGeoData->ay_player = 1;
        pGeoData->vy_player = 0;
        pGeoData->y_player = y_debut_player;
        pGeoData->sol = 1000;
        pGeoData->x = 0;
        pGeoData->vx = 6;
        pGeoData->x_fond = 0;
        pGeoData->timer = 0;
        pGeoData->onGround = 0;
        
        pGeoData->isDead = 0;
        pGeoData->score = 0;

        for (int i = 0; i < 1000; ++i) 
        {
            pGeoData->obstacles [i] = i*100 + 2000;
        }

        pGeoData->click = 0;
        int newType = 0;
        int count = 0;

        for (int i = 0; i < 1000; ++i) 
        {
            newType = rand()%3;

            if (newType != rectangle)
            {
                if (++count > 3)
                {
                    newType = rectangle;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
            
            pGeoData->id_obstacles [i] = newType;
        }

        pGeoData->id_obstacles [0] = rectangle;
        
        //printf("Player = %d\n", pGeoData->playerCurrent);
        //printf("ticket=%d\n", _pGeoDash->pPlayers[pGeoData->playerCurrent]->tickets);
    }
    
}

void MenuG_UpdateEvent(PGAME _pGeoDash)
{
    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;
    
    if (_pGeoDash->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        int boutton_X = 720;
        int boutton_Y = 450;
        
        if (_pGeoDash->pEvent->mouse.x > boutton_X && _pGeoDash->pEvent->mouse.x < boutton_X+al_get_bitmap_width(pGeoData->buttonPlay) && _pGeoDash->pEvent->mouse.y > boutton_Y && _pGeoDash->pEvent->mouse.y < boutton_Y+al_get_bitmap_height(pGeoData->buttonPlay))
        {
            if (pGeoData->playerCurrent <= 1)
            {
                pGeoData->isMenuEnable = 0;
            }
            else
            {
                Geo_Destroy(_pGeoDash);
                return;
            }
        }   
    }
}

void MenuG_Draw(PGAME _pGeoDash)
{
    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;
    
    al_draw_bitmap(pGeoData->menubk, 0, 0, 0);
    
    int boutton_X = 720;
    int boutton_Y = 450;

    if (pGeoData->playerCurrent <= 1)
    {    
        al_draw_bitmap(pGeoData->buttonPlay, boutton_X, boutton_Y, 0);
    }
    else
    {
        al_draw_bitmap(pGeoData->buttonMap, boutton_X, boutton_Y, 0);
    }
    
    al_draw_text(pGeoData->pFont50, al_map_rgb(0, 255, 0), 200, 200, 0, _pGeoDash->pPlayers[0]->name);
    al_draw_text(pGeoData->pFont50, al_map_rgb(255, 0, 0), 1650, 200, 0, _pGeoDash->pPlayers[1]->name);

    char strValue[8] = "0000000";
    sprintf(strValue, "%d", pGeoData->scores[0]);
    al_draw_text(pGeoData->pFont50, al_map_rgb(200, 200, 0), 200, 250, 0, strValue);
    sprintf(strValue, "%d", pGeoData->scores[1]);
    al_draw_text(pGeoData->pFont50, al_map_rgb(200, 200, 0), 1650, 250, 0, strValue);

    sprintf(strValue, "%d", _pGeoDash->pPlayers[0]->tickets);
    al_draw_text(pGeoData->pFont50, al_map_rgb(200, 200, 0), 200, 300, 0, strValue);
    sprintf(strValue, "%d", _pGeoDash->pPlayers[1]->tickets);
    al_draw_text(pGeoData->pFont50, al_map_rgb(200, 200, 0), 1650, 300, 0, strValue);

    //al_draw_rectangle(boutton_X, boutton_Y, boutton_X+al_get_bitmap_width(pGeoData->buttonPlay), boutton_Y+al_get_bitmap_height(pGeoData->buttonPlay), al_map_rgb(255, 0, 0), 5);
}
