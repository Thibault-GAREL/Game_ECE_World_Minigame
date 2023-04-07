#ifndef ALLEGROUTILS_H
#define ALLEGROUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


void Allegro_Init();
ALLEGRO_EVENT_QUEUE* Init_Event(ALLEGRO_DISPLAY* _pDisplay, ALLEGRO_TIMER* _ptimer);
int Get_Touch(ALLEGRO_EVENT* _pEvent, int _keycode, int _default, int _down, int _up, int _char);

typedef struct _ALLEGRO_MANAGER
{
    ALLEGRO_DISPLAY* pDisplay;
    ALLEGRO_TIMER* pTimer;
    ALLEGRO_EVENT_QUEUE* pEventQueue;
}ALLEGRO_MANAGER, *PALLEGRO_MANAGER;

PALLEGRO_MANAGER AllegroManager_Create(int _dw, int _dh, double _timeSpeed);
void AllegroManager_Destroy(PALLEGRO_MANAGER _pAllegroManager);

#endif