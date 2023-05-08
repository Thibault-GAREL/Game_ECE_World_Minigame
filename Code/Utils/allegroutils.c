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

    pAllegroManager->pSampleInstance = InitSample(pAllegroManager->pSample);

    pAllegroManager->pCursors = InitCursors();

    pAllegroManager->MusicGain = 1;
    pAllegroManager->SFXGain = 1;

    SetSampleInstance(pAllegroManager->pSampleInstance, pAllegroManager);
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
    Allegro_Samples_Instance_Destroy(_pAllegroManager->pSampleInstance);
    Allegro_Samples_Destroy(_pAllegroManager->pSample);
    Destroy_cursors(_pAllegroManager->pCursors);
    free(_pAllegroManager);
}

PALLEGRO_GAME_SAMPLES_INSTANCE InitSample (ALLEGRO_GAME_SAMPLE* pSample){
    PALLEGRO_GAME_SAMPLES_INSTANCE pSample_Instance = malloc(sizeof (ALLEGRO_GAME_SAMPLES_INSTANCE));

    pSample_Instance->PACMenu = al_create_sample_instance(pSample->PACMenu);
    pSample_Instance->PACGame = al_create_sample_instance(pSample->PACGame);
    pSample_Instance->PACEXplode = al_create_sample_instance(pSample->PACEXplode);
    pSample_Instance->PACEasterEgg = al_create_sample_instance(pSample->PACEasterEgg);
    pSample_Instance->PACCredits = al_create_sample_instance(pSample->PACCredits);

    pSample_Instance->TDLR_Menu = al_create_sample_instance(pSample->TDLR_Menu);
    pSample_Instance->TDLR_Degats = al_create_sample_instance(pSample->TDLR_Degats);
    pSample_Instance->TDLR_Fin = al_create_sample_instance(pSample->TDLR_Fin);

    pSample_Instance->FBMenu = al_create_sample_instance(pSample->FBMenu);
    pSample_Instance->FBGame = al_create_sample_instance(pSample->FBGame);
    pSample_Instance->FBDeath = al_create_sample_instance(pSample->FBDeath);

    pSample_Instance->mj= al_create_sample_instance(pSample->mj);

    pSample_Instance->walk = al_create_sample_instance(pSample->walk);
    //pSample_Instance->click = al_create_sample_instance(pSample->click);
    //pSample_Instance->shot = al_create_sample_instance(pSample->shot);
    //pSample_Instance->duck = al_create_sample_instance(pSample->duck);
    //pSample_Instance->car = al_create_sample_instance(pSample->car);
    //pSample_Instance->snake = al_create_sample_instance(pSample->snake);
    //pSample_Instance->balloon = al_create_sample_instance(pSample->balloon);

    return pSample_Instance;
}

void SetSampleInstance(ALLEGRO_GAME_SAMPLES_INSTANCE* pSampleInstance, ALLEGRO_MANAGER *pAllegroManager){
    al_set_sample_instance_playmode(pSampleInstance->PACMenu, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(pSampleInstance->PACGame, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(pSampleInstance->PACEXplode, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(pSampleInstance->PACEasterEgg, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(pSampleInstance->PACCredits, ALLEGRO_PLAYMODE_LOOP);

    al_set_sample_instance_playmode(pSampleInstance->walk, ALLEGRO_PLAYMODE_ONCE);

    al_set_sample_instance_playmode(pSampleInstance->TDLR_Menu, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(pSampleInstance->TDLR_Fin, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(pSampleInstance->TDLR_Degats, ALLEGRO_PLAYMODE_ONCE);

    al_set_sample_instance_playmode(pSampleInstance->FBMenu, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(pSampleInstance->FBGame, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(pSampleInstance->FBDeath, ALLEGRO_PLAYMODE_ONCE);

    al_set_sample_instance_playmode(pSampleInstance->mj,ALLEGRO_PLAYMODE_ONCE);

    al_attach_sample_instance_to_mixer(pSampleInstance->PACMenu, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->PACGame, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->PACEXplode, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->PACEasterEgg, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->PACCredits, al_get_default_mixer());

    al_attach_sample_instance_to_mixer(pSampleInstance->TDLR_Menu, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->TDLR_Fin, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->TDLR_Degats, al_get_default_mixer());

    al_attach_sample_instance_to_mixer(pSampleInstance->FBGame, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->FBMenu, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(pSampleInstance->FBDeath, al_get_default_mixer());

    al_attach_sample_instance_to_mixer(pSampleInstance->walk, al_get_default_mixer());
    //al_attach_sample_instance_to_mixer(pSampleInstance->click, al_get_default_mixer());
    //al_attach_sample_instance_to_mixer(pSampleInstance->shot, al_get_default_mixer());
    //al_attach_sample_instance_to_mixer(pSampleInstance->duck, al_get_default_mixer());
    //al_attach_sample_instance_to_mixer(pSampleInstance->car, al_get_default_mixer());
    //al_attach_sample_instance_to_mixer(pSampleInstance->snake, al_get_default_mixer());
    //al_attach_sample_instance_to_mixer(pSampleInstance->balloon, al_get_default_mixer());

    al_attach_sample_instance_to_mixer(pSampleInstance->mj,al_get_default_mixer());
}

void Set_New_Sample_Instance(ALLEGRO_MANAGER *pAllegroManager){

    //Gain for Musics

    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->PACMenu, pAllegroManager->MusicGain);
    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->PACGame, pAllegroManager->MusicGain);
    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->PACCredits, pAllegroManager->MusicGain);

    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->TDLR_Menu, pAllegroManager->MusicGain);
    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->TDLR_Fin, pAllegroManager->MusicGain);

    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->FBMenu, pAllegroManager->MusicGain);


    //Gain for SFX

    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->PACEXplode, pAllegroManager->SFXGain);
    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->PACEasterEgg, pAllegroManager->SFXGain);
    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->TDLR_Degats, pAllegroManager->MusicGain);

    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->mj, pAllegroManager->MusicGain);

    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->FBDeath, pAllegroManager->SFXGain);
    al_set_sample_instance_gain(pAllegroManager->pSampleInstance->FBGame, pAllegroManager->SFXGain);
}


PALLEGRO_GAME_SAMPLE Allegro_Samples_Create(){
    al_reserve_samples(Audio_Samples_Count);
    PALLEGRO_GAME_SAMPLE pSample = malloc (sizeof (ALLEGRO_GAME_SAMPLE));

    pSample->PACMenu = al_load_sample("..\\Audio-Samples\\PAC\\Menu.ogg");
    pSample->PACGame = al_load_sample("..\\Audio-Samples\\PAC\\Game.ogg");
    pSample->PACEXplode = al_load_sample("..\\Audio-Samples\\PAC\\Explode.ogg");
    pSample->PACEasterEgg = al_load_sample("..\\Audio-Samples\\PAC\\Easter Egg.ogg");
    pSample->PACCredits = al_load_sample("..\\Audio-Samples\\PAC\\Credits.ogg");

    pSample->TDLR_Menu = al_load_sample("..\\Audio-Samples\\TDLR\\Musique_Menu.ogg");
    pSample->TDLR_Fin = al_load_sample("..\\Audio-Samples\\TDLR\\Musique_Fin.ogg");
    pSample->TDLR_Degats = al_load_sample("..\\Audio-Samples\\TDLR\\Musique_Degat.ogg");

    pSample->walk = al_load_sample("..\\Audio-Samples\\Mario_sample.ogg");

    pSample->mj = al_load_sample("..\\Audio-Samples\\MJSONG.ogg");

    pSample->FBMenu = al_load_sample("..\\Audio-Samples\\FB\\Menu.ogg");
    pSample->FBGame = al_load_sample("..\\Audio-Samples\\FB\\Game.ogg");
    pSample->FBDeath = al_load_sample("..\\Audio-Samples\\FB\\Death.ogg");

    //pSample->balloon = NULL;

    return pSample;
}

void Allegro_Samples_Destroy(PALLEGRO_GAME_SAMPLE _pAllegroSample)
{
    al_destroy_sample(_pAllegroSample->PACMenu);
    al_destroy_sample(_pAllegroSample->PACGame);
    al_destroy_sample(_pAllegroSample->PACEXplode);
    al_destroy_sample(_pAllegroSample->PACEasterEgg);
    al_destroy_sample(_pAllegroSample->PACCredits);

    al_destroy_sample(_pAllegroSample->TDLR_Menu);
    al_destroy_sample(_pAllegroSample->TDLR_Degats);
    al_destroy_sample(_pAllegroSample->TDLR_Fin);

    al_destroy_sample(_pAllegroSample->FBGame);
    al_destroy_sample(_pAllegroSample->FBDeath);
    al_destroy_sample(_pAllegroSample->FBMenu);

    /*al_destroy_sample(_pAllegroSample->walk);
    al_destroy_sample(_pAllegroSample->click);
    al_destroy_sample(_pAllegroSample->shot);
    al_destroy_sample(_pAllegroSample->duck);
    al_destroy_sample(_pAllegroSample->car);
    al_destroy_sample(_pAllegroSample->snake);
    al_destroy_sample(_pAllegroSample->balloon);*/

    al_destroy_sample(_pAllegroSample->mj);
    free (_pAllegroSample);
}

void Allegro_Samples_Instance_Destroy(ALLEGRO_GAME_SAMPLES_INSTANCE* pSampleInstance){
    al_destroy_sample_instance(pSampleInstance->PACMenu);
    al_destroy_sample_instance(pSampleInstance->PACGame);
    al_destroy_sample_instance(pSampleInstance->PACEXplode);
    al_destroy_sample_instance(pSampleInstance->PACEasterEgg);
    al_destroy_sample_instance(pSampleInstance->PACCredits);

    al_destroy_sample_instance(pSampleInstance->TDLR_Menu);
    al_destroy_sample_instance(pSampleInstance->TDLR_Degats);
    al_destroy_sample_instance(pSampleInstance->TDLR_Fin);

    al_destroy_sample_instance(pSampleInstance->FBMenu);
    al_destroy_sample_instance(pSampleInstance->FBDeath);
    al_destroy_sample_instance(pSampleInstance->FBGame);


    /*al_destroy_sample_instance(pSampleInstance->walk);
    al_destroy_sample_instance(pSampleInstance->click);
    al_destroy_sample_instance(pSampleInstance->shot);
    al_destroy_sample_instance(pSampleInstance->duck);
    al_destroy_sample_instance(pSampleInstance->car);
    al_destroy_sample_instance(pSampleInstance->snake);
    al_destroy_sample_instance(pSampleInstance->balloon);*/

    al_destroy_sample_instance(pSampleInstance->mj);
    free(pSampleInstance);
}

void Allegro_play_Sample (ALLEGRO_SAMPLE_INSTANCE* _pSample){
    al_play_sample_instance(_pSample);
}

void Allegro_Stop_Sample (ALLEGRO_SAMPLE_INSTANCE* _pSample){
    al_stop_sample_instance(_pSample);
}

PALLEGRO_CURSOR InitCursors(){
    PALLEGRO_CURSOR pCursor = malloc(sizeof(ALLEGRO_CURSOR));

    ALLEGRO_BITMAP *Cursor1 = al_load_bitmap("..\\Textures\\Cursors\\cursor--v1.png");
    ALLEGRO_BITMAP *PAC = al_load_bitmap("..\\Textures\\Cursors\\PAC Sight (Personnalisé).png");
    //ALLEGRO_BITMAP *Cursor3 = al_load_bitmap();
    //ALLEGRO_BITMAP *Cursor4 = al_load_bitmap();
    //ALLEGRO_BITMAP *Cursor5 = al_load_bitmap();
    //ALLEGRO_BITMAP *Cursor6 = al_load_bitmap();
    //ALLEGRO_BITMAP *Cursor7 = al_load_bitmap();

    pCursor->PACSight = al_create_mouse_cursor(PAC, 0, 0);

    pCursor->Cursor1 = al_create_mouse_cursor(Cursor1, 0, 0);

    //pCursor->Cursor3 = al_create_mouse_cursor();
    //pCursor->Cursor4 = al_create_mouse_cursor();
    //pCursor->Cursor5 = al_create_mouse_cursor();
    //pCursor->Cursor6 = al_create_mouse_cursor();
    //pCursor->Cursor7 = al_create_mouse_cursor();

    return pCursor;
}

void Destroy_cursors(PALLEGRO_CURSOR pCursor){
    al_destroy_mouse_cursor(pCursor->Cursor1);
    al_destroy_mouse_cursor(pCursor->PACSight);
}

void ChangeCursor (PALLEGRO_MANAGER pAlManager, ALLEGRO_MOUSE_CURSOR *pMouseCursor){
    al_set_mouse_cursor(pAlManager->pDisplay, pMouseCursor);
}

void HideCursor (PALLEGRO_MANAGER pAlManager){
    al_hide_mouse_cursor(pAlManager->pDisplay);
}

void DisplayCursor (PALLEGRO_MANAGER pAlManager){
    al_show_mouse_cursor(pAlManager->pDisplay);
}