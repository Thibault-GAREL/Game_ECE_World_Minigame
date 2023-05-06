//
// Created by garel on 06/05/2023.
//

#include "Geometrie_dash.h"


void Geo_Create(PGAME _pExemple){

    GeoData * pGeoData = (GeoData *) malloc (sizeof (GeoData));
    _pExemple->gameData = pGeoData;

    pGeoData ->image [0] = al_load_bitmap(PATH "\\Textures\\Geometrie_dash\\GDa.png");

    pGeoData ->ay_player = -3;
    pGeoData ->vy_player = 0;
    pGeoData ->y_player = 0;
}

void Geo_Update(PGAME _pExemple){
    GeoData * pGeoData = (GeoData *) _pExemple->gameData;

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){  // attention au gamemode
        //printf("touche espace \n");

    }
}

void Geo_TimedUpdate(PGAME _pExemple) {
    GeoData * pGeoData = (GeoData *) _pExemple->gameData;
    pGeoData ->vy_player = pGeoData ->vy_player + pGeoData ->ay_player;
    pGeoData ->y_player = pGeoData ->y_player + pGeoData ->vy_player;

    al_draw_bitmap(pGeoData ->image [0], X_player, pGeoData ->y_player, 0);


}

void Geo_Destroy(PGAME _pExemple) {
    printf("Destruction du jeu...\n");

    free(_pExemple->gameData);
    _pExemple->gameData = NULL;
    *_pExemple->pCurrentGameId = GAME_MAP;
}
