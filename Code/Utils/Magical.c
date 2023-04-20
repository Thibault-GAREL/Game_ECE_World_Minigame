#include "Magical.h"

PANIMATION Animation_Create(VECTOR2D_INT _position, int _stepInterval, int _deltaStep, int _pBitmapsCount, ALLEGRO_BITMAP** _pBitmaps)
{
    PANIMATION pAnimation = malloc(sizeof(ANIMATION));

    //BASIC SETTINGS: 
    pAnimation->position = _position;
    pAnimation->stepInterval = _stepInterval;
    pAnimation->deltaStep = _deltaStep;
    pAnimation->pBitmapsCount = _pBitmapsCount;
    pAnimation->pBitmaps = _pBitmaps;

    //ADVANCED SETTINGS:
    pAnimation->stepCurrent = 0;
    pAnimation->isPositionTargetEnabled = 0;
    pAnimation->isScaleFactorEnabled = 0;
    
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
    int bitmapNo = _pAnimation->stepCurrent / _pAnimation->stepInterval;
    
    if (bitmapNo >= _pAnimation->pBitmapsCount)
    {
        return;
    }
    
    VECTOR2D_INT position;

    if (_pAnimation->isPositionTargetEnabled)
    {
        position = *_pAnimation->positionTarget;
    }
    else
    {
        position = _pAnimation->position;
    }
    
    if (!_pAnimation->isScaleFactorEnabled)
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
    _pAnimation->stepCurrent += _pAnimation->deltaStep;
    int bitmapNo = _pAnimation->stepCurrent / _pAnimation->stepInterval;

    if (bitmapNo >= _pAnimation->pBitmapsCount)
    {
        _pAnimation->stepCurrent = 0;
    }
}

void Animation_Enable_PositionTarget(PANIMATION _pAnimation, PVECTOR2D_INT _positionTarget)
{
    _pAnimation->positionTarget = _positionTarget;
    _pAnimation->isPositionTargetEnabled = 1;
}

void Animation_Enable_ScaleFactor(PANIMATION _pAnimation, VECTOR2D_FLOAT _scaleFactor)
{
    _pAnimation->scaleFactor = _scaleFactor;
    _pAnimation->isScaleFactorEnabled = 1;
}