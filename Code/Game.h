#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Utils\\allegroutils.h"

#define TICKET_START 5

enum
{
    GAME_NONE = 0,
    GAME_EXEMPLE = 1,
    GAME_SNAKE,
    GAME_TDLR,
    GAME_PAC,
    GAME_TAB,
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

typedef struct _MAP
{
    int gameId;
    void* MapData;
    void (*Map_Update)(struct _MAP*);
    void (*Map_TimedUpdate)(struct _MAP*);
    int* pCurrentGameId;
    ALLEGRO_EVENT* pEvent;
}MAP, *PMAP;

PGAME Game_Init(int _gameId, void (*_Game_Update)(PGAME), void (*_Game_TimedUpdate)(PGAME), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent, int _playersCount, PPLAYER* _pPlayers);

void Games_Update(PGAME* _pGames, int _gamesCount,int _currentGameId);
void Games_TimedUpdate(PGAME* _pGames, int _gamesCount, int _currentGameId);

void Players_Init(PPLAYER* _pPlayers, int _count);

void Maps_Update(PMAP* _pMaps, int _mapsCount,int _currentGameId);
void Maps_TimedUpdate(PMAP* _pMaps, int _mapsCount, int _currentGameId);
PMAP Map_Init(int _gameId, void (*_Map_Update)(PMAP), void (*_Map_TimedUpdate)(PMAP), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent);
