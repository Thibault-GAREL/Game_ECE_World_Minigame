#include "Magical.h"

PANIMATION Animation_Create(VECTOR2D_INT _position, int _bitmapDuration, int _deltaStep, int _pBitmapsCount, ALLEGRO_BITMAP** _pBitmaps)
{
    PANIMATION pAnimation = malloc(sizeof(ANIMATION));

    //BASIC SETTINGS: 
    pAnimation->position = _position;
    pAnimation->bitmapDuration = _bitmapDuration;
    pAnimation->deltaStep = _deltaStep;
    pAnimation->pBitmapsCount = _pBitmapsCount;
    pAnimation->pBitmaps = _pBitmaps;

    //ADVANCED SETTINGS:
    pAnimation->currentStep = ANIMATION_STATE_REPLAY;

    pAnimation->isPositionTargetEnable = DISABLE;
    pAnimation->isScaleFactorEnable = DISABLE;
    pAnimation->isStartStateEnable = DISABLE;
    pAnimation->isStartTriggerBOOLEnable = DISABLE;
    
    return pAnimation;
}

void Animation_Destroy(PANIMATION _pAnimation)
{
    for (int i = 0; i < _pAnimation->pBitmapsCount; i++)
    {
        al_destroy_bitmap(_pAnimation->pBitmaps[i]);
    }
    
    free(_pAnimation);
}

void Animation_Draw(PANIMATION _pAnimation)
{
    int bitmapNo = _pAnimation->currentStep / _pAnimation->bitmapDuration;

    bitmapNo = bitmapNo < 0 ? 0 : bitmapNo;

    if (bitmapNo >= _pAnimation->pBitmapsCount)
    {
        return;
    }
    
    VECTOR2D_INT position;

    if (_pAnimation->isPositionTargetEnable == ENABLE)
    {
        position = *_pAnimation->positionTarget;
    }
    else
    {
        position = _pAnimation->position;
    }
    
    if (_pAnimation->isScaleFactorEnable == DISABLE)
    {
        al_draw_bitmap(_pAnimation->pBitmaps[bitmapNo], position.x, position.y, 0);
    }

    VECTOR2D_INT bitmapSize;
    bitmapSize.x = al_get_bitmap_width(_pAnimation->pBitmaps[bitmapNo]);
    bitmapSize.y = al_get_bitmap_height(_pAnimation->pBitmaps[bitmapNo]);

    al_draw_scaled_bitmap(_pAnimation->pBitmaps[bitmapNo], 0, 0, bitmapSize.x, bitmapSize.y, position.x, position.y, bitmapSize.x * _pAnimation->scaleFactor.x, bitmapSize.y * _pAnimation->scaleFactor.y, 0);
}

void Animation_Update_Step(PANIMATION _pAnimation)
{    
    if (_pAnimation->currentStep < ANIMATION_STATE_REPLAY)
    {
        if (_pAnimation->isStartTriggerBOOLEnable == DISABLE)
        {
            return;
        }

        if (_pAnimation->pStartTriggerBOOL <= 0)
        {
            return;
        }
        
        _pAnimation->currentStep = ANIMATION_STATE_REPLAY;
    }
    
    _pAnimation->currentStep += _pAnimation->deltaStep;
    int bitmapNo = _pAnimation->currentStep / _pAnimation->bitmapDuration;

    if (bitmapNo >= _pAnimation->pBitmapsCount)
    {
        _pAnimation->currentStep = _pAnimation->isStartStateEnable ? _pAnimation->startState : ANIMATION_STATE_REPLAY;
    }
}

void Animation_Enable_PositionTarget(PANIMATION _pAnimation, PVECTOR2D_INT _positionTarget)
{
    _pAnimation->positionTarget = _positionTarget;
    _pAnimation->isPositionTargetEnable = ENABLE;
}

void Animation_Enable_ScaleFactor(PANIMATION _pAnimation, Vector2D _scaleFactor)
{
    _pAnimation->scaleFactor = _scaleFactor;
    _pAnimation->isScaleFactorEnable = ENABLE;
}

void Animation_Enable_StartState(PANIMATION _pAnimation, int _startStepValue)
{
    _pAnimation->startState = _startStepValue;
    _pAnimation->isStartStateEnable = ENABLE;
}

void Animation_Enable_StartTrigger(PANIMATION _pAnimation, int* _pStartTriggerBOOL)
{
    _pAnimation->pStartTriggerBOOL = _pStartTriggerBOOL;
    _pAnimation->isStartTriggerBOOLEnable = ENABLE;
}
