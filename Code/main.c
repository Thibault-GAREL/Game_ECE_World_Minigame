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

#define PLAYER_COUNT 2
#define MAP_EXEMPLE 6
int main()
{
    Allegro_Init();
    PALLEGRO_MANAGER pAlManager = AllegroManager_Create(1920, 1080, 0.01);
    ALLEGRO_EVENT event;

    //Allegro_play_Sample(pAlManager->pSampleInstance->walk);

    //Allegro_Stop_Sample(pAlManager->pSampleInstance->walk);

    //ChangeCursor(pAlManager, pAlManager->pCursors->Cursor1);

    int currentGameId = GAME_NONE;
    
    PPLAYER players;
    Players_Init(&players, PLAYER_COUNT);

    int gamesCount = 5;
    PGAME pGames[gamesCount];
    PMAP pMaps[1];
    pGames[0] = Game_Init(GAME_EXEMPLE, Exemple_Update, Exemple_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[1] = Game_Init(GAME_SNAKE, SnakeGame_Update, SnakeGame_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[2] = Game_Init(GAME_TDLR, TDLR_Update, TDLR_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[3] = Game_Init(GAME_PAC,PAC_Update, PAC_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pGames[4] = Game_Init(GAME_TAB,Exemple_Update, Exemple_TimedUpdate, &currentGameId, &event, PLAYER_COUNT, &players);
    pMaps[0] = Map_Init(MAP_EXEMPLE, Map_Update, Map_TimedUpdate, &currentGameId, &event);

    pGames[3]->SampleAlManager = pAlManager;


    int mouseX = 0;
    int mouseY = 0;
    while (1)
    {
        al_wait_for_event(pAlManager->pEventQueue, &event);
        currentGameId=

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

        if (event.mouse.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            mouseX = event.mouse.x;
            mouseY = event.mouse.y;
            continue;
        }

        if (event.mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            //printf("[%d] mouseX=%d, mouseY=%d\n", event.mouse.button, mouseX, mouseY);
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
        	al_clear_to_color(al_map_rgb(255,255,255));
            if (currentGameId==6){
                Maps_TimedUpdate(pMaps , 1 , currentGameId);
            }
            else {
                Games_TimedUpdate(pGames, gamesCount, currentGameId);
            }
            al_flip_display();
            continue;
        }
        printf("%d\n",currentGameId);
    }

    printf("Correctly quit");
    return 0;
}
