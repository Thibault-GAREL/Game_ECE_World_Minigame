//
// Created by garel on 20/04/2023.
//

#include "Traverse_code.h"
#define Largeur 1920
#define  X_player 910
#define Y_player 720

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

int inverse (int num, int pixel_avance){
    int num_inverse = 0;
    num_inverse= 6 - num + pixel_avance;
    return num_inverse;
}

void generation_strat (PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    pGameData->Strat [pGameData->compteur_strat] = rand()%9;  //0 "paix", 1 "chasseur TIE", 2 "X-wings"
    position_alleatoire(_pExemple);
    if (pGameData->Strat [pGameData->compteur_strat] == 3 || pGameData->Strat [pGameData->compteur_strat] == 4 || pGameData->Strat [pGameData->compteur_strat] == 7 || pGameData->Strat [pGameData->compteur_strat] == 8){
        pGameData->position_obstacle[pGameData->compteur_strat].x2 = pGameData->position_obstacle[pGameData->compteur_strat].x + 900;
    }
    if (pGameData->Strat [pGameData->compteur_strat] == 5 || pGameData->Strat [pGameData->compteur_strat] == 6 || pGameData->Strat [pGameData->compteur_strat] == 7 || pGameData->Strat [pGameData->compteur_strat] == 8){
        pGameData->position_obstacle [pGameData->compteur_strat].vx_ajout = pGameData->position_obstacle [pGameData->compteur_strat].vx_ajout * -1;
    }
    //printf("%d", pGameData->Strat[pGameData->compteur_strat]);
    pGameData->compteur_strat += 1;
}

void position_alleatoire (PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    //pGameData->position_obstacle[pGameData->compteur_strat].vient_droite = rand()%1;
    if (pGameData->Strat [pGameData->compteur_strat] == 0){
        pGameData->position_obstacle[pGameData->compteur_strat].x = 0;
        pGameData->position_obstacle[pGameData->compteur_strat].vx = 0;
        pGameData->position_obstacle[pGameData->compteur_strat].vx_ajout = 0;
    }
    else{
        pGameData->position_obstacle[pGameData->compteur_strat].x = rand()%1120 + 10;
        //printf("position x : %f", pGameData->position_obstacle [pGameData->compteur_strat].x);
        pGameData->position_obstacle[pGameData->compteur_strat].vx_ajout = rand()%5 + 3;
        //printf("position x : %f", pGameData->position_obstacle [pGameData->compteur_strat].vx);
    }
}

void affichage_strat (PGAME _pExemple, int numero){
    GameData* pGameData = (GameData*) _pExemple->gameData;
    if (pGameData->Strat [numero] == 0) {
        al_draw_bitmap(pGameData->image [1], 1800, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->Strat[numero] == 1){
        al_draw_bitmap(pGameData->image [2], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->Strat [numero] == 2){
        al_draw_bitmap(pGameData->image [3], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->Strat[numero] == 3){
        al_draw_bitmap(pGameData->image [2], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->image [2], pGameData->position_obstacle[numero].x_transi2, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData ->Strat[numero] == 4){
        al_draw_bitmap(pGameData->image [3], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->image [3], pGameData->position_obstacle[numero].x_transi2, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }

    if (pGameData->Strat[numero] == 5){
        al_draw_bitmap(pGameData->image [4], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->Strat [numero] == 6){
        al_draw_bitmap(pGameData->image [5], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->Strat[numero] == 7){
        al_draw_bitmap(pGameData->image [4], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->image [4], pGameData->position_obstacle[numero].x_transi2, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData ->Strat[numero] == 8){
        al_draw_bitmap(pGameData->image [5], pGameData->position_obstacle[numero].x_transi, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->image [5], pGameData->position_obstacle[numero].x_transi2, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    //printf("%d", pGameData->compteur_strat);
}

bool collision (PGAME _pExemple, int numero){
    GameData* pGameData = (GameData*) _pExemple->gameData;

    if (pGameData->position_obstacle [numero].x_transi <= (X_player + 50) && (X_player + 50) <= (pGameData->position_obstacle [numero].x_transi +180) ){
        return TRUE;
    }

        if (pGameData->position_obstacle [numero].x_transi2 <= (X_player + 50) && (X_player + 50) <= (pGameData->position_obstacle [numero].x_transi2 +180)){
            return TRUE;
        }


    else {
        return FALSE;
    }
}

void TDLR_Create(PGAME _pExemple)
{
    /*printf("Creation du jeu...\n");

    int* gameData = (int*)malloc(sizeof(int) * 2);
    gameData[0] = 0;
    gameData[1] = 0;
    _pExemple->gameData = gameData;*/

    GameData* pGameData = (GameData*) malloc (sizeof (GameData));
    _pExemple->gameData = pGameData;
    pGameData->image [0] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fond_d-ecran-Bataille_spatiale.jpg");
    pGameData->image [1] = al_load_bitmap(PATH "\\Textures\\TDLR\\Standtooper.png");
    pGameData->image [2] = al_load_bitmap(PATH "\\Textures\\TDLR\\X-wing_gauche.png");
    pGameData->image [3] = al_load_bitmap(PATH "\\Textures\\TDLR\\Chasseur_TIE_gauche.png");
    pGameData->image [4] = al_load_bitmap(PATH "\\Textures\\TDLR\\X-wing_droite.png");
    pGameData->image [5] = al_load_bitmap(PATH "\\Textures\\TDLR\\Chasseur_TIE_droite.png");

    pGameData->police[0]= al_load_ttf_font(PATH"\\police.ttf",150,0);
    pGameData->police[1]= al_load_ttf_font(PATH"\\police.ttf",100,0);
    pGameData->police[2]= al_load_ttf_font(PATH"\\police.ttf",30,0);

    pGameData->compteur_strat = 3;
    pGameData->pixel_avance = 0;
    pGameData->life = 30;
    pGameData->gamemode = 0;
    srand(time(NULL));

    pGameData->Strat [0] = 0;
    pGameData->Strat [1] = 0;
    pGameData->Strat [2] = 0;

    /*pGameData->Strat [3] = 1;
    pGameData->Strat [4] = 1;
    pGameData->Strat [5] = 1;
    pGameData->Strat [6] = 1;
    pGameData->Strat [7] = 1;
    pGameData->Strat [8] = 1;
    pGameData->Strat [9] = 1;
    pGameData->Strat [10] = 1;
    pGameData->Strat [11] = 1;*/

    for (int i = 2; i < 7; ++i) {
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
    GameData* pGameData = (GameData*) _pExemple->gameData;
    //int* gameData = _pExemple->gameData;
    //printf("%d\n", gameData[0]++);

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        TDLR_Destroy(_pExemple);
    }
    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_SPACE, 0, 1, 0, 0)){
        //printf("touche espace \n");
        pGameData->pixel_avance += 1;
        generation_strat(_pExemple);
    }

    //ajouterfinLSC(&(pGameData->liste), 1); // ajouter au fur et à mesure des maillions AVEC obstacles
}

void TDLR_TimedUpdate(PGAME _pExemple) //dessin + Timer dans cette fonction
{
    GameData* pGameData = (GameData*) _pExemple->gameData;
    //al_draw_bitmap(pGameData->image [0], 0, 0, 0);
    if (pGameData->gamemode == 0) {
        al_draw_bitmap(pGameData->image [0], 0, 0, 0);
    }
    if (pGameData->gamemode == 1) {
        al_clear_to_color(al_map_rgb(50, 50, 50));
        al_draw_bitmap(pGameData->image [1], X_player, Y_player, 0);

        if (collision(_pExemple, pGameData->pixel_avance + 2) == TRUE){
            al_clear_to_color(al_map_rgba(255, 0, 0, 245));
            pGameData->life -=1;
        }

        if (pGameData->life <= 0){
            //al_clear_to_color(al_map_rgb(255, 255, 255));
            al_rest(20);
        }

        for (int i = pGameData->pixel_avance; i < pGameData->pixel_avance + 7 ; ++i) {

            if (pGameData->position_obstacle [i].vx_ajout > 0 && pGameData->position_obstacle[i].x_transi >= Largeur){
                pGameData->position_obstacle[i].x = -150;
                pGameData->position_obstacle[i].x_transi = -10;
                pGameData->position_obstacle[i].vx = 0;

            }
            if (pGameData->position_obstacle [i].vx_ajout > 0 && pGameData->position_obstacle [i].x_transi2 >= Largeur){
                pGameData->position_obstacle[i].x2 = -150;
                pGameData->position_obstacle[i].x_transi2 = -10;
                pGameData->position_obstacle[i].vx2 = 0;
            }

            if (pGameData->position_obstacle [i].vx_ajout < 0 && pGameData->position_obstacle [i].x_transi <= -150){
                pGameData->position_obstacle[i].x = Largeur + 150;
                pGameData->position_obstacle[i].x_transi = 10;
                pGameData->position_obstacle[i].vx = 0;

            }
            if (pGameData->position_obstacle [i].vx_ajout < 0 && pGameData->position_obstacle [i].x_transi2 <= -150){
                pGameData->position_obstacle[i].x2 = Largeur + 150;
                pGameData->position_obstacle[i].x_transi2 = 10;
                pGameData->position_obstacle[i].vx2 = 0;
            }

            pGameData->position_obstacle [i].vx = pGameData->position_obstacle [i].vx + pGameData->position_obstacle [i].vx_ajout;
            pGameData->position_obstacle [i].x_transi = pGameData->position_obstacle [i].x + pGameData->position_obstacle [i].vx;

            if ((pGameData->Strat [i] == 3) || (pGameData->Strat [i] == 4) || (pGameData->Strat [i] == 7) || (pGameData->Strat [i] == 8)) {
                pGameData->position_obstacle[i].vx2 =
                        pGameData->position_obstacle[i].vx2 + pGameData->position_obstacle[i].vx_ajout;
                pGameData->position_obstacle[i].x_transi2 =
                        pGameData->position_obstacle[i].x2 + pGameData->position_obstacle[i].vx2;
            }
            affichage_strat(_pExemple, i);      //affiche de compteur -6 à compteur
            printf("position de %d : %f\n", pGameData->pixel_avance + 2, pGameData->position_obstacle[pGameData->pixel_avance + 2].x_transi);
            printf("life : %d", pGameData->life);
        }
    }
}

void TDLR_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    GameData* pGameData = (GameData*) _pExemple->gameData;
    //liberation(&(pGameData->liste));

    free(_pExemple->gameData); //Pour chaque structure / allocation
    _pExemple->gameData = NULL;

                                                                                                                //Ne pas oublier de destroy

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}


// Manque ajout des 2 joueurs +

