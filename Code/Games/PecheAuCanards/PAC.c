#include "PAC.h"

void PAC_Create(PGAME _pPAC)
{
    pPacGameData pPAC = malloc(sizeof (pPacGameData));

    _pPAC->gameData = pPAC;

    pPAC->DuckTextures[0] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[1] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2.png");
    pPAC->DuckTextures[2] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[3] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2.png");
    pPAC->DuckTextures[4] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[5] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[6] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_2.png");
    pPAC->DuckTextures[7] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[8] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[9] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[10] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[11] = al_load_bitmap("..\\Textures/PAC/Spaceship_texture_3.png");

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

    InitDuck(_pPAC);

    _pPAC->gameData = pPAC;     //envoi des données du jeu dans la structure globale
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
}

void InitDuck (PGAME _pPAC){
    pPacGameData gamedata = _pPAC->gameData;

    PAC_Coordinates_create(_pPAC);

}

void PAC_Coordinates_create(PGAME _pPAC){

    srand(time(NULL));

    pPacGameData gamedata = _pPAC->gameData;

    gamedata->DuckInfos[0]->x = 300;
    gamedata->DuckInfos[1]->x = 425;
    gamedata->DuckInfos[2]->x = 550;
    gamedata->DuckInfos[3]->x = 675;
    gamedata->DuckInfos[4]->x = 800;
    gamedata->DuckInfos[5]->x = 925;
    gamedata->DuckInfos[6]->x = 1050;
    gamedata->DuckInfos[7]->x = 1175;
    gamedata->DuckInfos[8]->x = 1300;
    gamedata->DuckInfos[9]->x = 1425;
    gamedata->DuckInfos[10]->x = 1550;
    gamedata->DuckInfos[11]->x = 1675;

    gamedata->DuckInfos[0]->y = 900 + (rand() % 25);
    gamedata->DuckInfos[1]->y = 840 + (rand() % 25);
    gamedata->DuckInfos[2]->y = 780 + (rand() % 25);
    gamedata->DuckInfos[3]->y = 720 + (rand() % 25);
    gamedata->DuckInfos[4]->y = 660 + (rand() % 25);
    gamedata->DuckInfos[5]->y = 600 + (rand() % 25);
    gamedata->DuckInfos[6]->y = 540 + (rand() % 25);
    gamedata->DuckInfos[7]->y = 480 + (rand() % 25);
    gamedata->DuckInfos[8]->y = 420 + (rand() % 25);
    gamedata->DuckInfos[9]->y = 360 + (rand() % 25);
    gamedata->DuckInfos[10]->y = 300 + (rand() % 25);
    gamedata->DuckInfos[11]->y = 240 + (rand() % 25);

    for (int SpeedInit = 0; SpeedInit < DuckCount ; SpeedInit++){
        gamedata->DuckInfos[SpeedInit]->vx = (rand() % MaxDuckSpeed);
        gamedata->DuckInfos[SpeedInit]->vy = (rand() % MaxDuckSpeed);
    }
}

void Check_Duck_Colisions(PGAME _pPAC){

    pPacGameData gamedata = _pPAC->gameData;

    for (int i = 0; i < DuckCount-1; i++){
        if (Point_In_Rectangle((Vector2D){gamedata->DuckInfos[i]->x,gamedata->DuckInfos[i]->y}, (Vector2D){gamedata->DuckInfos[i+1]->x,gamedata->DuckInfos[i+1]->y}, (Vector2D){gamedata->DuckInfos[i+1]->x,gamedata->DuckInfos[i+1]->y}))
        {
            gamedata->DuckInfos[i]->vx*=-1;
            gamedata->DuckInfos[i]->vy*=-1;
            gamedata->DuckInfos[i+1]->vx*=-1;
            gamedata->DuckInfos[i+1]->vy*=-1;
        }
        else {
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

    ALLEGRO_DISPLAY * display = al_get_current_display();

    al_draw_bitmap(gameData->DuckTextures[1],50,50,0);

    //Check_Duck_Colisions(gameData);

}


void PAC_Destroy(PGAME _pPAC)
{
    printf("Destruction du jeu...\n");

    free(_pPAC->gameData);
    _pPAC->gameData = NULL;

    printf("Jeu detruit\n");

    *_pPAC->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}



//release 24/04/23
