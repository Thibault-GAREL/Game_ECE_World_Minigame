#include "PAC.h"

void PAC_Create(PGAME _pPAC)
{
    pPacGameData pPAC = malloc(sizeof (pPacGameData));

    pPAC->DuckTextures[0] = al_load_bitmap("Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[1] = al_load_bitmap("Textures/PAC/Spaceship_texture_2.png");
    pPAC->DuckTextures[2] = al_load_bitmap("Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[3] = al_load_bitmap("Textures/PAC/Spaceship_texture_2.png");
    pPAC->DuckTextures[4] = al_load_bitmap("Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[5] = al_load_bitmap("Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[6] = al_load_bitmap("Textures/PAC/Spaceship_texture_2.png");
    pPAC->DuckTextures[7] = al_load_bitmap("Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[8] = al_load_bitmap("Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[9] = al_load_bitmap("Textures/PAC/Spaceship_texture_1.png");
    pPAC->DuckTextures[10] = al_load_bitmap("Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[11] = al_load_bitmap("Textures/PAC/Spaceship_texture_3.png");
    pPAC->DuckTextures[12] = al_load_bitmap("Textures/PAC/Spaceship_texture_EasterEgg.png");
    InitDuck(pPAC);

    _pPAC->gameData = pPAC;     //envoi des données du jeu dans la structure globale
}

void PAC_Update(PGAME _pPAC)
{
    printf("Exemple de fonction Update...\n");

    if (_pPAC->gameData == NULL)
    {
        PAC_Create(_pPAC);
    }

    pPacGameData gameData = _pPAC->gameData;

    if (Get_Touch(_pPAC->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        PAC_Destroy(_pPAC);
    }

    printf("\n");
}

void PAC_TimedUpdate(PGAME _pPAC)
{
    printf("Exemple de fonction TimedUpdate...\n");

    pPacGameData  gameData = _pPAC->gameData;

    Check_Duck_Colisions(gameData);


    printf("\n");
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

void InitDuck (pPacGameData pPAC){

    for (int i = 0; i <DuckCount ; ++i) {
        pPAC->DuckInfos[i]->IsDuckFished = false;
    }
    PAC_Coordinates_create(pPAC);
}

void PAC_Coordinates_create(pPacGameData gamedata){
    srand(time(NULL));

    gamedata->DuckInfos[0]->x = (rand() % MAX_POS_X) * DuckThreshold;
    gamedata->DuckInfos[0]->y = (rand() % MAX_POS_Y) * DuckThreshold;

    for (int x = 1; x < DuckCount; x++) {
        do {
            gamedata->DuckInfos[x]->x = (rand() % MAX_POS_X) * DuckThreshold;
        }while(gamedata->DuckInfos[x-1]->x < gamedata->DuckInfos[x]->x + DuckThreshold || gamedata->DuckInfos[x-1]->x > gamedata->DuckInfos[x]->x - DuckThreshold);
    }

    for (int y = 1; y < DuckCount ; y++) {
        do {
            gamedata->DuckInfos[y]->y = (rand() % MAX_POS_Y) * DuckThreshold;
        }while(gamedata->DuckInfos[y-1]->y < gamedata->DuckInfos[y]->y + DuckThreshold || gamedata->DuckInfos[y-1]->y > gamedata->DuckInfos[y]->y - DuckThreshold);
    }

    for (int SpeedInit = 0; SpeedInit < DuckCount ; SpeedInit++){
        gamedata->DuckInfos[SpeedInit]->vx = (rand() % MaxDuckSpeed);
        gamedata->DuckInfos[SpeedInit]->vy = (rand() % MaxDuckSpeed);
    }
}

void Check_Duck_Colisions(pPacGameData gamedata){

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

//release 24/04/23
