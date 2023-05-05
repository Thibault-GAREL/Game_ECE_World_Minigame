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

int inverse (int num, int pixel_avance){
    int num_inverse = 0;
    num_inverse= 6 - num + pixel_avance;
    return num_inverse;
}

void generation_strat (PGAME _pExemple){
    GameData* pGameData = _pExemple->gameData;
    //pGameData->Strat [pGameData->compteur_strat] = rand()%9;  //0 "paix", 1 "chasseur TIE", 2 "X-wings"

    if (pGameData->Strat [pGameData->compteur_strat-1] == 0 ) {
        pGameData->Strat [pGameData->compteur_strat] = rand()%9;
    }
    if (pGameData->Strat [pGameData->compteur_strat-1] == 5 || pGameData->Strat [pGameData->compteur_strat-1] == 6 || pGameData->Strat [pGameData->compteur_strat-1] == 7 || pGameData->Strat [pGameData->compteur_strat-1] == 8) {
        pGameData->Strat [pGameData->compteur_strat] = rand()%5;
    }
    else if (pGameData->Strat [pGameData->compteur_strat-1] == 1 || pGameData->Strat [pGameData->compteur_strat-1] == 2 || pGameData->Strat [pGameData->compteur_strat-1] == 3 || pGameData->Strat [pGameData->compteur_strat -1] == 4) {
        pGameData->Strat [pGameData->compteur_strat] = rand()%3 +5;
    }
    position_alleatoire(_pExemple);
    if (pGameData->Strat [pGameData->compteur_strat] == 3 || pGameData->Strat [pGameData->compteur_strat] == 4 || pGameData->Strat [pGameData->compteur_strat] == 7 || pGameData->Strat [pGameData->compteur_strat] == 8){
        pGameData->position_obstacle[pGameData->compteur_strat].x2 = pGameData->position_obstacle[pGameData->compteur_strat].x + 900;
    }
    if (pGameData->Strat [pGameData->compteur_strat] == 5 || pGameData->Strat [pGameData->compteur_strat] == 6 || pGameData->Strat [pGameData->compteur_strat] == 7 || pGameData->Strat [pGameData->compteur_strat] == 8){
        pGameData->position_obstacle [pGameData->compteur_strat].vx_ajout = pGameData->position_obstacle [pGameData->compteur_strat].vx_ajout * -1;
    }
    //printf("%d", pGameData->Strat[pGameData->compteur_strat]);
    pGameData->compteur_strat += 1;
    pGameData->fond_choisi [pGameData->compteur_strat]= rand()%8;
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
        pGameData->position_obstacle[pGameData->compteur_strat].vx_ajout = rand()%5 + 4;
        //printf("position x : %f", pGameData->position_obstacle [pGameData->compteur_strat].vx);
    }
}

void affichage_strat (PGAME _pExemple, int numero){
    GameData* pGameData = (GameData*) _pExemple->gameData;
    if (pGameData->Strat [numero] == 0) {
        al_draw_bitmap(pGameData->fond [8], 0, inverse(numero, pGameData->pixel_avance) * 180, 0);
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

    else {
        //al_draw_bitmap(pGameData->image [1], 0, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    //printf("%d", pGameData->compteur_strat);
}
void affichage_fond (PGAME _pExemple, int numero) {
    GameData* pGameData = (GameData*) _pExemple->gameData;
    if (pGameData->fond_choisi [numero] == 0) {
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->fond_choisi[numero] == 1){
        al_draw_bitmap(pGameData->fond [1], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->fond_choisi [numero] == 2){
        al_draw_bitmap(pGameData->fond [2], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->fond_choisi[numero] == 3){
        al_draw_bitmap(pGameData->fond [3], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData ->fond_choisi[numero] == 4){
        al_draw_bitmap(pGameData->fond [4], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }

    if (pGameData->fond_choisi[numero] == 5){
        al_draw_bitmap(pGameData->fond [5], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->fond_choisi [numero] == 6){
        al_draw_bitmap(pGameData->fond [6], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
    if (pGameData->fond_choisi[numero] == 7){
        al_draw_bitmap(pGameData->fond [7], pGameData->x_fond [numero], inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] + 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
        al_draw_bitmap(pGameData->fond [0], pGameData->x_fond [numero] - 1920, inverse(numero, pGameData->pixel_avance) * 180, 0);
    }
}

bool collision (PGAME _pExemple, int numero){
    GameData* pGameData = (GameData*) _pExemple->gameData;   // pGameData->position_obstacle [pGameData->pixel_avance + 2].x_transi/2 +

    if (pGameData->position_obstacle [numero].x_transi <= (pGameData->X_player + 50) && (pGameData->X_player + 50) <= (pGameData->position_obstacle [numero].x_transi +180) ){
        return true;
    }

        if (pGameData->position_obstacle [numero].x_transi2 <= (pGameData->X_player + 50) && (pGameData->X_player + 50) <= (pGameData->position_obstacle [numero].x_transi2 +180)){
            return true;
        }


    else {
        return false;
    }
}

void next_joueur (PGAME _pExemple){
    GameData* pGameData = (GameData*) _pExemple->gameData;
    pGameData->life = LIFE;
    pGameData->compteur_strat = 3;
    pGameData->pixel_avance = 0;
    pGameData->player_en_cours = 3;
    pGameData->temps_restant = 31000;

    pGameData->Strat [0] = 0;
    pGameData->Strat [1] = 0;
    pGameData->Strat [2] = 0;

    pGameData->fond_choisi [0] = 1;
    pGameData->fond_choisi [1] = 2;
    pGameData->fond_choisi [2] = 3;
    pGameData->fond_choisi [3] = 4;

    pGameData->X_player = 910;

    //pGameData->nb_jouer = 1;

    for (int i = 3; i < 7; ++i) {
        generation_strat(_pExemple);
    }
}

/*void nb_to_text (int score_player, char score_player_txt []) {
    int score = score_player;

    int scoreDec[4] = {0, 0, 0, 0};
    scoreDec[0] = score / 1000;
    scoreDec[1] = (score - scoreDec[0] * 1000) / 100;
    scoreDec[2] = (score - scoreDec[0] * 1000 - scoreDec[1]  * 100) / 10;
    scoreDec[3] = (score - scoreDec[0] * 1000 - scoreDec[1] * 100 - scoreDec[2] * 10);

    char zero = '0';
    char scoreStr[5] = "0000\0";

    for (size_t i = 0; i < 4; i++)
    {
        scoreStr[i] = scoreDec[i] + zero;
    }
    score_player_txt = scoreStr;
}*/

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

    pGameData->image [7] = al_load_bitmap(PATH "\\Textures\\TDLR\\boutonplay.png");
    pGameData->image [8] = al_load_bitmap(PATH "\\Textures\\TDLR\\Etoile_noire.jpg");

    pGameData->fond [0] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip.png");
    pGameData->fond [1] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip1.png");
    pGameData->fond [2] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip2.png");
    pGameData->fond [3] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip3.png");
    pGameData->fond [4] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip4.png");
    pGameData->fond [5] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip5.png");
    pGameData->fond [6] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip6.png");
    pGameData->fond [7] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\tempsnip7.png");
    pGameData->fond [8] = al_load_bitmap(PATH "\\Textures\\TDLR\\Fonds\\Zone_de_paix.png");

    /*pGameData->video [0] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h56m51s571.png");
    pGameData->video [1] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h56m58s324.png");
    pGameData->video [2] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m01s945.png");
    pGameData->video [3] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m06s538.png");
    pGameData->video [4] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m11s632.png");
    pGameData->video [5] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m15s450.png");
    pGameData->video [6] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m19s121.png");
    pGameData->video [7] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m23s030.png");
    pGameData->video [8] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m26s670.png");
    pGameData->video [9] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m30s530.png");
    pGameData->video [10] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m35s216.png");
    pGameData->video [11] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m39s320.png");
    pGameData->video [12] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m43s768.png");
    pGameData->video [13] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m47s732.png");
    pGameData->video [14] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m52s671.png");
    pGameData->video [15] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h57m56s460.png");
    pGameData->video [16] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h58m00s724.png");
    pGameData->video [17] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h58m05s653.png");
    pGameData->video [18] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h58m12s321.png");
    pGameData->video [19] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h58m16s241.png");
    pGameData->video [20] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h58m46s620.png");
    pGameData->video [21] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-12h59m27s401.png");
    pGameData->video [22] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h04m38s452.png");
    pGameData->video [23] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h04m43s448.png)");
    pGameData->video [24] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m17s417.png");
    pGameData->video [25] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m22s560.png");
    pGameData->video [26] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m26s871.png");
    pGameData->video [27] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m32s616.png");
    pGameData->video [28] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m36s320.png");
    pGameData->video [29] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m40s875.png");
    pGameData->video [30] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m44s652.png");
    pGameData->video [31] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m48s874.png");
    pGameData->video [32] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h06m53s778.png");
    pGameData->video [33] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h07m02s058.png");
    pGameData->video [34] = al_load_bitmap(PATH "\\Textures\\TDLR\\Dark_vador\\vlcsnap-2023-05-04-13h07m14s492.png");*/

    pGameData->police[0]= al_load_ttf_font(PATH"\\Textures\\Fonts\\police.ttf",150,0);
    pGameData->police[1]= al_load_ttf_font(PATH"\\Textures\\Fonts\\police.ttf",100,0);
    pGameData->police[2]= al_load_ttf_font(PATH"\\Textures\\Fonts\\police.ttf",50,0);


    pGameData->compteur_strat = 3;
    pGameData->pixel_avance = 0;
    pGameData->life = LIFE;
    pGameData->gamemode = 0;
    pGameData->temps_restant = 31000;
    pGameData->player_en_cours = 1;
    pGameData->compteur_rectangle = 0;
    srand(time(NULL));

    pGameData->Strat [0] = 0;
    pGameData->Strat [1] = 0;
    pGameData->Strat [2] = 0;

    pGameData->fond_choisi [0] = 1;
    pGameData->fond_choisi [1] = 2;
    pGameData->fond_choisi [2] = 3;
    pGameData->fond_choisi [3] = 4;

    pGameData->X_player = 910;

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
    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_UP, 0, 1, 0, 0) && pGameData->gamemode == 1){
        //printf("touche espace \n");
        pGameData->pixel_avance += 1;
        generation_strat(_pExemple);
    }

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_RIGHT, 0, 0, 0, 1) && pGameData->gamemode == 1){
        //printf("touche espace \n");
        pGameData->X_player = pGameData->X_player + 15;
    }

    if (Get_Touch(_pExemple->pEvent, ALLEGRO_KEY_LEFT, 0, 0, 0, 1) && pGameData->gamemode == 1){
        //printf("touche espace \n");
        pGameData->X_player = pGameData->X_player - 15;
    }

    if (_pExemple->pEvent->mouse.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pGameData->mouse_position.x = _pExemple->pEvent->mouse.x;
        pGameData->mouse_position.y = _pExemple->pEvent->mouse.y;
    }

    if (_pExemple->pEvent->mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && _pExemple->pEvent->mouse.button == 1){
        pGameData->click =1;
    }
    if (_pExemple->pEvent->mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && _pExemple->pEvent->mouse.button == 1){
        pGameData->click =0;
    }


    //ajouterfinLSC(&(pGameData->liste), 1); // ajouter au fur et à mesure des maillions AVEC obstacles
}

void TDLR_TimedUpdate(PGAME _pExemple) //dessin + Timer dans cette fonction
{
    GameData* pGameData = (GameData*) _pExemple->gameData;
    //al_draw_bitmap(pGameData->image [0], 0, 0, 0);
    if (pGameData->gamemode == 0) {
        Allegro_Stop_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Fin);
        Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Menu);
        al_draw_bitmap(pGameData->image [0], 0, 0, 0);
        //al_draw_bitmap(pGameData->image [8], 0, 0, 0);
        al_draw_filled_rectangle(255, 90, 1665, 310, al_map_rgba(50, 50, 50, 255));
        al_draw_text(pGameData->police[1], al_map_rgb(255, 255, 255),265,100,0,"Traversé du champ");
        al_draw_text(pGameData->police[1], al_map_rgb(255, 255, 255),550,200,0,"de bataille");

        if (pGameData->player_en_cours == 1) {
            al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),100,480,0,"C'est au tour de :");
            //al_draw_text(pGameData->police [2], al_map_rgb(255, 255, 255), 100, 580, 0, _pExemple->pPlayers [0]->name);       //mettre ensuite _pExemple->pPlayers[0]->name
            //al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),1350,480,0,"Player 2"); //_pExemple->pPlayers[1]->name
        }
        if (pGameData->player_en_cours == 2) {
            al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),100,480,0,"C'est au tour de");  //mettre ensuite _pExemple->pPlayers[0]->name
            //al_draw_text(pGameData->police [2], al_map_rgb(255, 255, 255), 100, 580, 0, _pExemple->pPlayers [1]->name);
            //al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),1350,480,0,"Player 2"); //_pExemple->pPlayers[1]->name
        }

        if (Point_In_Rectangle(pGameData->mouse_position, (Vector2D){816,800}, (Vector2D){1104,889}) == 1 && pGameData->click==1)
        {
            pGameData->gamemode=1;
            pGameData->click=0;
        }
        //  tif (Point_In_Rectangle())
        al_draw_bitmap(pGameData->image [7], 816, 800, 0);
        //printf("X: %f, Y: %f \n", pGameData->mouse_position.x,  pGameData->mouse_position.y);
        //al_draw_filled_rectangle(816, 800, 1104, 889, al_map_rgb(255, 0, 0));
    }
    else if (pGameData->gamemode == 1) {
        Allegro_Stop_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Menu);
        Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Fin);
        /*if (pGameData->player_en_cours == 2 ) {
            next_joueur(_pExemple);
            //pGameData->nb_jouer =2;&& pGameData->nb_jouer == 1
        }*/
        al_clear_to_color(al_map_rgb( 0, 0, 0));
        pGameData->X_player = pGameData->position_obstacle [pGameData->pixel_avance + 2].vx_ajout/2 + pGameData->X_player;
        for (int i = pGameData->pixel_avance; i < pGameData->pixel_avance + 7 ; ++i) {
            pGameData->x_fond[i] = pGameData->position_obstacle[i].vx_ajout/4 + pGameData->x_fond[i];
            if (pGameData->x_fond [i] <= -Largeur){
                pGameData->x_fond [i] = 0;
            }
            if (pGameData->x_fond [i] > Largeur){
                pGameData->x_fond [i] = -Largeur;
            }
            affichage_fond(_pExemple, i);
        }


        printf("%d\n", pGameData->X_player);

        if (collision(_pExemple, pGameData->pixel_avance + 2) == true){
            al_clear_to_color(al_map_rgba(255, 0, 0, 245));
            Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Degats);
            pGameData->life -=1;
        }

        if (pGameData->X_player <= 0 ){ ///||
            al_clear_to_color(al_map_rgba(255, 0, 0, 245));
            pGameData->life = pGameData->life -1;
            Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Degats);
        }
        if (pGameData->X_player > Largeur) {
            al_clear_to_color(al_map_rgba(255, 0, 0, 245));
            pGameData->life = pGameData->life -1;
            Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Degats);
        }

        if (pGameData->life <= 0 || pGameData->temps_restant <=0){                                   //changer ici si + de 2 joueurs
            //al_clear_to_color(al_map_rgb(255, 255, 255));
            if (pGameData->player_en_cours == 1){
                pGameData->gamemode = 0;
                pGameData->player_en_cours = 2;
            }
            else if (pGameData->player_en_cours == 2){
                pGameData->gamemode = 1;
                next_joueur(_pExemple);
            }
            else if (pGameData->player_en_cours == 3){
                pGameData->gamemode = 2;
            }

        }
        if (pGameData->player_en_cours == 1) {
           pGameData->score_player1 = pGameData->pixel_avance;
           //printf("%d \n", pGameData->score_player1 );
           //printf("AAA");
        }
        else  {
            pGameData->score_player2 = pGameData->pixel_avance;
            //printf("%d \n", pGameData->pixel_avance);
            //printf("AAA");
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
            //printf("position de %d : %f\n", pGameData->pixel_avance + 2, pGameData->position_obstacle[pGameData->pixel_avance + 2].x_transi);
            //printf("life : %d", pGameData->life);
            if (pGameData->life >= 0) {
                al_draw_filled_rectangle(50, 50, pGameData->life + 50, 100, al_map_rgb(0, 200, 0));
                al_draw_rectangle(50, 50, pGameData->life + 50, 100, al_map_rgb(255, 255, 255), 3);
                al_draw_text(pGameData->police [2], al_map_rgb(255, 255, 255), 50, 100, 0, "Life");
            }
            pGameData->temps_restant = pGameData->temps_restant - 1;
            //sprintf(pGameData->timer, "%d", (int) pGameData->temps_restant);
            //printf("%d", pGameData->timer);
            sprintf(pGameData->timer_txt,"%d",(int) pGameData->temps_restant/1000);
            al_draw_text(pGameData->police[1], al_map_rgb(255,255,255),1650,50,0,pGameData->timer_txt);
            al_draw_text(pGameData->police[2], al_map_rgb(255,255,255),1400,75,0,"Timer :");
        }
        al_draw_bitmap(pGameData->image [1], pGameData->X_player, Y_player, 0);
    }
    else if (pGameData->gamemode == 2) {
        Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Fin);
        al_draw_bitmap(pGameData->image [8], 0, 0, 0);
        al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),100,480,0,"Score du joueur 1 :");
        al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),1100,480,0,"Score du jouuer 2 :");
        //printf("1 : %d / 2 : %d \n", pGameData->score_player1, pGameData->score_player2);
        if (pGameData->compteur_rectangle <= pGameData->score_player1*2) {
            pGameData->compteur_rectangle ++;
        }
        al_draw_filled_rectangle(100, 900, pGameData->score_player1*2 + 100, 950, al_map_rgb(200, 0, 0));
        al_draw_filled_rectangle(1100, 900, pGameData->score_player2*2 + 1100, 950, al_map_rgb(0, 0, 200));
        //nb_to_text(pGameData->score_player1, pGameData->score_player1_txt);


        int score1 = pGameData->score_player1;

        int scoreDec1[4] = {0, 0, 0, 0};
        scoreDec1[0] = score1 / 1000;
        scoreDec1[1] = (score1 - scoreDec1[0] * 1000) / 100;
        scoreDec1[2] = (score1 - scoreDec1[0] * 1000 - scoreDec1[1]  * 100) / 10;
        scoreDec1[3] = (score1 - scoreDec1[0] * 1000 - scoreDec1[1] * 100 - scoreDec1[2] * 10);

        int score2 = pGameData->score_player2;

        int scoreDec2[4] = {0, 0, 0, 0};
        scoreDec2[0] = score2 / 1000;
        scoreDec2[1] = (score2 - scoreDec2[0] * 1000) / 100;
        scoreDec2[2] = (score2 - scoreDec2[0] * 1000 - scoreDec2[1]  * 100) / 10;
        scoreDec2[3] = (score2 - scoreDec2[0] * 1000 - scoreDec2[1] * 100 - scoreDec2[2] * 10);

        char zero = '0';
        char scoreStr1[5] = "0000\0";
        char scoreStr2[5] = "0000\0";

        for (size_t i = 0; i < 4; i++)
        {
            scoreStr1[i] = scoreDec1[i] + zero;
        }
        for (size_t i = 0; i < 4; i++)
        {
            scoreStr2[i] = scoreDec2[i] + zero;
        }
        pGameData->score_player1_txt = scoreStr1;
        pGameData->score_player2_txt = scoreStr2;

        al_draw_text(pGameData->police [2], al_map_rgb(100, 0, 0), 100, 580, 0, pGameData->score_player1_txt);
        al_draw_text(pGameData->police [2], al_map_rgb(0, 0, 100), 1100, 580, 0, pGameData->score_player2_txt);
        if (Point_In_Rectangle(pGameData->mouse_position, (Vector2D){720, 100}, (Vector2D){1100, 250}) == 1 && pGameData->click==1)
        {
            pGameData->gamemode=3;
            pGameData->click=0;
        }
        //  tif (Point_In_Rectangle())
        //al_draw_bitmap(pGameData->image [7], 910, 100, 0);
        al_draw_filled_rectangle(720, 100, 1100, 250, al_map_rgb(50, 100, 200));
        al_draw_rectangle(720, 100, 1100, 250, al_map_rgb(255, 255, 255), 3);
        al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 775, 150, 0, "Suivant");
    }
    if (pGameData->gamemode == 3) {
        Allegro_play_Sample((_pExemple->SampleAlManager)->pSampleInstance->TDLR_Fin);
        al_draw_bitmap(pGameData->image [8], 0, 0, 0);
        al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255),100,100,0,"Le gagnant est :");
        if (pGameData->score_player1 > pGameData->score_player2){
            pGameData->gagnant = pGameData->score_player1;
            al_draw_filled_rectangle(720, 700, 1100, 850, al_map_rgb(50, 100, 200));
            al_draw_rectangle(720, 700, 1100, 850, al_map_rgb(255, 255, 255), 3);
            al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 800 , 750, 0, "Sortir");
            if (Point_In_Rectangle(pGameData->mouse_position, (Vector2D){720, 700}, (Vector2D){1100, 850}) == 1 && pGameData->click==1)
            {
                _pExemple->pPlayers [0]->tickets ++;
                pGameData->click=0;
                TDLR_Destroy(_pExemple);
                return;
                //al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 100, 400, 0, _pExemple->pPlayers[0]->name);
            }
        }
        else if (pGameData->score_player1 < pGameData->score_player2){
            pGameData->gagnant = pGameData->score_player2;
            al_draw_filled_rectangle(720, 700, 1100, 850, al_map_rgb(50, 100, 200));
            al_draw_rectangle(720, 700, 1100, 850, al_map_rgb(255, 255, 255), 3);
            al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 800 , 750, 0, "Sortir");
            if (Point_In_Rectangle(pGameData->mouse_position, (Vector2D){720, 700}, (Vector2D){1100, 850}) == 1 && pGameData->click==1)
            {
                _pExemple->pPlayers [1]->tickets ++;
                pGameData->click=0;
                TDLR_Destroy(_pExemple);
                //al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 100, 400, 0, _pExemple->pPlayers[1]->name);
                return;
            }
        }
        else {
            pGameData->gagnant = 0;
            al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 100, 400, 0, "personne (vous avez eu le même score!)");
            al_draw_filled_rectangle(720, 700, 1100, 850, al_map_rgb(50, 100, 200));
            al_draw_rectangle(720, 700, 1100, 850, al_map_rgb(255, 255, 255), 3);
            al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 800 , 750, 0, "Sortir");
            if (Point_In_Rectangle(pGameData->mouse_position, (Vector2D){720, 700}, (Vector2D){1100, 850}) == 1 && pGameData->click==1)
            {
                _pExemple->pPlayers [0]->tickets ++;
                _pExemple->pPlayers [1]->tickets ++;
                pGameData->click=0;
                TDLR_Destroy(_pExemple);
                //al_draw_text(pGameData->police[2], al_map_rgb(255, 255, 255), 100, 400, 0, _pExemple->pPlayers[1]->name);
                return;
            }
        }
    }
}

void TDLR_Destroy(PGAME _pExemple)
{
    printf("Destruction du jeu...\n");

    GameData* pGameData = (GameData*) _pExemple->gameData;
    for (int i = 0; i < 9; ++i) {
        al_destroy_bitmap(pGameData->image [i]);
        al_destroy_bitmap(pGameData->fond [i]);
    }
    for (int i = 0; i < 3; ++i) {
        al_destroy_font(pGameData->police [i]);
    }
    for (int i = 0; i < 35; ++i) {
        al_destroy_bitmap(pGameData->video [i]);
    }
    free(_pExemple->gameData); //Pour chaque structure / allocation
    _pExemple->gameData = NULL;


                                                                                                                //Ne pas oublier de destroy

    printf("Jeu detruit\n");

    *_pExemple->pCurrentGameId = GAME_MAP;

    printf("Etat du jeu actuel mis a GAME_NONE");
}


// Menu + affichage vie + affichage point + eclairé le bouton + faire fiche explicative sur le jeu  + Dark vador + plateforme + son + fond a finir

// Fait

