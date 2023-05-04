#ifndef ALLEGROUTILS_H
#define ALLEGROUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define Audio_Samples_Count 20

void Allegro_Init();
ALLEGRO_EVENT_QUEUE* Init_Event(ALLEGRO_DISPLAY* _pDisplay, ALLEGRO_TIMER* _ptimer);
int Get_Touch(ALLEGRO_EVENT* _pEvent, int _keycode, int _default, int _down, int _up, int _char);


typedef struct _ALLEGRO_SAMPLES
{
    ALLEGRO_SAMPLE *PACMenu;
    ALLEGRO_SAMPLE *PACGame;
    ALLEGRO_SAMPLE *PACEXplode;
    ALLEGRO_SAMPLE *PACEasterEgg;
    ALLEGRO_SAMPLE *PACCredits;

    ALLEGRO_SAMPLE *TDLR_Menu;
    ALLEGRO_SAMPLE *TDLR_Degats;
    ALLEGRO_SAMPLE *TDLR_Fin;

    ALLEGRO_SAMPLE *walk;
    ALLEGRO_SAMPLE *click;
    ALLEGRO_SAMPLE *shot;
    ALLEGRO_SAMPLE *duck;
    ALLEGRO_SAMPLE *car;
    ALLEGRO_SAMPLE *snake;
    ALLEGRO_SAMPLE *balloon;

    ALLEGRO_SAMPLE *mj;
}ALLEGRO_GAME_SAMPLE, *PALLEGRO_GAME_SAMPLE;

typedef struct _ALLEGRO_SAMPLES_INSTANCE
{
    ALLEGRO_SAMPLE_INSTANCE *PACMenu;
    ALLEGRO_SAMPLE_INSTANCE *PACGame;
    ALLEGRO_SAMPLE_INSTANCE *PACEXplode;
    ALLEGRO_SAMPLE_INSTANCE *PACEasterEgg;
    ALLEGRO_SAMPLE_INSTANCE *PACCredits;

    ALLEGRO_SAMPLE_INSTANCE *TDLR_Menu;
    ALLEGRO_SAMPLE_INSTANCE *TDLR_Degats;
    ALLEGRO_SAMPLE_INSTANCE *TDLR_Fin;

    ALLEGRO_SAMPLE_INSTANCE *walk;
    ALLEGRO_SAMPLE_INSTANCE *click;
    ALLEGRO_SAMPLE_INSTANCE *shot;
    ALLEGRO_SAMPLE_INSTANCE *duck;
    ALLEGRO_SAMPLE_INSTANCE *car;
    ALLEGRO_SAMPLE_INSTANCE *snake;
    ALLEGRO_SAMPLE_INSTANCE *balloon;

    ALLEGRO_SAMPLE_INSTANCE *mj;
}ALLEGRO_GAME_SAMPLES_INSTANCE, *PALLEGRO_GAME_SAMPLES_INSTANCE;

typedef struct _ALLEGRO_MOUSE_CURSOR{
    ALLEGRO_MOUSE_CURSOR *PACSight;

    ALLEGRO_MOUSE_CURSOR *Cursor1;
    //ALLEGRO_MOUSE_CURSOR *Cursor2;
    //ALLEGRO_MOUSE_CURSOR *Cursor3;
    //ALLEGRO_MOUSE_CURSOR *Cursor4;
    //ALLEGRO_MOUSE_CURSOR *Cursor5;
    //ALLEGRO_MOUSE_CURSOR *Cursor6;
    //ALLEGRO_MOUSE_CURSOR *Cursor7;
}ALLEGRO_CURSOR, *PALLEGRO_CURSOR;


typedef struct _ALLEGRO_MANAGER
{
    ALLEGRO_DISPLAY* pDisplay;
    ALLEGRO_TIMER* pTimer;
    ALLEGRO_EVENT_QUEUE* pEventQueue;
    ALLEGRO_GAME_SAMPLE* pSample;
    ALLEGRO_GAME_SAMPLES_INSTANCE* pSampleInstance;
    ALLEGRO_CURSOR *pCursors;
    void* pMenu;
}ALLEGRO_MANAGER, *PALLEGRO_MANAGER;



PALLEGRO_MANAGER AllegroManager_Create(int _dw, int _dh, double _timeSpeed);
void AllegroManager_Destroy(PALLEGRO_MANAGER _pAllegroManager);
PALLEGRO_GAME_SAMPLE Allegro_Samples_Create();
void Allegro_Samples_Destroy(PALLEGRO_GAME_SAMPLE _pAllegroSample);
void Allegro_Samples_Instance_Destroy(ALLEGRO_GAME_SAMPLES_INSTANCE* pSampleInstance);
void Allegro_play_Sample (ALLEGRO_SAMPLE_INSTANCE * _pSample);
void Allegro_Stop_Sample (ALLEGRO_SAMPLE_INSTANCE * _pSample);
PALLEGRO_GAME_SAMPLES_INSTANCE InitSample (ALLEGRO_GAME_SAMPLE * pSample);
void SetSampleInstance(ALLEGRO_GAME_SAMPLES_INSTANCE* pSampleInstance);
PALLEGRO_CURSOR InitCursors();
void Destroy_cursors(PALLEGRO_CURSOR pCursor);
void ChangeCursor (PALLEGRO_MANAGER pAlManager, ALLEGRO_MOUSE_CURSOR *pMouseCursor);
void HideCursor (PALLEGRO_MANAGER pAlManager);

#endif