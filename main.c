#include "Init.c"

//Release of 06.04.2023


int main(void) {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event;

    Init_Allegro();

    Init_Allegro_Display(&display, 500, 500, "ECE World");

    Init_Allegro_Event(&queue,&display,&timer);


}
