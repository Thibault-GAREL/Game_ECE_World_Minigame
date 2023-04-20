#pragma once

#include "allegroutils.h"
#include "Magical.h"

enum
{
    ELEMENT_NONE = 0,
    ELEMENT_TEXT = 1,
    ELEMENT_IMAGE = 2,
    ELEMENT_ANIMATION = 3,
    ELEMENT_BUTTON = 4
};

typedef union _ELEMENT
{
    PANIMATION pAnimation;

}ELEMENT, *PELEMENT;

typedef struct _UI_ELEMENT
{
    int type;
    ELEMENT element;
}UI_ELEMENT, *PUI_ELEMENT;


typedef struct _PANEL
{
    //BASIC SETTINGS:
    
    VECTOR2D_INT position;
    unsigned int uiElementsCount;
    PUI_ELEMENT* pUiElements;

    //ADVANCED SETTINGS:

    int isEnable;
    /*
    PVECTOR2D_INT positionTarget;
    char isPositionTargetEnabled;
    */
}PANEL, *PPANEL;

PUI_ELEMENT UiElement_Create(int _type, ELEMENT _element);
void UiElement_Destroy(PUI_ELEMENT _pUiElement);
void UiElement_Draw(PUI_ELEMENT _pUiElement);
void UiElement_Update(PUI_ELEMENT _pUiElement);

PPANEL Panel_Create();
void Panel_Destroy(PPANEL _pPanel);

void Panel_Add_UiElement(PPANEL _pPanel, PUI_ELEMENT _pUiElement);
void Panel_Remove_UiElement(PPANEL _pPanel, int _no, int _destroy);

void Panel_Draw(PPANEL _pPanel);
void Panel_Update(PPANEL _pPanel);
