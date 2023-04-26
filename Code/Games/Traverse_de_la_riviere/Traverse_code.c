//
// Created by garel on 20/04/2023.
//

#include "Traverse_code.h"

/*void ajouterfinLSC (Maillion** p, int numero){
    Maillion* new = malloc (sizeof (Maillion));
    new->numero = numero;
    if (*p = NULL){
        *p = new;
    }
    else {
        new->next = *p;
    }
}

void afficherLSC (Maillion* liste_debut){
    if (liste_debut != NULL){
        Maillion * parcours = liste_debut;
        do {
            printf("Liste : %d", liste_debut->numero);
        } while (parcours != liste_debut);
    }
}

void liberation (Maillion** m){
    if (*m = NULL){
        return;
    }
    liberation(&((*m)->next));
    free (*m);
    *m = NULL;
}*/

void generation_strat (PGAME _pExemple){
    srand(time(NULL));
    GameData* pGameData = _pExemple->gameData;
    pGameData->Strat [pGameData->compteur_strat] = rand()%3;  //0 "paix", 1 "chasseur TIE", 2 "X-wings"
    pGameData->compteur_strat += 1;
}

void affichage_strat (PGAME _pExemple){ //affiche de compteur -6 à compteur
    GameData* pGameData = _pExemple->gameData;
    if (pGameData->Strat[pGameData->strat_affiche] == 1){
        al_draw_bitmap(pGameData->image [2], pGameData->compteur_strat, pGameData->pixel_avance, 0);
    }
    if (pGameData->Strat [pGameData->strat_affiche] == 2){
        al_draw_bitmap(pGameData->image [3], pGameData->compteur_strat, pGameData->pixel_avance, 0);
    }
    printf("%d", pGameData->compteur_strat);
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
    pGameData->image [1] = al_load_bitmap(PATH "\\Textures\\TDLR\\Standtooper.png");
    pGameData->image [2] = al_load_bitmap(PATH "\\Textures\\TDLR\\X-wing.png");
    pGameData->image [3] = al_load_bitmap(PATH "\\Textures\\TDLR\\Chasseur_TIE.png");

    pGameData->compteur_strat =0;
    pGameData->strat_affiche = 0;
    pGameData->pixel_avance = 0;

    pGameData->Strat [0] = 0;
    pGameData->Strat [1] = 0;
    for (int i = 0; i < 5; ++i) {
        generation_strat(_pExemple);
    }
    /*pGameData->liste = NULL;
    ajouterfinLSC(&(pGameData->liste), 1);      //Ici ajouter les première zone sans obstacles
    ajouterfinLSC(&(pGameData->liste), 2);
    ajouterfinLSC(&(pGameData->liste), 3);

    afficherLSC(pGameData->liste);*/
    printf("Jeu cree!\n");
}

void TDLR_Update(PGAME _pExemple)
{
    if (_pExemple->gameData == NULL)  //voir si le programme est lancé
    {
        TDLR_Create(_pExemple);
    }
    GameData* pGameData = _pExemple->gameData;
    //int* gameData = _pExemple->gameData;
    //printf("%d\n", gameData[0]++);

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        TDLR_Destroy(_pExemple);
    }
    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){
        printf("touche espace \n");
        generation_strat (_pExemple);
        pGameData->pixel_avance +=180;
    }

    //ajouterfinLSC(&(pGameData->liste), 1); // ajouter au fur et à mesure des maillions AVEC obstacles
}

void TDLR_TimedUpdate(PGAME _pExemple) //dessin + Timer dans cette fonction
{
    GameData* pGameData = _pExemple->gameData;
    //al_draw_bitmap(pGameData->image [0], 0, 0, 0);
    al_clear_to_color(al_map_rgb(50, 50, 50));
    al_draw_bitmap(pGameData->image [1], 910, 720, 0);
    affichage_strat(_pExemple);
}

void TDLR_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    GameData* pGameData = _pExemple->gameData;
    //liberation(&(pGameData->liste));

    free(_pExemple->gameData); //Pour chaque structure / allocation
    _pExemple->gameData = NULL;

    //Ne pas oublier de destroy

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}


