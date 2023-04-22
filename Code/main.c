#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Games/Exemple/GameExemple.h"
#include "Games/Snake/Snake.h"
#include "Utils/allegroutils.h"
#include "Games/Traverse_de_la_riviere/Traverse_code.h"


int main()
{
    Allegro_Init();
    PALLEGRO_MANAGER pAlManager = AllegroManager_Create(1000, 1000, 0.01);
    ALLEGRO_EVENT event;

    Allegro_play_Sample(pAlManager->pSampleInstance->walk);

    //Allegro_Stop_Sample(pAlManager->pSampleInstance->walk);

    ChangeCursor(pAlManager, pAlManager->pCursors->Cursor1);

    int currentGameId = GAME_NONE;
    PPLAYER players[2];
    int gamesCount = 2;
    PGAME pGames[gamesCount];
    pGames[0] = Game_Init(GAME_EXEMPLE, Exemple_Update, Exemple_TimedUpdate, &currentGameId, &event, players);
    pGames[1] = Game_Init(GAME_SNAKE, Snake_Update, Snake_TimedUpdate, &currentGameId, &event, players);
    pGames [2] = Game_Init(GAME_TDLR, TDLR_Update, TDLR_TimedUpdate, &currentGameId, &event, players);

    int mouseX = 0;
    int mouseY = 0;

    while (1)
    {
        al_wait_for_event(pAlManager->pEventQueue, &event);

        if (event.display.type == ALLEGRO_EVENT_DISPLAY_CLOSE || Get_Touch(&event, ALLEGRO_KEY_ESCAPE, 0, 0, 1, 0))
        {
            break;
        }

        Games_Update(pGames, gamesCount, currentGameId);

        if (event.mouse.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            mouseX = event.mouse.x;
            mouseY = event.mouse.y;
            continue;
        }

        if (event.mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            printf("mouseX=%d, mouseY=%d\n", mouseX, mouseY);
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
        }
        
        if (event.type == ALLEGRO_EVENT_TIMER)
        {
        	al_clear_to_color(al_map_rgb(255,255,255));
            Games_TimedUpdate(pGames, gamesCount, currentGameId);
            al_flip_display();
            continue;
        }
    }

    return 0;
}
