#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Utils\\allegroutils.h"

enum
{
    GAME_NONE = 0,
    GAME_EXEMPLE = 1,
    GAME_SNAKE,
    GAME_TDLR
};

typedef struct _PLAYER
{
    char name[100];
    int tickets;
}PLAYER, *PPLAYER;


typedef struct _GAME
{
    int gameId;
    void* gameData;
    void (*Game_Update)(struct _GAME*);
    void (*Game_TimedUpdate)(struct _GAME*);
    
    int* pCurrentGameId;
    ALLEGRO_EVENT* pEvent;
    PPLAYER* pPlayers;
}GAME, *PGAME;

PGAME Game_Init(int _gameId, void (*_Game_Update)(PGAME), void (*_Game_TimedUpdate)(PGAME), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent, PPLAYER* _pPlayers);

void Games_Update(PGAME* _pGames, int _gamesCount,int _currentGameId);
void Games_TimedUpdate(PGAME* _pGames, int _gamesCount, int _currentGameId);
