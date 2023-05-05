#include "JeuBonus.h"


void Bonus_Create(PGAME _pBonus)
{
    BonusData* pBonusData = malloc(sizeof (BonusData));
    _pBonus->gameData = pBonusData;
}

void Bonus_Update(PGAME _pBonus)
{
    if (!_pBonus->gameData)
    {
        Bonus_Create(_pBonus);
    }
    BonusData* pBonusData = _pBonus->gameData;
    if (_pBonus->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pBonusData->mouse.x = _pBonus->pEvent->mouse.x*1.25;
        pBonusData->mouse.y = _pBonus->pEvent->mouse.y*1.25;
    }
    if ( _pBonus->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        pBonusData->click=1;
    }
    if (_pBonus->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        pBonusData->click=0;
    }
}

void Bonus_TimedUpdate(PGAME _pBonus) {
    BonusData *pBonusData = _pBonus->gameData;
}

void Bonus_Destroy(PGAME _pBonus){
    free(_pBonus->gameData);
    _pBonus->gameData = NULL;
}