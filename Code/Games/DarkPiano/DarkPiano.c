#include "DarkPiano.h"

void DarkPiano_Create(PGAME _pGame)
{
    PDP_DATA pDpData = (PDP_DATA)calloc(1, sizeof(DP_DATA));

    pDpData->ui.pBackground = al_load_bitmap("..\\Textures\\DarkPiano\\Bk.png");
    pDpData->ui.pFont50 = al_load_font("..\\Textures\\Fonts\\police.TTF", 50, 0);
    
    _pGame->gameData = pDpData;
}

void DarkPiano_Update(PGAME _pGame)
{    
    if (_pGame->gameData == NULL)
    {
        DarkPiano_Create(_pGame);
    }

    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    if (Get_Touch(_pGame->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        DarkPiano_Destroy(_pGame);
    }

    for (int i = 0; i < CORDE_NB; i++)
    {
        if (Note_UpdateANDIsTouch(&pDpData->corde[i], 0))
        {
            pDpData->score++;
            printf("Touchee\n");
        }
        
        if (Note_Get_MaxTop(pDpData->corde[i]) >= NOTE_START_POSITION && (rand() % NOTE_PROBA) == 0)
        {
            Note_Add(&pDpData->corde[i]);
            printf("Nouvelle note\n");
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

    for (int i = 0; i < CORDE_NB; i++)
    {
        Note_Move(pDpData->corde[i], DELTA);
    }
    
    al_draw_bitmap(pDpData->ui.pBackground, -500, -500, 0);
    
    for (int i = 0; i < CORDE_NB; i++)
    {
        Note_Draw(pDpData->corde[i], 100*i, 100*i + 50);
    }

    DarkPiano_DrawUI(_pGame);
}

void DarkPiano_Destroy(PGAME _pGame)
{
    PDP_DATA pDpData = (PDP_DATA)_pGame->gameData;

    al_destroy_bitmap(pDpData->ui.pBackground);
    al_destroy_font(pDpData->ui.pFont50);
    
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

    al_draw_line(0, LINE_VALUE, 1920, LINE_VALUE, al_map_rgb(0, 255, 0), 1);

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
        (*_ppFirstNote)->top = -(NOTE_MIN_SIZE + rand()%NOTE_MAX_SIZE) - NOTE_START_POSITION;

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
    
    al_draw_filled_rectangle(_x1, _pNote->top, _x2, _pNote->bottom, al_map_rgb(255, 0, 0));

    Note_Draw(_pNote->pNext, _x1, _x2);
}

int Note_Get_MaxTop(PNOTE _pNote)
{
    if (!_pNote)
    {
        printf("ERROR: le pointeur de cette note est nulle !\n");
        return NOTE_START_POSITION;
    }
    
    if (_pNote->pNext)
    {
        return Note_Get_MaxTop(_pNote->pNext);
    }

    return _pNote->top;
}

int Note_UpdateANDIsTouch(PNOTE* _ppFirstNote, int _isPressed)
{
    if (!(*_ppFirstNote))
    {
        return 0;
    }
    
    if ((*_ppFirstNote)->bottom < LINE_VALUE)
    {
        return 0;
    }

    if ((*_ppFirstNote)->top > LINE_VALUE)
    {
        PNOTE pNoteBuffer = *_ppFirstNote;
        *_ppFirstNote = (*_ppFirstNote)->pNext;

        free(pNoteBuffer);
        return 0;
    }

    if (!_isPressed)
    {
        return 0;
    }

    PNOTE pNoteBuffer = *_ppFirstNote;
    *_ppFirstNote = (*_ppFirstNote)->pNext;

    free(pNoteBuffer);
    return 1;
}
