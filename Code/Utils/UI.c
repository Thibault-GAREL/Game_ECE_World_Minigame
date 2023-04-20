#include "UI.h"


/*
    --- UI_ELEMENT ---
*/

PUI_ELEMENT UiElement_Create(int _type, ELEMENT _element)
{
    PUI_ELEMENT pUiElement = malloc(sizeof(UI_ELEMENT));
    pUiElement->type = _type;
    pUiElement->element = _element;
    return pUiElement;
}

void UiElement_Destroy(PUI_ELEMENT _pUiElement)
{
    free(_pUiElement);
}

void UiElement_Draw(PUI_ELEMENT _pUiElement)
{
    if (_pUiElement->type == ELEMENT_ANIMATION)
    {
        Animation_Draw(_pUiElement->element.pAnimation);
        return;
    }
}

void UiElement_Update(PUI_ELEMENT _pUiElement)
{
    if (_pUiElement->type == ELEMENT_ANIMATION)
    {
        Animation_Update_Step(_pUiElement->element.pAnimation);
        return;
    }
}


/*
    --- PANEL ---
*/

PPANEL Panel_Create()
{
    PPANEL pPanel = malloc(sizeof(PANEL));

    assert(pPanel);

    pPanel->position = (VECTOR2D_INT){0,0};
    pPanel->uiElementsCount = 0;
    pPanel->pUiElements = NULL;
    pPanel->isEnable = 1;

    return pPanel;
}

void Panel_Destroy(PPANEL _pPanel)
{
    for (int i = 0; i < _pPanel->uiElementsCount; i++)
    {
        Panel_Remove_UiElement(_pPanel, _pPanel->uiElementsCount - 1, true);
    }

    free(_pPanel);
}

void Panel_Add_UiElement(PPANEL _pPanel, PUI_ELEMENT _pUiElement)
{
    _pPanel->pUiElements = realloc(_pPanel->pUiElements, sizeof(PUI_ELEMENT) * ++_pPanel->uiElementsCount);
    _pPanel->pUiElements[_pPanel->uiElementsCount - 1] = _pUiElement;
}

void Panel_Remove_UiElement(PPANEL _pPanel, int _no, int _destroy)
{
    if (_destroy)
    {
        free(_pPanel->pUiElements[_no]);
    }

    _pPanel->uiElementsCount--;

    for (int i = _no; i < _pPanel->uiElementsCount; i++)
    {
        _pPanel->pUiElements[i] = _pPanel->pUiElements[i + 1];
    }

    _pPanel->pUiElements = realloc(_pPanel->pUiElements, sizeof(PUI_ELEMENT) * _pPanel->uiElementsCount);
}

void Panel_Draw(PPANEL _pPanel)
{
    if (!_pPanel->isEnable)
    {
        return;
    }
    
    for (int i = 0; i < _pPanel->uiElementsCount; i++)
    {
        UiElement_Draw(_pPanel->pUiElements[i]);
    }
}

void Panel_Update(PPANEL _pPanel)
{
    if (!_pPanel->isEnable)
    {
        return;
    }
    
    for (int i = 0; i < _pPanel->uiElementsCount; i++)
    {
        UiElement_Update(_pPanel->pUiElements[i]);
    }
}