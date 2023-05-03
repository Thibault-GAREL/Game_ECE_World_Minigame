#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Games/TirAuBallon/GameExemple.h"
#include "Games/Snake/Snake.h"
#include "Utils/allegroutils.h"
#include "Games/Traverse_de_la_riviere/Traverse_code.h"
#include "Games/PecheAuCanards/PAC.h"
#include "Games/TestMap/Map.h"
#include "Games/Exemple/GameExemple.h"
#include "Games/DarkPiano/DarkPiano.h"

#define PLAYER_COUNT 2
#define MAP_EXEMPLE 6

int main()
{
    Allegro_Init();
    PALLEGRO_MANAGER pAlManager = AllegroManager_Create(1920, 1080, 0.01);
    ALLEGRO_EVENT event;
    
    //pMenu_Animation pAnimation_for_Menu = Init_Game_Loading();


    //Allegro_play_Sample(pAlManager->pSampleInstance->walk);

    //Allegro_Stop_Sample(pAlManager->pSampleInstance->walk);

    //ChangeCursor(pAlManager, pAlManager->pCursors->Cursor1);

    int currentGameId = GAME_NONE;

    PPLAYER players;
    Players_Init(&players, PLAYER_COUNT);

    int gamesCount = 5;
    PGAME pGames[gamesCount];
    PMAP pMaps[1];
    //pGames[0] = Game_Init(GAME_EXEMPLE, Exemple_Update, Exemple_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[GAME_SNAKE] = Game_Init(GAME_SNAKE, SnakeGame_Update, SnakeGame_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[GAME_TDLR] = Game_Init(GAME_TDLR, TDLR_Update, TDLR_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[GAME_PAC] = Game_Init(GAME_PAC, PAC_Update, PAC_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[GAME_TAB] = Game_Init(GAME_TAB, TAB_Update, TAB_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[GAME_DP] = Game_Init(GAME_DP, DarkPiano_Update, DarkPiano_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pMaps[0] = Map_Init(MAP_EXEMPLE, Map_Update, Map_TimedUpdate, &currentGameId, &event);

    pGames[GAME_PAC]->SampleAlManager = pAlManager;
    pGames[GAME_TAB]->SampleAlManager = pAlManager;

    while (1)
    {
        al_wait_for_event(pAlManager->pEventQueue, &event);

        if (event.display.type == ALLEGRO_EVENT_DISPLAY_CLOSE || Get_Touch(&event, ALLEGRO_KEY_ESCAPE, 0, 0, 1, 0))
        {
            break;
        }

        if (currentGameId!=6){
            Games_Update(pGames, gamesCount, currentGameId);
        }
        else {
            Maps_Update(pMaps , 1 , currentGameId);
        }

        if (event.mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            continue;
        }

        if (currentGameId == GAME_NONE)
        {
            if (Get_Touch(&event, ALLEGRO_KEY_S, 0, 1, 0, 0))
            {
                currentGameId = GAME_SNAKE;
            }
            if (Get_Touch(&event, ALLEGRO_KEY_T, 0, 1, 0, 0))
            {
                currentGameId = GAME_TDLR;
            }
            if(Get_Touch(&event, ALLEGRO_KEY_E, 0,1,0,0))
            {
                currentGameId = GAME_PAC;
            }
            if(Get_Touch(&event, ALLEGRO_KEY_P, 0,1,0,0))
            {
                currentGameId = GAME_DP;
            }
            if(Get_Touch(&event, ALLEGRO_KEY_F, 0,1,0,0))
            {
                currentGameId = GAME_TAB;
            }
            if (Get_Touch(&event, ALLEGRO_KEY_V, 0, 1, 0, 0))
            {
                currentGameId = MAP_EXEMPLE;
            }
        }

        if (event.type == ALLEGRO_EVENT_TIMER) 
        {
            al_clear_to_color(al_map_rgb(255, 255, 255));

            if (currentGameId == 6) 
            {
                Maps_TimedUpdate(pMaps, 1, currentGameId);
            } 
            else 
            {
                Games_TimedUpdate(pGames, gamesCount, currentGameId);
            }

            al_flip_display();

            continue;
        }
    }

    printf("Correctly quit");
    return 0;
}
