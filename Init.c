#include "Include.h"

void Init_Allegro(){
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());
    assert(al_init_image_addon());
}

void Init_Allegro_Display(ALLEGRO_DISPLAY **pdisplay, int X, int Y, char *pTitle){
    *pdisplay = al_create_display(X, Y);
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_window_title(*pdisplay, pTitle);
}

void Init_Allegro_Event(ALLEGRO_EVENT_QUEUE **pqueue, ALLEGRO_DISPLAY **pdisplay, ALLEGRO_TIMER **ptimer){
    *pqueue = al_create_event_queue();
    al_register_event_source(*pqueue, al_get_keyboard_event_source());
    al_register_event_source(*pqueue, al_get_display_event_source(*pdisplay));
    al_register_event_source(*pqueue, al_get_timer_event_source(*ptimer));
}

