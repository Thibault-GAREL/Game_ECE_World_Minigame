#include "PAC.h"

void PAC_Create(PGAME _pPAC)
{
    printf("Creation du jeu...\n");

    int* gameData = (int*)malloc(sizeof(int) * 2);
    gameData[0] = 0;
    gameData[1] = 0;
    _pPAC->gameData = gameData;

    printf("Jeu cree!\n");
}

void PAC_Update(PGAME _pPAC)
{
    printf("Exemple de fonction Update...\n");

    if (_pPAC->gameData == NULL)
    {
        PAC_Create(_pPAC);
    }

    int* gameData = _pPAC->gameData;

    printf("%d\n", gameData[0]++);

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

    int* gameData = _pPAC->gameData;

    printf("%d\n", gameData[1]++);

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

pGameData InitDuck (){
    pGameData pPAC = malloc(sizeof (GameData));

    for (int i = 0; i <DuckCount ; ++i) {
        pPAC->DuckInfos[i]->IsDuckFished = false;
    }
    pPAC = PAC_Coordinates_create(pPAC);

    return pPAC;
}

pGameData PAC_Coordinates_create(pGameData gamedata){
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

    return gamedata;
}

