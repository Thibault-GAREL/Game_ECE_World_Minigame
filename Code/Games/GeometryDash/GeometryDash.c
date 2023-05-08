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
    pGeoData->image [3] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\img.png");


    pGeoData->ay_player = 1;
    pGeoData->vy_player = 0;
    pGeoData->y_player = y_debut_player;
    pGeoData->sol = 1000;
    pGeoData->x = 0;
    pGeoData->vx = 6;
    pGeoData->x_fond = 0;
    pGeoData->timer = 0;
    pGeoData->onGround = 0;

    pGeoData->gamemode = 0;
    pGeoData->click = 0;

    pGeoData->x_triangle1 = 700;

    pGeoData->x_rectangle1 = 1000;

    for (int i = 0; i < 1000; ++i) {
        pGeoData->obstacles [i] = i*200 + 2000;
    }
    for (int i = 0; i < 1000; ++i) {
        pGeoData->id_obstacles [i] = rand()%2+1;
    }

    /*pGD_Gamedata GameData = malloc(sizeof(GD_Gamedata));

    _pGeoDash->gameData = GameData;

    GameData ->GDTextures[0] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\GDa.png");

    GameData->Jump = 0;
    GameData->Velocity = -10;
    GameData->Gravity = 0.5;
    GameData->y = 400;
    GameData->JumpDuration = 0;*/
}


void Geo_Update(PGAME _pGeoDash){

    if (_pGeoDash->gameData == NULL)
    {
        Geo_Create(_pGeoDash);
    }

    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;

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

    if (Get_Touch(_pGeoDash->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){  // attention au gamemode
        printf("touche espace \n");

        if (pGeoData->onGround)
        {
            pGeoData->vy_player = -20;
        }
    }

   
}

void Geo_TimedUpdate(PGAME _pGeoDash) {

    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;

    if (pGeoData->gamemode == 0) {
        al_draw_bitmap(pGeoData->image [2], 0, 0, 0);
        if (Point_In_Rectangle(pGeoData->mouse_position, (Vector2D){816,800}, (Vector2D){1104,889}) == 1 && pGeoData->click==1)
        {
            pGeoData->gamemode=1;
            pGeoData->click=0;
        }
        //  tif (Point_In_Rectangle())
        al_draw_bitmap(pGeoData->image [1], 816, 800, 0);
    }
    else if (pGeoData->gamemode == 1) {
        

        pGeoData->vy_player += pGeoData ->ay_player;
        pGeoData->y_player += pGeoData ->vy_player;

        for (int i = 0; i < 1000; ++i) {

            if (pGeoData->obstacles [i] < pGeoData->x + X_player && pGeoData->x + X_player <= pGeoData->obstacles [i] + 100){
                if (pGeoData->y_player < pGeoData->sol - 100) {
                    break;
                }
                if (pGeoData->id_obstacles [i] == triangle){
                    printf("Mort !!!! \n");
                    break;
                }
                else if (pGeoData->id_obstacles [i] == rectangle){
                    printf("Rectangle\n");
                    if (y_debut_player < pGeoData->y_player && pGeoData->y_player <= y_debut_player + 10){
                        pGeoData->y_player = y_debut_player;
                    }
                    break;
                }
                break;
            }
        }

        al_draw_bitmap(pGeoData->image [2], pGeoData->x_fond - pGeoData->x, 0, 0);

        for (int i = 0; i < 1000; ++i) {
            if (pGeoData->obstacles [i] < pGeoData->x -500) {
                continue;
            }
            if (pGeoData->obstacles [i] >= pGeoData->x + 2000) {
                break;
            }
            if (pGeoData->id_obstacles [i] == triangle) {
                al_draw_filled_triangle(pGeoData->x * (-1) + pGeoData->obstacles [i], y_debut_player + 100, pGeoData->x * (-1) + pGeoData->obstacles [i] + 100, y_debut_player + 100, pGeoData->x* (-1) + pGeoData->obstacles [i] + 50, y_debut_player,
                                        al_map_rgb(255, 0, 0));
            }
            else if (pGeoData->id_obstacles [i] == rectangle) {
                al_draw_filled_rectangle(pGeoData->x* (-1) + pGeoData->obstacles [i], y_debut_player, pGeoData->x * (-1) + pGeoData->obstacles [i] + 100, y_debut_player + 100,
                                         al_map_rgb(0, 0, 255));
            }
        }

        //printf("py=%d\n", pGeoData->y_player);

        if (pGeoData->y_player >= pGeoData->sol) 
        {
            pGeoData->y_player = pGeoData->sol;
            pGeoData->onGround = 1;
            
            if (pGeoData->vy_player > 0)
            {
                pGeoData->vy_player = 0;
            }
        }
        else
        {
            pGeoData->onGround = 0;
        }
        

        //printf("py2=%d\n", pGeoData->y_player);


        al_draw_bitmap(pGeoData->image[0], X_player, pGeoData->y_player - 100, 0);

        pGeoData->x = pGeoData->x + pGeoData->vx;
    }
    else if (pGeoData->gamemode == 2) 
    {

    }
    else if (pGeoData->gamemode == 3) 
    {
        Geo_Destroy(_pGeoDash);
    }
}

void Geo_Destroy(PGAME _pGeoDash) {
    printf("Destruction du jeu...\n");

    free(_pGeoDash->gameData);
    _pGeoDash->gameData = NULL;
    *_pGeoDash->pCurrentGameId = GAME_MAP;
}
