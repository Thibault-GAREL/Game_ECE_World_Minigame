#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Utils\\allegroutils.h"

#define TICKET_START 0

enum
{
    GAME_NONE = -1,
    GAME_SNAKE,
    GAME_TDLR,
    GAME_PAC,
    GAME_TAB,
    GAME_DP,
    GAME_MAP,
};

typedef struct _PLAYER
{
    char name[100];
    int tickets;
}PLAYER, *PPLAYER;


typedef struct _GAME
{
    int gameId; //nb du jeu
    void* gameData;
    PALLEGRO_MANAGER SampleAlManager;
    void (*Game_Update)(struct _GAME*);
    void (*Game_TimedUpdate)(struct _GAME*);
    
    int* pCurrentGameId; //jeu en cours
    ALLEGRO_EVENT* pEvent;
    int playersCount;
    PPLAYER* pPlayers;
}GAME, *PGAME;


PGAME Game_Init(int _gameId, void (*_Game_Update)(PGAME), void (*_Game_TimedUpdate)(PGAME), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent, int _playersCount, PPLAYER* _pPlayers);

void Games_Update(PGAME* _pGames, int _gamesCount,int _currentGameId);
void Games_TimedUpdate(PGAME* _pGames, int _gamesCount, int _currentGameId);

void Players_Init(PPLAYER* _pPlayers, int _count);
void Players_Destroy(PPLAYER* _pPlayers, int _count);

