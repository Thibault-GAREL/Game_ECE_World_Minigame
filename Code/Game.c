#include "Game.h"

PGAME Game_Init(int _gameId, void (*_Game_Update)(PGAME), void (*_Game_TimedUpdate)(PGAME), int* _pCurrentGameId, ALLEGRO_EVENT* _pEvent, PPLAYER* _pPlayers)
{
    PGAME pGame = malloc(sizeof(GAME));

    pGame->gameId = _gameId;
    pGame->gameData = NULL;
    pGame->Game_Update = _Game_Update;
    pGame->Game_TimedUpdate = _Game_TimedUpdate;

    pGame->pCurrentGameId = _pCurrentGameId;
    pGame->pEvent = _pEvent;
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
        printf("Test\n");

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