#include "Menu.h"

void Init_Game_Loading(){
    pMenu_Animation LoadingAnimation = malloc(sizeof (Menu_Animation));

    for (int i=0; i<120; i++){
        sprintf(LoadingAnimation->LoadingCount, "..\\Textures/Map/darkvador%d.png", i);
        LoadingAnimation->LoadingTextures[i]= al_load_bitmap(LoadingAnimation->LoadingCount);
    }
}

void Game_Loading(){
    
}