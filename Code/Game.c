#include "Game.h"

PGAME Game_Init(int _gameId, void (*_Game_Update)(PGAME), void (*_Game_TimedUpdate)(PGAME), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent, int _playersCount, PPLAYER* _pPlayers)
{
    PGAME pGame = malloc(sizeof(GAME));

    pGame->gameId = _gameId;
    pGame->gameData = NULL;
    pGame->Game_Update = _Game_Update;
    pGame->Game_TimedUpdate = _Game_TimedUpdate;

    pGame->pCurrentGameId = _pCurrentGameId;
    pGame->pEvent = _pEvent;
    pGame->playersCount = _playersCount;
    pGame->pPlayers = _pPlayers;

    return pGame;
}

void Games_Update(PGAME* _pGames, int _gamesCount, int _currentGameId)
{
    if (_currentGameId == GAME_NONE)
    {
        return;
    }

    for (int i = 0; i < _gamesCount; i++)
    {
        if (_pGames[i]->gameId != _currentGameId)
        {
            continue;
        }

        if (_pGames[i]->Game_Update == NULL)
        {
            continue;
        }

        _pGames[i]->Game_Update(_pGames[i]);

        return;
    }
}

void Games_TimedUpdate(PGAME* _pGames, int _gamesCount, int _currentGameId)
{
    if (_currentGameId == GAME_NONE)
    {
        return;
    }

    for (int i = 0; i < _gamesCount; i++)
    {
        if (_pGames[i]->gameId != _currentGameId)
        {
            continue;
        }

        if (_pGames[i]->Game_TimedUpdate == NULL)
        {
            continue;
        }

        _pGames[i]->Game_TimedUpdate(_pGames[i]);

        return;
    }
}

void Players_Init(PPLAYER* _pPlayers, int _count)
{
    (*_pPlayers) = calloc(_count, sizeof(PLAYER));

    for (int i = 0; i < _count; i++)
    {
        (*_pPlayers)[i].name[0] = '\0';
        (*_pPlayers)[i].tickets = TICKET_START;
    }
}


PMAP Map_Init(int _gameId, void (*_Map_Update)(PMAP), void (*_Map_TimedUpdate)(PMAP), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent){
    PMAP pMap = malloc(sizeof(GAME));

    pMap->gameId = _gameId;
    pMap->MapData = NULL;
    pMap->Map_Update = _Map_Update;
    pMap->Map_TimedUpdate = _Map_TimedUpdate;

    pMap->pCurrentGameId = _pCurrentGameId;
    pMap->pEvent = _pEvent;

    return pMap;
}

void Maps_Update(PMAP* _pMaps, int _mapsCount,int _currentGameId){
    if (_currentGameId == GAME_NONE)
    {
        return;
    }

    for (int i = 0; i < _mapsCount; i++)
    {
        if (_pMaps[i]->gameId != _currentGameId)
        {
            continue;
        }
        //printf("Test\n");

        if (_pMaps[i]->Map_Update == NULL)
        {
            continue;
        }

        _pMaps[i]->Map_Update(_pMaps[i]);

        return;
    }
}

void Maps_TimedUpdate(PMAP* _pMaps, int _mapsCount, int _currentGameId){
    if (_currentGameId == GAME_NONE)
    {
        return;
    }

    for (int i = 0; i < _mapsCount; i++)
    {
        if (_pMaps[i]->gameId != _currentGameId)
        {
            continue;
        }

        if (_pMaps[i]->Map_TimedUpdate == NULL)
        {
            continue;
        }

        _pMaps[i]->Map_TimedUpdate(_pMaps[i]);

        return;
    }
}
