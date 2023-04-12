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

void Exemple_Update(PGAME _pPAC)
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

