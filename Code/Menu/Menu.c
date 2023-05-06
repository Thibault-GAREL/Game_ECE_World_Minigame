#include "Menu.h"
#include "../Game.h"
#include "string.h"

void Menu_Create(PGAME _pMenu)
{
    pMenuGameData gameData = malloc(sizeof(MenuGameData));

    _pMenu->gameData = gameData;

    gameData->GameLaunched = 0;
    gameData->Main_Menu_Select = 0;
    gameData->CurrentCharPos = 0;
    gameData->GetNameState = 1;

    gameData->Menu_Bitmap[0] = al_load_bitmap("..\\Textures/Menu/Menu.jpg");
    gameData->Menu_Bitmap[1] = al_load_bitmap("..\\Textures/Menu/Menu Choice 1 (Personnalisé).png");
    gameData->Menu_Bitmap[2] = al_load_bitmap("..\\Textures/Menu/Menu Choice 2 (Personnalisé).png");
    gameData->Menu_Bitmap[3] = al_load_bitmap("..\\Textures/Menu/Menu Choice 3 (Personnalisé).png");
    gameData->Menu_Bitmap[4] = al_load_bitmap("..\\Textures/Menu/Settings.png");
    gameData->Menu_Bitmap[5] = al_load_bitmap("..\\Textures/Menu/Credits.png");
    gameData->Menu_Bitmap[6] = al_load_bitmap("..\\Textures/Menu/Names.png");
    gameData->Menu_Bitmap[7] = al_load_bitmap("..\\Textures/Menu/Button (Personnalisé).png");
    gameData->Menu_Bitmap[8] = al_load_bitmap("..\\Textures/Menu/Button Clicked (Personnalisé).png");

    for (int i = 0; i < 20; ++i) {
        gameData->MB_Infos[i] = malloc(sizeof (MenuBitmapInfo));
        gameData->MB_Infos[i]->BitmapClicked = 0;
    }

    gameData->MB_Infos[0]->x = 0;
    gameData->MB_Infos[0]->y = 0;
    gameData->MB_Infos[1]->x = 300;
    gameData->MB_Infos[1]->y = 200;
    gameData->MB_Infos[2]->x = 300;
    gameData->MB_Infos[2]->y = 450;
    gameData->MB_Infos[3]->x = 300;
    gameData->MB_Infos[3]->y = 700;
    gameData->MB_Infos[4]->x = 0;
    gameData->MB_Infos[4]->y = 0;
    gameData->MB_Infos[5]->x = 0;
    gameData->MB_Infos[5]->y = 0;
    gameData->MB_Infos[6]->x = 0;
    gameData->MB_Infos[6]->y = 0;


    gameData->MB_Infos[7]->x = 950;;
    gameData->MB_Infos[7]->y = 675;;
    gameData->MB_Infos[8]->x = 1050;
    gameData->MB_Infos[8]->y = 675;
    gameData->MB_Infos[9]->x = 1150;
    gameData->MB_Infos[9]->y = 675;
    gameData->MB_Infos[10]->x = 1250;
    gameData->MB_Infos[10]->y = 675;
    gameData->MB_Infos[11]->x = 1350;
    gameData->MB_Infos[11]->y = 675;

    gameData->MB_Infos[12]->x = 950;
    gameData->MB_Infos[12]->y = 850;
    gameData->MB_Infos[13]->x = 1050;
    gameData->MB_Infos[13]->y = 850;
    gameData->MB_Infos[14]->x = 1150;
    gameData->MB_Infos[14]->y = 850;
    gameData->MB_Infos[15]->x = 1250;
    gameData->MB_Infos[15]->y = 850;
    gameData->MB_Infos[16]->x = 1350;
    gameData->MB_Infos[16]->y = 850;
    gameData->MB_Infos[17]->x = 1450;
    gameData->MB_Infos[17]->y = 850;

    gameData->MB_Infos[0]->vx = 0;
    gameData->MB_Infos[0]->vy = 0;
    gameData->MB_Infos[1]->vx = 0;
    gameData->MB_Infos[1]->vy = 2;
    gameData->MB_Infos[2]->vx = 0;
    gameData->MB_Infos[2]->vy = 2;
    gameData->MB_Infos[3]->vx = 0;
    gameData->MB_Infos[3]->vy = 2;
    gameData->MB_Infos[4]->vx = 0;
    gameData->MB_Infos[4]->vy = 0;
    gameData->MB_Infos[5]->vx = 0;
    gameData->MB_Infos[5]->vy = 0;

    for (int i = 0; i < 10; ++i) {
        gameData->GetName1[i] = 0;
        gameData->GetName2[i] = 0;
    }


    gameData->GetNameFont = al_load_font("..\\Textures/Fonts/StarWars Font.TTF", 55, 0);
}

void Menu_Update(PGAME _pMenu)
{
    if (_pMenu->gameData == NULL){
        Menu_Create(_pMenu);
    }

    pMenuGameData gameData = _pMenu->gameData;

    gameData->MB_Infos[1]->MouseIsOver = 0;
    gameData->MB_Infos[2]->MouseIsOver = 0;
    gameData->MB_Infos[3]->MouseIsOver = 0;
    
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

    if (Get_Touch( _pMenu->pEvent, ALLEGRO_KEY_DELETE,0,0,1,0) && gameData->Main_Menu_Select != 0 && gameData->GameLaunched == 0){
        gameData->Main_Menu_Select = 0;
    }
    else if(Get_Touch( _pMenu->pEvent, ALLEGRO_KEY_DELETE,0,0,1,0) && gameData->Main_Menu_Select == 0){
        Menu_Destroy(_pMenu);
    }

    if (Point_In_Rectangle((Vector2D){gameData->mouse.x, gameData->mouse.y}, (Vector2D){gameData->MB_Infos[1]->x ,gameData->MB_Infos[1]->y }, (Vector2D){gameData->MB_Infos[1]->x + al_get_bitmap_width(gameData->Menu_Bitmap[1]),gameData->MB_Infos[1]->y+al_get_bitmap_height(gameData->Menu_Bitmap[1])})){
        gameData->MB_Infos[1]->MouseIsOver = 1;
        if (gameData->click == 1){
            gameData->GameLaunched = 1;
        }
    }
    for (int i = 7; i < 18; ++i) {
        if (Point_In_Rectangle((Vector2D){gameData->mouse.x, gameData->mouse.y}, (Vector2D){gameData->MB_Infos[i]->x ,gameData->MB_Infos[i]->y }, (Vector2D){gameData->MB_Infos[i]->x + al_get_bitmap_width(gameData->Menu_Bitmap[7]),gameData->MB_Infos[i]->y+al_get_bitmap_height(gameData->Menu_Bitmap[7])})){
            if (gameData->click == 1) {
                if (gameData->MB_Infos[i]->BitmapClicked == 1){
                    gameData->MB_Infos[i]->BitmapClicked = 0;
                }
                else {
                    gameData->MB_Infos[i]->BitmapClicked = 1;
                    for (int j = 7; j <18 && j !=i; j++){
                        gameData->MB_Infos[j]->BitmapClicked = 0;
                    }
                    printf("bouton click \n");
                }
            }
        }
    }


    if (gameData->GetNameState == 1){
        if (gameData->GameLaunched == 1){
            al_get_keyboard_state(&(gameData->keyboard_state));
            if (Get_Touch( _pMenu->pEvent, ALLEGRO_KEY_ENTER,0,0,1,0)){
                gameData->GetName1[gameData->CurrentCharPos] = '\0';
                gameData->GetNameState = 2;
                gameData->CurrentCharPos = 0;
            }

            else {
                for (int i = 0; i < ALLEGRO_KEY_MAX; ++i) {
                    if (Get_Touch( _pMenu->pEvent, i,0,0,1,0))
                    {
                        if (i >= ALLEGRO_KEY_A && i <= ALLEGRO_KEY_Z)
                        {
                            if (gameData->CurrentCharPos < sizeof(gameData->GetName1) - 1)
                            {
                                gameData->GetName1[gameData->CurrentCharPos++] = 'a' + (i - ALLEGRO_KEY_A);
                            }
                        }
                        else if (i == ALLEGRO_KEY_BACKSPACE)
                        {
                            if (gameData->CurrentCharPos > 0)
                            {
                                gameData->GetName1[--gameData->CurrentCharPos] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (gameData->GetNameState == 2){
        if (gameData->GameLaunched == 1){
            al_get_keyboard_state(&(gameData->keyboard_state));
            if (Get_Touch( _pMenu->pEvent, ALLEGRO_KEY_ENTER,0,0,1,0)){
                gameData->GetName2[gameData->CurrentCharPos] = '\0';
                gameData->GetNameState = 3;

                strcpy(_pMenu->pPlayers[0]->name, gameData->GetName1);
                strcpy(_pMenu->pPlayers[1]->name, gameData->GetName2);
                printf("%s \n",_pMenu->pPlayers[0]->name);
                printf("%s \n",_pMenu->pPlayers[1]->name);
                Menu_Destroy(_pMenu);
                return;

            }

            else {
                for (int i = 0; i < ALLEGRO_KEY_MAX; ++i) {
                    if (Get_Touch( _pMenu->pEvent, i,0,0,1,0))
                    {
                        if (i >= ALLEGRO_KEY_A && i <= ALLEGRO_KEY_Z)
                        {
                            if (gameData->CurrentCharPos < sizeof(gameData->GetName2) - 1)
                            {
                                gameData->GetName2[gameData->CurrentCharPos++] = 'a' + (i - ALLEGRO_KEY_A);
                            }
                        }
                        else if (i == ALLEGRO_KEY_BACKSPACE)
                        {
                            if (gameData->CurrentCharPos > 0)
                            {
                                gameData->GetName2[--gameData->CurrentCharPos] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if (Point_In_Rectangle((Vector2D){gameData->mouse.x, gameData->mouse.y}, (Vector2D){gameData->MB_Infos[2]->x ,gameData->MB_Infos[2]->y }, (Vector2D){gameData->MB_Infos[2]->x + al_get_bitmap_width(gameData->Menu_Bitmap[2]),gameData->MB_Infos[2]->y+al_get_bitmap_height(gameData->Menu_Bitmap[2])})){
        gameData->MB_Infos[2]->MouseIsOver = 1;
        if (gameData->click == 1){
            gameData->Main_Menu_Select = 1;
        }
    }
    if (Point_In_Rectangle((Vector2D){gameData->mouse.x, gameData->mouse.y}, (Vector2D){gameData->MB_Infos[3]->x ,gameData->MB_Infos[3]->y }, (Vector2D){gameData->MB_Infos[3]->x + al_get_bitmap_width(gameData->Menu_Bitmap[3]),gameData->MB_Infos[3]->y+al_get_bitmap_height(gameData->Menu_Bitmap[3])})){
        gameData->MB_Infos[3]->MouseIsOver = 1;
        if (gameData->click == 1){
            gameData->Main_Menu_Select = 2;
        }
    }
}

void Menu_TimedUpdate(PGAME _pMenu)
{
    pMenuGameData gameData = _pMenu->gameData;

    if (gameData->Main_Menu_Select == 0 && gameData->GameLaunched == 0){
        al_draw_bitmap(gameData->Menu_Bitmap[0],gameData->MB_Infos[0]->x,gameData->MB_Infos[0]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[1],gameData->MB_Infos[1]->x,gameData->MB_Infos[1]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[2],gameData->MB_Infos[2]->x,gameData->MB_Infos[2]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[3],gameData->MB_Infos[3]->x,gameData->MB_Infos[3]->y,0);
    }
    if(gameData->Main_Menu_Select == 1 && gameData->GameLaunched == 0){
        al_draw_bitmap(gameData->Menu_Bitmap[4],gameData->MB_Infos[4]->x,gameData->MB_Infos[4]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[7]->BitmapClicked],gameData->MB_Infos[7]->x, gameData->MB_Infos[7]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[8]->BitmapClicked],gameData->MB_Infos[8]->x, gameData->MB_Infos[8]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[9]->BitmapClicked],gameData->MB_Infos[9]->x, gameData->MB_Infos[9]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[10]->BitmapClicked],gameData->MB_Infos[10]->x, gameData->MB_Infos[10]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[11]->BitmapClicked],gameData->MB_Infos[11]->x, gameData->MB_Infos[11]->y,0);

        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[12]->BitmapClicked],gameData->MB_Infos[12]->x, gameData->MB_Infos[12]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[13]->BitmapClicked],gameData->MB_Infos[13]->x, gameData->MB_Infos[13]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[14]->BitmapClicked],gameData->MB_Infos[14]->x, gameData->MB_Infos[14]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[15]->BitmapClicked],gameData->MB_Infos[15]->x, gameData->MB_Infos[15]->y,0);
        al_draw_bitmap(gameData->Menu_Bitmap[7+gameData->MB_Infos[16]->BitmapClicked],gameData->MB_Infos[16]->x, gameData->MB_Infos[16]->y,0);
    }
    if(gameData->Main_Menu_Select == 2 && gameData->GameLaunched == 0){
        al_draw_bitmap(gameData->Menu_Bitmap[5],gameData->MB_Infos[5]->x,gameData->MB_Infos[5]->y,0);
    }

    if (gameData->GameLaunched == 1 && gameData->GetNameState == 1){
        al_draw_bitmap(gameData->Menu_Bitmap[6],0,0,0);
        al_draw_text(gameData->GetNameFont, al_map_rgb(0,0,0),1154,400,1,gameData->GetName1);
    }

    if (gameData->GameLaunched == 1 && gameData->GetNameState == 2){
        al_draw_bitmap(gameData->Menu_Bitmap[6],0,0,0);
        al_draw_text(gameData->GetNameFont, al_map_rgb(0,0,0),1154,400,1,gameData->GetName1);
        al_draw_text(gameData->GetNameFont, al_map_rgb(0,0,0),1154,670,1,gameData->GetName2);
    }

}

void Menu_Destroy(PGAME _pMenu)
{
    printf("Destruction du jeu...\n");
    pMenuGameData gameData = _pMenu->gameData;

    al_destroy_bitmap(gameData->Menu_Bitmap[0]);
    al_destroy_bitmap(gameData->Menu_Bitmap[1]);
    al_destroy_bitmap(gameData->Menu_Bitmap[2]);
    al_destroy_bitmap(gameData->Menu_Bitmap[3]);
    al_destroy_bitmap(gameData->Menu_Bitmap[4]);
    al_destroy_bitmap(gameData->Menu_Bitmap[5]);
    al_destroy_bitmap(gameData->Menu_Bitmap[6]);

    al_destroy_font(gameData->GetNameFont);

    for (int i = 0; i < 10; ++i) {
        free(gameData->MB_Infos[i]);
    }

    free(_pMenu->gameData);
    _pMenu->gameData = NULL;

    printf("Jeu detruit\n");

    *_pMenu->pCurrentGameId = GAME_MAP;
}

