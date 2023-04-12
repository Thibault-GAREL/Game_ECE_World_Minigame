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
    GameData *pPAC = malloc(sizeof (GameData));

    pPAC->pDuckInfo1->IsDuckFished = false;
    pPAC->pDuckInfo2->IsDuckFished = false;
    pPAC->pDuckInfo3->IsDuckFished = false;
    pPAC->pDuckInfo4->IsDuckFished = false;
    pPAC->pDuckInfo5->IsDuckFished = false;
    pPAC->pDuckInfo6->IsDuckFished = false;
    pPAC->pDuckInfo7->IsDuckFished = false;
    pPAC->pDuckInfo8->IsDuckFished = false;
    pPAC->pDuckInfo9->IsDuckFished = false;
    pPAC->pDuckInfo10->IsDuckFished = false;
    pPAC->pDuckInfo11->IsDuckFished = false;
    pPAC->pDuckInfo12->IsDuckFished = false;

    pPAC->pDuckInfo1->x = srand()
}