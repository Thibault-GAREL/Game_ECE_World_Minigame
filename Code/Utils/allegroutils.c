#include "allegroutils.h"

void Allegro_Init()
{
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_image_addon());
    assert(al_install_keyboard());
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_acodec_addon();
    al_install_audio();
}

ALLEGRO_EVENT_QUEUE* Init_Event(ALLEGRO_DISPLAY* _pDisplay, ALLEGRO_TIMER* _ptimer)
{
    ALLEGRO_EVENT_QUEUE* pEvq = al_create_event_queue();
    al_register_event_source(pEvq, al_get_display_event_source(_pDisplay));
    al_register_event_source(pEvq, al_get_keyboard_event_source());
    al_register_event_source(pEvq, al_get_timer_event_source(_ptimer));
    al_register_event_source(pEvq, al_get_mouse_event_source());
    return pEvq;
}

int Get_Touch(ALLEGRO_EVENT* _pEvent, int _keycode, int _default, int _down, int _up, int _char)
{
    if (_pEvent->keyboard.keycode != _keycode)
    {
        return _default;
    }
    if (_pEvent->keyboard.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        return _down;
    }
    if (_pEvent->keyboard.type == ALLEGRO_EVENT_KEY_UP)
    {
        return _up;
    }

    return _char;
}

PALLEGRO_MANAGER AllegroManager_Create(int _dw, int _dh, double _timeSpeed)
{
    PALLEGRO_MANAGER pAllegroManager = malloc(sizeof(ALLEGRO_MANAGER));
    pAllegroManager->pSample = Allegro_Samples_Create(Audio_Samples_Count);
    pAllegroManager->pDisplay =  al_create_display(_dw, _dh);
    pAllegroManager->pTimer = al_create_timer(_timeSpeed);
    al_start_timer(pAllegroManager->pTimer);
    pAllegroManager->pEventQueue = Init_Event(pAllegroManager->pDisplay, pAllegroManager->pTimer);

    return pAllegroManager;
}

void AllegroManager_Destroy(PALLEGRO_MANAGER _pAllegroManager)
{
    al_destroy_display(_pAllegroManager->pDisplay);
    al_destroy_timer(_pAllegroManager->pTimer);
    al_destroy_event_queue(_pAllegroManager->pEventQueue);
    Allegro_Samples_Destroy(_pAllegroManager->pSample);
    free(_pAllegroManager);
}

PALLEGRO_GAME_SAMPLE Allegro_Samples_Create(){
    al_reserve_samples(Audio_Samples_Count);
    PALLEGRO_GAME_SAMPLE pSample = malloc (sizeof (ALLEGRO_MANAGER));

    pSample->walk = al_load_sample("..\\Audio-Samples\\Mario_sample.ogg");

    return pSample;
}

void Allegro_Samples_Destroy(PALLEGRO_GAME_SAMPLE _pAllegroSample){
    al_destroy_sample(_pAllegroSample->walk);
    al_destroy_sample(_pAllegroSample->click);
    al_destroy_sample(_pAllegroSample->shot);
    al_destroy_sample(_pAllegroSample->duck);
    al_destroy_sample(_pAllegroSample->car);
    al_destroy_sample(_pAllegroSample->snake);
    al_destroy_sample(_pAllegroSample->balloon);
    free (_pAllegroSample);
}

void InitSample (PALLEGRO_GAME_SAMPLES_ID _pSample){

}

void Allegro_play_Sample (ALLEGRO_SAMPLE* _pSample){
    al_play_sample(_pSample, 1, 1, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Allegro_Stop_Sample (ALLEGRO_SAMPLE* _pSample){
    al_stop_sample(_pSample);
}
