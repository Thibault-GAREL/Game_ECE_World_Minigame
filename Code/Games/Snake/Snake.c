#include "Snake.h"

/*
gcc -g -Wall *.c .\Utils\*.c .\Games\Exemple\*.c .\Games\Snake\*.c -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf -lallegro_acodec -lallegro_audio  -oExemple
*/

void Snake_Create(PGAME _pSnake)
{
    printf("Creation du jeu...\n");

    int* gameData = (int*)malloc(sizeof(int) * 2);
    gameData[0] = 0;
    gameData[1] = 0;
    _pSnake->gameData = gameData;

    printf("Jeu cree!\n");
}

void Snake_Update(PGAME _pSnake)
{
    printf("Exemple de fonction Update...\n");
    
    if (_pSnake->gameData == NULL)
    {
        Snake_Create(_pSnake);
    }

    int* gameData = _pSnake->gameData;

    printf("%d\n", gameData[0]++);

    if (Get_Touch(_pSnake->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        Snake_Destroy(_pSnake);
    }
    
    printf("\n");
}

void Snake_TimedUpdate(PGAME _pSnake)
{
    printf("Exemple de fonction TimedUpdate...\n");

    int* gameData = _pSnake->gameData;

    printf("%d\n", gameData[1]++);

    printf("\n");
}

void Snake_Destroy(PGAME _pSnake)
{
    printf("Destruction du jeu...\n");

    free(_pSnake->gameData);
    _pSnake->gameData = NULL;

    printf("Jeu detruit\n");

    *_pSnake->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}

