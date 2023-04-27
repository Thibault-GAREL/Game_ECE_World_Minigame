#include "PAC.h"
int Collisions = 0;

void PAC_Create(PGAME _pPAC)
{
    pPacGameData pPAC = malloc(sizeof (PacGameData));

    _pPAC->gameData = pPAC;

    pPAC->DuckTextures[0] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    pPAC->DuckTextures[1] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2 (Personnalisé).png");
    pPAC->DuckTextures[2] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");
    pPAC->DuckTextures[3] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2 (Personnalisé).png");
    pPAC->DuckTextures[4] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    pPAC->DuckTextures[5] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");
    pPAC->DuckTextures[6] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2 (Personnalisé).png");
    pPAC->DuckTextures[7] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    pPAC->DuckTextures[8] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    pPAC->DuckTextures[9] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1 (Personnalisé).png");
    pPAC->DuckTextures[10] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");
    pPAC->DuckTextures[11] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3 (Personnalisé).png");

    pPAC->Fishingstate[0] = 0;
    pPAC->Fishingstate[1] = 0;
    pPAC->Fishingstate[2] = 0;
    pPAC->Fishingstate[3] = 0;
    pPAC->Fishingstate[4] = 0;
    pPAC->Fishingstate[5] = 0;
    pPAC->Fishingstate[6] = 0;
    pPAC->Fishingstate[7] = 0;
    pPAC->Fishingstate[8] = 0;
    pPAC->Fishingstate[9] = 0;
    pPAC->Fishingstate[10] = 0;
    pPAC->Fishingstate[11] = 0;

    pPAC->DuckInfos[0] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[1] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[2] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[3] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[4] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[5] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[6] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[7] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[8] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[9] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[10] = malloc(sizeof (DuckInfos));
    pPAC->DuckInfos[11] = malloc(sizeof (DuckInfos));

    PAC_Coordinates_create(_pPAC);
}

void PAC_Update(PGAME _pPAC)
{

    if (_pPAC->gameData == NULL)
    {
        PAC_Create(_pPAC);
    }

    pPacGameData gameData = _pPAC->gameData;

    if (_pPAC->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        gameData->mouse.x = _pPAC->pEvent->mouse.x*1;
        gameData->mouse.y = _pPAC->pEvent->mouse.y*1;
    }
    if ( _pPAC->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        gameData->click=1;
    }
    if (_pPAC->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        gameData->click=0;
    }
    if (Get_Touch( _pPAC->pEvent, ALLEGRO_KEY_W,0,0,1,0)){
        PAC_Destroy(_pPAC);
    }
}

void PAC_Coordinates_create(PGAME _pPAC){

    srand(time(NULL));

    pPacGameData gamedata = _pPAC->gameData;


    for (int i = 0; i < 12; i++)
    {
        gamedata->DuckInfos[i]->vx = rand() % 3+1;
        gamedata->DuckInfos[i]->vy = rand() % 3+1;
    }

    for (int i = 0; i < 6; ++i) {
        gamedata->DuckInfos[i]->x = 200*(i+1);
        gamedata->DuckInfos[i]->y = 400;
    }
    for (int i = 6; i < 12; ++i) {
        gamedata->DuckInfos[i]->x = 200*(i-5);
        gamedata->DuckInfos[i]->y = 800;
    }

}

void Check_Duck_Colisions(PGAME _pPAC){

    pPacGameData gamedata = _pPAC->gameData;

    for (int i = 0; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x,gamedata->DuckInfos[i]->y}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                gamedata->DuckInfos[i]->vx*=-1;
                gamedata->DuckInfos[i]->vy*=-1;
                gamedata->DuckInfos[i]->x +=(gamedata->DuckInfos[i]->vx)*2;
                gamedata->DuckInfos[i]->y +=(gamedata->DuckInfos[i]->vy)*2;
                gamedata->DuckInfos[j]->vx*=-1;
                gamedata->DuckInfos[j]->vy*=-1;
                gamedata->DuckInfos[j]->x +=(gamedata->DuckInfos[j]->vx)*2;
                gamedata->DuckInfos[j]->y +=(gamedata->DuckInfos[j]->vy)*2;
            }
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x + al_get_bitmap_width(gamedata->DuckTextures[i]),gamedata->DuckInfos[i]->y}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                gamedata->DuckInfos[i]->vx*=-1;
                gamedata->DuckInfos[i]->vy*=-1;
                gamedata->DuckInfos[i]->x +=(gamedata->DuckInfos[i]->vx)*2;
                gamedata->DuckInfos[i]->y +=(gamedata->DuckInfos[i]->vy)*2;
                gamedata->DuckInfos[j]->vx*=-1;
                gamedata->DuckInfos[j]->vy*=-1;
                gamedata->DuckInfos[j]->x +=(gamedata->DuckInfos[j]->vx)*2;
                gamedata->DuckInfos[j]->y +=(gamedata->DuckInfos[j]->vy)*2;
            }
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x,gamedata->DuckInfos[i]->y+ al_get_bitmap_height(gamedata->DuckTextures[i])}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                gamedata->DuckInfos[i]->vx*=-1;
                gamedata->DuckInfos[i]->vy*=-1;
                gamedata->DuckInfos[i]->x +=(gamedata->DuckInfos[i]->vx)*2;
                gamedata->DuckInfos[i]->y +=(gamedata->DuckInfos[i]->vy)*2;
                gamedata->DuckInfos[j]->vx*=-1;
                gamedata->DuckInfos[j]->vy*=-1;
                gamedata->DuckInfos[j]->x +=(gamedata->DuckInfos[j]->vx)*2;
                gamedata->DuckInfos[j]->y +=(gamedata->DuckInfos[j]->vy)*2;
            }
            if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x + al_get_bitmap_width(gamedata->DuckTextures[i]),gamedata->DuckInfos[i]->y+ al_get_bitmap_height(gamedata->DuckTextures[i])}, (Vector2D){gamedata->DuckInfos[j]->x ,gamedata->DuckInfos[j]->y }, (Vector2D){gamedata->DuckInfos[j]->x + al_get_bitmap_width(gamedata->DuckTextures[j]),gamedata->DuckInfos[j]->y+al_get_bitmap_height(gamedata->DuckTextures[j])}))
            {
                gamedata->DuckInfos[i]->vx*=-1;
                gamedata->DuckInfos[i]->vy*=-1;
                gamedata->DuckInfos[i]->x +=(gamedata->DuckInfos[i]->vx)*2;
                gamedata->DuckInfos[i]->y +=(gamedata->DuckInfos[i]->vy)*2;
                gamedata->DuckInfos[j]->vx*=-1;
                gamedata->DuckInfos[j]->vy*=-1;
                gamedata->DuckInfos[j]->x +=(gamedata->DuckInfos[j]->vx)*2;
                gamedata->DuckInfos[j]->y +=(gamedata->DuckInfos[j]->vy)*2;
            }

        }
    }


    for (int i = 0; i < 11; i++){
        if(gamedata->DuckInfos[i]->y <= 0 || gamedata->DuckInfos[i]->y >= 1080){

            gamedata->DuckInfos[i]->vy*=-1;
            gamedata->DuckInfos[i]->y +=gamedata->DuckInfos[i]->vy;
        }
        if(gamedata->DuckInfos[i]->x <= 0 || gamedata->DuckInfos[i]->x >= 1920){
            gamedata->DuckInfos[i]->vx*=-1;
            gamedata->DuckInfos[i]->x +=gamedata->DuckInfos[i]->vx;
        }
        else{
            gamedata->DuckInfos[i]->x += gamedata->DuckInfos[i]->vx;
            gamedata->DuckInfos[i]->y += gamedata->DuckInfos[i]->vy;

            gamedata->DuckInfos[i+1]->x += gamedata->DuckInfos[i+1]->vx;
            gamedata->DuckInfos[i+1]->y += gamedata->DuckInfos[i+1]->vy;
        }
    }
}

void PAC_TimedUpdate(PGAME _pPAC)
{
    printf("Exemple de fonction TimedUpdate...\n");

    pPacGameData gameData = _pPAC->gameData;

    //ALLEGRO_DISPLAY * display = al_get_current_display();

    al_draw_bitmap(gameData->DuckTextures[0],gameData->DuckInfos[0]->x,gameData->DuckInfos[0]->y,0);
    al_draw_bitmap(gameData->DuckTextures[1],gameData->DuckInfos[1]->x,gameData->DuckInfos[1]->y,0);
    al_draw_bitmap(gameData->DuckTextures[2],gameData->DuckInfos[2]->x,gameData->DuckInfos[2]->y,0);
    al_draw_bitmap(gameData->DuckTextures[3],gameData->DuckInfos[3]->x,gameData->DuckInfos[3]->y,0);
    al_draw_bitmap(gameData->DuckTextures[4],gameData->DuckInfos[4]->x,gameData->DuckInfos[4]->y,0);
    al_draw_bitmap(gameData->DuckTextures[5],gameData->DuckInfos[5]->x,gameData->DuckInfos[5]->y,0);
    al_draw_bitmap(gameData->DuckTextures[6],gameData->DuckInfos[6]->x,gameData->DuckInfos[6]->y,0);
    al_draw_bitmap(gameData->DuckTextures[7],gameData->DuckInfos[7]->x,gameData->DuckInfos[7]->y,0);
    al_draw_bitmap(gameData->DuckTextures[8],gameData->DuckInfos[8]->x,gameData->DuckInfos[8]->y,0);
    al_draw_bitmap(gameData->DuckTextures[9],gameData->DuckInfos[9]->x,gameData->DuckInfos[9]->y,0);
    al_draw_bitmap(gameData->DuckTextures[10],gameData->DuckInfos[10]->x,gameData->DuckInfos[10]->y,0);
    al_draw_bitmap(gameData->DuckTextures[11],gameData->DuckInfos[11]->x,gameData->DuckInfos[11]->y,0);

    Check_Duck_Colisions(_pPAC);
}

void PAC_Destroy(PGAME _pPAC)
{
    printf("Destruction du jeu...\n");

    pPacGameData pPAC = _pPAC->gameData;

    for (int i = 0; i < 12; ++i) {
        al_destroy_bitmap(pPAC->DuckTextures[i]);
        free(pPAC->DuckInfos[i]);
    }

    free(_pPAC->gameData);
    _pPAC->gameData = NULL;

    printf("Jeu detruit\n");

    *_pPAC->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}