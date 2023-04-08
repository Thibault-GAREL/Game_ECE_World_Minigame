#ifndef ALLEGROUTILS_H
#define ALLEGROUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define Audio_Samples_Count 10

void Allegro_Init();
ALLEGRO_EVENT_QUEUE* Init_Event(ALLEGRO_DISPLAY* _pDisplay, ALLEGRO_TIMER* _ptimer);
int Get_Touch(ALLEGRO_EVENT* _pEvent, int _keycode, int _default, int _down, int _up, int _char);

typedef struct _ALLEGRO_SAMPLES
{
    ALLEGRO_SAMPLE *walk;
    ALLEGRO_SAMPLE *click;
    ALLEGRO_SAMPLE *shot;
    ALLEGRO_SAMPLE *duck;
    ALLEGRO_SAMPLE *car;
    ALLEGRO_SAMPLE *snake;
    ALLEGRO_SAMPLE *balloon;
    ALLEGRO_SAMPLE_INSTANCE *SampleInstance;
}ALLEGRO_GAME_SAMPLE, *PALLEGRO_GAME_SAMPLE;



typedef struct _ALLEGRO_MANAGER
{
    ALLEGRO_DISPLAY* pDisplay;
    ALLEGRO_TIMER* pTimer;
    ALLEGRO_EVENT_QUEUE* pEventQueue;
    ALLEGRO_GAME_SAMPLE* pSample;
}ALLEGRO_MANAGER, *PALLEGRO_MANAGER;

typedef struct _ALLEGRO_SAMPLES_ID
{
    ALLEGRO_SAMPLE_ID walk;
    ALLEGRO_SAMPLE_ID click;
    ALLEGRO_SAMPLE_ID shot;
    ALLEGRO_SAMPLE_ID duck;
    ALLEGRO_SAMPLE_ID car;
    ALLEGRO_SAMPLE_ID snake;
    ALLEGRO_SAMPLE_ID balloon;
}ALLEGRO_GAME_SAMPLES_ID, *PALLEGRO_GAME_SAMPLES_ID;


PALLEGRO_MANAGER AllegroManager_Create(int _dw, int _dh, double _timeSpeed);
void AllegroManager_Destroy(PALLEGRO_MANAGER _pAllegroManager);
PALLEGRO_GAME_SAMPLE Allegro_Samples_Create();
void Allegro_Samples_Destroy(PALLEGRO_GAME_SAMPLE _pAllegroSample);
void Allegro_play_Sample (ALLEGRO_SAMPLE* _pSample);
void Allegro_Stop_Sample (ALLEGRO_SAMPLE* _pSample);

#endif
