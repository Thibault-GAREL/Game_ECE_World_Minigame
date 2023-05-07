//
// Created by garel on 06/05/2023.
//


#include "GeometryDash.h"

void Geo_Create(PGAME _pGeoDash)
{
    GeoData * pGeoData = (GeoData *) malloc (sizeof (GeoData));
    _pGeoDash->gameData = pGeoData;

    pGeoData->image[0] = al_load_bitmap(PATH "\\Textures\\GeometryDash\\GDa.png");
    pGeoData->image[1] = al_load_bitmap(PATH "\\Textures\\TDLR\\boutonplay.png");


    pGeoData->ay_player = 1;
    pGeoData->vy_player = 0;
    pGeoData->y_player = y_debut_player;
    pGeoData->sol = 900;
    pGeoData->x_fond = 0;
    pGeoData->avancement_fond = -1;
    pGeoData->timer = 0;

    pGeoData->gamemode = 0;
    pGeoData->click = 0;


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

    if (pGeoData->gamemode == 0) {
        al_draw_bitmap(pGeoData->image [7], 0, 0, 0);
        if (Point_In_Rectangle(pGeoData->mouse_position, (Vector2D){816,800}, (Vector2D){1104,889}) == 1 && pGeoData->click==1)
        {
            pGeoData->gamemode=1;
            pGeoData->click=0;
        }
        //  tif (Point_In_Rectangle())
        al_draw_bitmap(pGeoData->image [1], 816, 800, 0);
    }
    else if (pGeoData->gamemode == 1) {
        //al_clear_to_color(al_map_rgb(200, 0, 0));
        pGeoData->vy_player = pGeoData ->vy_player + pGeoData ->ay_player;
        pGeoData->y_player = pGeoData ->y_player + pGeoData ->vy_player;


        if (pGeoData->y_player + 100 >= pGeoData->sol) {
            pGeoData->y_player = pGeoData->sol - 100;
        }

        pGeoData->timer ++;
        if (pGeoData->timer % 20 == 0){
            if (0.929411 <= al_get_pixel(pGeoData->image [7], ((-1) * pGeoData->x_fond) + X_player, pGeoData->y_player).r && al_get_pixel(pGeoData->image [7], ((-1) * pGeoData->x_fond) + X_player, pGeoData->y_player).r < 0.929413){
                printf("colision %d\n", pGeoData->timer);
            }
        }

        // printf("%f", al_map_rgb(237, 28, 36).r);
        //printf(" -- %d\n", pGeoData->x_fond);
        //printf("%f", al_get_pixel(pGeoData->image [6], pGeoData->x_fond * (-1) - 100, 500).b);      al_get_pixel(pGeoData->image [7], ((-1) * pGeoData->x_fond), pGeoData->y_player).r <= 0.929412

        al_draw_bitmap(pGeoData->image [7], pGeoData->x_fond, 0, 0);
        //al_draw_filled_rectangle(pGeoData->x_fond  + 800, y_debut_player, pGeoData->x_fond + 1000, y_debut_player + 100 ,al_map_rgb(0, 0, 18));
        //al_draw_bitmap(pGeoData->image[3], pGeoData->x_fond + 50,100,0);

        al_draw_bitmap(pGeoData ->image [0], X_player, pGeoData ->y_player, 0);
        pGeoData->x_fond = pGeoData->x_fond + pGeoData->avancement_fond;
        //al_draw_filled_triangle();

    }
    else if (pGeoData->gamemode == 2) {

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
