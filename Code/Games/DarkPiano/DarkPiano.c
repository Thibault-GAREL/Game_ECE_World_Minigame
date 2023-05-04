#include "DarkPiano.h"

void DarkPiano_Create(PGAME _pGame)
{
    PDP_DATA pDpData = (PDP_DATA)calloc(1, sizeof(DP_DATA));

    pDpData->ui.pBackground = al_load_bitmap("..\\Textures\\DarkPiano\\Bk.png");
    pDpData->ui.pFont50 = al_load_font("..\\Textures\\Fonts\\police.TTF", 50, 0);
    pDpData->ui.pFlecheIdle = al_load_bitmap("..\\Textures\\DarkPiano\\FlecheIdle.png");
    pDpData->ui.pFlecheAppuyee = al_load_bitmap("..\\Textures\\DarkPiano\\FlecheAppuyee.png");
    pDpData->ui.pFalse = al_load_bitmap("..\\Textures\\DarkPiano\\False.png");
    
    pDpData->speed = START_SPEED;
    pDpData->error = 0;
    pDpData->playerCurrent = 0;

    _pGame->gameData = pDpData;
}

void DarkPiano_Update(PGAME _pGame)
{    
    if (_pGame->gameData == NULL)
    {
        DarkPiano_Create(_pGame);
    }

    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    GameStateChecker(_pGame);

    if (Get_Touch(_pGame->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        DarkPiano_Destroy(_pGame);
        return;
    }

    pDpData->cordeInput[0] = Get_Touch(_pGame->pEvent, ALLEGRO_KEY_A, 0, 1, 0, 0);
    pDpData->cordeInput[1] = Get_Touch(_pGame->pEvent, ALLEGRO_KEY_Z, 0, 1, 0, 0);
    pDpData->cordeInput[2] = Get_Touch(_pGame->pEvent, ALLEGRO_KEY_E, 0, 1, 0, 0);
    pDpData->cordeInput[3] = Get_Touch(_pGame->pEvent, ALLEGRO_KEY_R, 0, 1, 0, 0);

    for (int i = 0; i < CORDE_NB; i++)
    {
        Note_Update(&pDpData->corde[i], &pDpData->error);

        if (Note_Get_MaxTop(pDpData->corde[i]) >= NOTE_START_POSITION && (rand() % NOTE_PROBA) == 0)
        {
            Note_Add(&pDpData->corde[i]);
        }
        if (!pDpData->corde[i])
        {
            Note_Add(&pDpData->corde[i]);
        }
        
        
        if (Note_IsTouch(&pDpData->corde[i], pDpData->cordeInput[i]) == 1)
        {
            pDpData->score++;
        }
        
        if (pDpData->corde[i] && pDpData->corde[i]->isTouch == -1 && pDpData->corde[i]->isErrored == 0)
        {
            pDpData->corde[i]->isErrored = 1;
            pDpData->error++;
        }
    }
}

void DarkPiano_TimedUpdate(PGAME _pGame)
{
    if (_pGame->gameData == NULL)
    {
        return;
    }

    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    if (pDpData->speed < MAX_SPEED)
    {
        pDpData->speed += ACCELERATION;
    }
    else
    {
        pDpData->speed = MAX_SPEED;
    }
    

    for (int i = 0; i < CORDE_NB; i++)
    {
        Note_Move(pDpData->corde[i],  pDpData->speed);
    }
    
    al_draw_bitmap(pDpData->ui.pBackground, -500, -500, 0);
    
    for (int i = 0; i < CORDE_NB; i++)
    {
        Note_Draw(pDpData->corde[i], (NOTE_ECART_X + NOTE_W)*i + NOTE_OFFSET_X, (NOTE_ECART_X + NOTE_W)*i + NOTE_W + NOTE_OFFSET_X);
    }

    DarkPiano_DrawUI(_pGame);
}

void DarkPiano_Destroy(PGAME _pGame)
{
    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    al_destroy_bitmap(pDpData->ui.pBackground);
    al_destroy_font(pDpData->ui.pFont50);

    al_destroy_bitmap(pDpData->ui.pFlecheIdle);
    al_destroy_bitmap(pDpData->ui.pFlecheAppuyee);
    al_destroy_bitmap(pDpData->ui.pFalse);
    
    for (int i = 0; i < CORDE_NB; i++)
    {
        Note_Destroy(pDpData->corde[i]);
    }

    free(_pGame->gameData);

    _pGame->gameData = NULL;

    *_pGame->pCurrentGameId = GAME_NONE;

    printf("DarkPiano correctly destroy\n");
}

void DarkPiano_DrawUI(PGAME _pGame)
{
    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    //Dessin de la ligne
    //al_draw_line(0, LINE_VALUE, 1920, LINE_VALUE, al_map_rgb(0, 255, 0), 1);

    //Dessin du score
    int score = pDpData->score > 9999 ? 9999 : pDpData->score;

    int scoreDec[4] = {0, 0, 0, 0};
    scoreDec[0] = score / 1000;
    scoreDec[1] = (score - scoreDec[0] * 1000) / 100;
    scoreDec[2] = (score - scoreDec[0] * 1000 - scoreDec[1]  * 100) / 10;
    scoreDec[3] = (score - scoreDec[0] * 1000 - scoreDec[1] * 100 - scoreDec[2] * 10);

    char zero = '0';
    char scoreStr[5] = "0000\0";

    for (size_t i = 0; i < 4; i++)
    {
        scoreStr[i] = scoreDec[i] + zero;
    }

    al_draw_text(pDpData->ui.pFont50, al_map_rgb(0, 0, 0), 850, 900, 0, scoreStr);

    //Dessin des fleche
    float scaleFactor = 0.1f;
    float scaleFactorF = 0.12f;

    for (int i = 0; i < CORDE_NB; i++)
    {   
        if (!pDpData->corde[i])
        {
            al_draw_scaled_rotated_bitmap(pDpData->ui.pFlecheIdle, 0, 0, (NOTE_ECART_X + NOTE_W)*i + FLECHE_OFFSET_X , LINE_VALUE, scaleFactor, scaleFactor, 0, 0);
        }
        else if (pDpData->corde[i]->isTouch == 1)
        {
            al_draw_scaled_rotated_bitmap(pDpData->ui.pFlecheAppuyee, 0, 0, (NOTE_ECART_X + NOTE_W)*i + FLECHE_OFFSET_X , LINE_VALUE, scaleFactor * 1.2f, scaleFactor * 1.2f, 0, 0);
        }
        else if (pDpData->corde[i] && pDpData->corde[i]->isTouch < - 0.5f)
        {
            al_draw_scaled_rotated_bitmap(pDpData->ui.pFalse, 0, 0, (NOTE_ECART_X + NOTE_W)*i + FLECHE_OFFSET_X, LINE_VALUE, scaleFactorF, scaleFactorF, 0, 0);
            pDpData->corde[i]->isTouch += 0.01f;
        }
        else if (pDpData->corde[i] && pDpData->corde[i]->isTouch < 0)
        {
            al_draw_scaled_rotated_bitmap(pDpData->ui.pFalse, 0, 0, (NOTE_ECART_X + NOTE_W)*i + FLECHE_OFFSET_X, LINE_VALUE, scaleFactorF * pDpData->corde[i]->isTouch * -2, scaleFactorF * pDpData->corde[i]->isTouch * -2, 0, 0);
            pDpData->corde[i]->isTouch += 0.01f;
        }
        else
        {
            pDpData->corde[i]->isErrored = 0;
            pDpData->corde[i]->isTouch = 0;
            al_draw_scaled_rotated_bitmap(pDpData->ui.pFlecheIdle, 0, 0, (NOTE_ECART_X + NOTE_W)*i + FLECHE_OFFSET_X , LINE_VALUE, scaleFactor, scaleFactor, 0, 0);
        }
    }

    //Dessin des erreurs
    for (int i = 0; i < pDpData->error; i++)
    {
        al_draw_scaled_rotated_bitmap(pDpData->ui.pFalse, 0, 0, i * 110 + 780, 950, 0.2f, 0.2f, 0, 0);
    }
    
}


void Note_Add(PNOTE* _ppFirstNote)
{
    if (*_ppFirstNote)
    {
        Note_Add(&(*_ppFirstNote)->pNext);
    }
    else
    {
        *_ppFirstNote = (PNOTE)calloc(1, sizeof(NOTE));
        
        (*_ppFirstNote)->bottom = NOTE_START_POSITION;
        (*_ppFirstNote)->top = (*_ppFirstNote)->bottom - (NOTE_MIN_SIZE + rand()%NOTE_MAX_SIZE);

        /*int top = -(NOTE_MIN_SIZE + rand()%NOTE_MAX_SIZE) - NOTE_START_POSITION;
        printf("New top = %d\n", top);
        (*_ppFirstNote)->top = top;*/
    }
}

void Note_Destroy(PNOTE _pNote)
{
    if (!_pNote)
    {
        return;
    }
    
    Note_Destroy(_pNote->pNext);
    free(_pNote);
}

void Note_Move(PNOTE _pNote, float _delta)
{
    if (!_pNote)
    {
        return;
    }
    
    _pNote->top += _delta;
    _pNote->bottom += _delta;

    Note_Move(_pNote->pNext, _delta);
}

void Note_Draw(PNOTE _pNote, int _x1, int _x2)
{
    if (!_pNote)
    {
        return;
    }
    
    Note_Draw(_pNote->pNext, _x1, _x2);

    if (_pNote->isTouch == 1)
    {
        al_draw_filled_rectangle(_x1 + NOTE_PP, _pNote->top + NOTE_PP, _x2 - NOTE_PP, _pNote->bottom - NOTE_PP, al_map_rgb(20, 255, 20));
    }
    else
    {
        al_draw_filled_rectangle(_x1, _pNote->top, _x2, _pNote->bottom, al_map_rgba(200, 200, 200, 150));
    }
}

int Note_Get_MaxTop(PNOTE _pNote)
{
    if (!_pNote)
    {
        //printf("ERROR: le pointeur de cette note est nulle !\n");
        return NOTE_START_POSITION;
    }
    
    if (_pNote->pNext)
    {
        return Note_Get_MaxTop(_pNote->pNext);
    }

    return _pNote->top;
}


int Note_IsTouch(PNOTE* _ppFirstNote, int _isPressed)
{
    if (!(*_ppFirstNote) || !_isPressed)
    {
        return 0;
    }
    
    if ((*_ppFirstNote)->top > LINE_VALUE)
    {
        return 0;
    }

    if ((*_ppFirstNote)->bottom < LINE_VALUE)
    {
        (*_ppFirstNote)->isTouch = -1;
         return 0;
    }
    
    if ((*_ppFirstNote)->isTouch == 1)
    {
        return 0;
    }
    
    (*_ppFirstNote)->isTouch = 1;
    
    return 1;
}

void Note_Update(PNOTE* _ppFirstNote, int* _pError)
{
    if (!(*_ppFirstNote))
    {
        return;
    }

    if ((*_ppFirstNote)->top > LINE_VALUE)
    {
        if ((*_ppFirstNote)->isTouch != 1)
        {
            (*_pError)++;
        }
        
        PNOTE pNoteBuffer = *_ppFirstNote;
        *_ppFirstNote = (*_ppFirstNote)->pNext;

        free(pNoteBuffer);
        return;
    }
}

void GameStateChecker(PGAME _pGame)
{
    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    if (pDpData->error >= ERROR_MAX)
    {
        if (++pDpData->playerCurrent >= _pGame->playersCount)
        {
            DarkPiano_Destroy(_pGame);
            return;
        }

        for (int i = 0; i < CORDE_NB; i++)
        {
            Note_Destroy(pDpData->corde[i]);
            pDpData->corde[i] = 0;
        }

        pDpData->speed = START_SPEED;
        pDpData->error = 0;

        for (int i = 0; i < 4; i++)
        {
            pDpData->cordeInput[i] = 0;
        }
        

        printf("Player = %d\n", pDpData->playerCurrent);
        printf("ticket=%d\n", _pGame->pPlayers[pDpData->playerCurrent]->tickets);
    }
    
}
