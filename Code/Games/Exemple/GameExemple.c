#include "GameExemple.h"

void Exemple_Create(PGAME _pExemple)
{
    printf("Creation du jeu...\n");

    int* gameData = (int*)malloc(sizeof(int) * 2);
    gameData[0] = 0;
    gameData[1] = 0;
    _pExemple->gameData = gameData;

    printf("Jeu cree!\n");
}

void Exemple_Update(PGAME _pExemple)
{
    printf("Exemple de fonction Update...\n");
    
    if (_pExemple->gameData == NULL)
    {
        Exemple_Create(_pExemple);
    }

    int* gameData = _pExemple->gameData;

    printf("%d\n", gameData[0]++);

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        Exemple_Destroy(_pExemple);
    }
    
    printf("\n");
}

void Exemple_TimedUpdate(PGAME _pExemple)
{
    printf("Exemple de fonction TimedUpdate...\n");

    int* gameData = _pExemple->gameData;

    printf("%d\n", gameData[1]++);

    printf("\n");
}

void Exemple_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    free(_pExemple->gameData);
    _pExemple->gameData = NULL;

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}

