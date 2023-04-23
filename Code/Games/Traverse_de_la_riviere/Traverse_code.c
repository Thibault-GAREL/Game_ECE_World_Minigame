//
// Created by garel on 20/04/2023.
//

#include "Traverse_code.h"

void ajouterfinLSC (Maillion** p, int numero){
    Maillion* new = malloc (sizeof (Maillion));
    new->numero = numero;
    if (*p = NULL){
        *p = new;
    }
    else {
        new->next = *p;
    }
}

void liberation (Maillion** m){
    if (*m = NULL){
        return;
    }
    liberation(&((*m)->next));
    free (*m);
    *m = NULL;
}

void TDLR_Create(PGAME _pExemple)
{
    /*printf("Creation du jeu...\n");

    int* gameData = (int*)malloc(sizeof(int) * 2);
    gameData[0] = 0;
    gameData[1] = 0;
    _pExemple->gameData = gameData;*/

    GameData* pGameData = malloc(sizeof (GameData));
    _pExemple->gameData = pGameData;
    pGameData->image [0] = al_load_bitmap(PATH "\\Textures\\TDLR\\vache2.jpg");

    pGameData->liste = NULL;
    ajouterfinLSC(&(pGameData->liste), 1);      //Ici ajouter les première zone sans obstacles


    printf("Jeu cree!\n");
}

void TDLR_Update(PGAME _pExemple)
{
    //printf("Exemple de fonction Update...\n");

    if (_pExemple->gameData == NULL)  //voir si le programme est lancé
    {
        TDLR_Create(_pExemple);
    }

    //int* gameData = _pExemple->gameData;
    //printf("%d\n", gameData[0]++);

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        TDLR_Destroy(_pExemple);
    }
    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){
        printf("touche espace");

    }

    /////////////////////////////ajouterfinLSC(&(pGameData->liste), 1); // ajouter au fur et à mesure des maillions AVEC obstacles
}

void TDLR_TimedUpdate(PGAME _pExemple) //dessin + Timer dans cette fonction
{
    GameData* pGameData = _pExemple->gameData;
    al_draw_bitmap(pGameData->image [0], 0, 0, 0);

}

void TDLR_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    GameData* pGameData = _pExemple->gameData;
    liberation(&(pGameData->liste));

    free(_pExemple->gameData); //Pour chaque structure / allocation
    _pExemple->gameData = NULL;

    //Ne pas oublier de destroy

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}


