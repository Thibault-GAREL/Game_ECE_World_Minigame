#include "Menu.h"

Menu_Animation* Init_Game_Loading(){
    pMenu_Animation LoadingAnimation = malloc(sizeof (Menu_Animation));

    for (int i=1; i<120; i++){
        sprintf(LoadingAnimation->LoadingCount, "..\\Textures/Animations/Allegro-loading/%d.png", i);

        LoadingAnimation->LoadingTextures[i] = al_load_bitmap(LoadingAnimation->LoadingCount);
        printf("%d", i);
    }
    return LoadingAnimation;
}

void Game_Loading(pMenu_Animation pLoadingAnimation){
    al_clear_to_color(al_map_rgb(255,255,255));
    for (int i = 0; i < 120; i++) {
        al_draw_bitmap(pLoadingAnimation->LoadingTextures[i],0,0,0);
    }
}