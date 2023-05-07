//
// Created by garel on 06/05/2023.
//


#include "GeometryDash.h"

void Geo_Create(PGAME _pGeoDash)
{
    GeoData * pGeoData = (GeoData *) malloc (sizeof (GeoData));
    _pGeoDash->gameData = pGeoData;

    pGeoData->image [0] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\GDa.png");
    pGeoData->image [1] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\GD Map (Personnalisé).png");

    pGeoData->ay_player = 1;
    pGeoData->vy_player = 0;
    pGeoData->y_player = y_debut_player;
    pGeoData->sol = 900;
    pGeoData->x_fond = 500;
    pGeoData->avancement_fond = -1;
    pGeoData->timer = 0;

    pGeoData->gamemode = 1;


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

    if (Get_Touch(_pGeoDash->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0) && pGeoData->y_player == y_debut_player){  // attention au gamemode
        //printf("touche espace \n");
        pGeoData->vy_player = -20;
    }


    /*pGD_Gamedata GameData = _pGeoDash->gameData;

    if (Get_Touch(_pGeoDash->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){  // attention au gamemode
        GameData->Jump = 1;
    }
    if (GameData->JumpDuration == 20){
        GameData->Jump = -1;
    }*/
}

void Geo_TimedUpdate(PGAME _pGeoDash) {

    GeoData * pGeoData = (GeoData *) _pGeoDash->gameData;

    if (pGeoData->gamemode = 0) {
        //pGeoData->gamemode = 1;
    }
    else if (pGeoData->gamemode = 1) {
        al_clear_to_color(al_map_rgb(200, 0, 0));
        pGeoData->vy_player = pGeoData ->vy_player + pGeoData ->ay_player;
        pGeoData->y_player = pGeoData ->y_player + pGeoData ->vy_player;


        if (pGeoData->y_player + 100 >= pGeoData->sol) {
            pGeoData->y_player = pGeoData->sol - 100;
        }

        pGeoData->timer ++;
        if (pGeoData->timer % 20 == 0){
            if (al_get_pixel(pGeoData->image [1], X_player + 100, pGeoData->y_player).b > al_map_rgb(0, 0,161).b){
                printf("colision\n");
            }
        }



        al_draw_bitmap(pGeoData->image [1], pGeoData->x_fond, 0, 0);

        al_draw_bitmap(pGeoData ->image [0], X_player, pGeoData ->y_player, 0);
        pGeoData->x_fond = pGeoData->x_fond + pGeoData->avancement_fond;
        //al_draw_filled_triangle();

    }

    /*pGD_Gamedata gameData = _pGeoDash->gameData;

    gameData->vy += gameData->Gravity;

    gameData->y += gameData->vy;

    if (gameData->y >400){
        gameData->y = 400;
        gameData->vy = 0;
        gameData->Jump = 0;
        gameData->JumpDuration = 0;
    }
    if (gameData->vy > 50){
        gameData->vy = 50;
    }

    if (gameData->Jump == 1){
        gameData->JumpDuration++;
        gameData->vy = gameData->Velocity;
    }
    if (gameData->Jump == -1){
        gameData->JumpDuration++;
        gameData->vy = -gameData->Velocity;
    }
    al_draw_bitmap(gameData->GDTextures[0],X_player, gameData->y,0);*/
}

void Geo_Destroy(PGAME _pGeoDash) {
    printf("Destruction du jeu...\n");

    free(_pGeoDash->gameData);
    _pGeoDash->gameData = NULL;
    *_pGeoDash->pCurrentGameId = GAME_MAP;
}
