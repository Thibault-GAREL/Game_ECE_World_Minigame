#include "Menu.h"
#include "../Game.h"

void Menu_Create(PGAME _pMenu)
{
    pMenuGameData gameData = malloc(sizeof(MenuGameData));

    _pMenu->gameData = gameData;

    gameData->GameLaunched = 0;
    gameData->Main_Menu_Select = 1;

    gameData->Menu_Bitmap[0] = al_load_bitmap("..\\Textures/Menu/Menu.jpg");
    gameData->Menu_Bitmap[1] = al_load_bitmap("..\\Textures/Menu/Menu Choice 1 (Personnalisé).png");
    gameData->Menu_Bitmap[2] = al_load_bitmap("..\\Textures/Menu/Menu Choice 2 (Personnalisé).png");
    gameData->Menu_Bitmap[3] = al_load_bitmap("..\\Textures/Menu/Menu Choice 3 (Personnalisé).png");
    gameData->Menu_Bitmap[4] = al_load_bitmap("..\\Textures/Menu/Settings.png");
    gameData->Menu_Bitmap[4] = al_load_bitmap("..\\Textures/Menu/Credits.png");
}

void Menu_Update(PGAME _pMenu)
{
    if (_pMenu->gameData == NULL){
        Menu_Create(_pMenu);
    }

    pMenuGameData gameData = _pMenu->gameData;
    
    if (_pMenu->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        gameData->mouse.x = _pMenu->pEvent->mouse.x*1;
        gameData->mouse.y = _pMenu->pEvent->mouse.y*1;
    }
    if ( _pMenu->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        gameData->click=1;
        printf("click \n");
        printf("%d \n", gameData->click);
    }
    if (_pMenu->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        gameData->click=0;
    }
    if (Get_Touch( _pMenu->pEvent, ALLEGRO_KEY_W,0,0,1,0)){
        Menu_Destroy(_pMenu);
    }
    if (Get_Touch( _pMenu->pEvent, ALLEGRO_KEY_ENTER,0,0,1,0)){
        gameData->GameLaunched = 1;
    }
}

void Menu_TimedUpdate(PGAME _pMenu)
{
    pMenuGameData gameData = _pMenu->gameData;

    if (gameData->Main_Menu_Select == 0){
        al_draw_bitmap(gameData->Menu_Bitmap[0],0,0,0);
        al_draw_bitmap(gameData->Menu_Bitmap[1],300,200,0);
        al_draw_bitmap(gameData->Menu_Bitmap[2],300,450,0);
        al_draw_bitmap(gameData->Menu_Bitmap[3],300,700,0);
    }
    if(gameData->Main_Menu_Select == 1){
        al_draw_bitmap(gameData->Menu_Bitmap[4],0,0,0);
    }

}

void Menu_Destroy(PGAME _pMenu)
{
    printf("Destruction du jeu...\n");

    free(_pMenu->gameData);
    _pMenu->gameData = NULL;

    printf("Jeu detruit\n");

    *_pMenu->pCurrentGameId = GAME_MAP;
}

