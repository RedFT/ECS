#include "app.h"
#include "debug.h"
#include <stdlib.h>

#include "entities/entity.h"


int   App_init(App *self)
{
    if (!self)
        return 1;
    self->app_running = 1;
    self->clean = App_clean;
    INIT(EventManager, self->event_manager);
    REGISTER(self->event_manager, App, self);
    
    
    /*
    self->win = SDL_CreateWindow("Example",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            SDL_WINDOW_SHOWN); // | SDL_WINDOW_OPENGL);
    ERR(self->win, "%s", SDL_GetError());
    
    self->ren = SDL_CreateRenderer(self->win,
            -1, 0);
    ERR(self->ren, "%s", SDL_GetError());
    return 0;
error:
    */
    return 0;
}



int   App_run(App *self)
{
    Door d;
    INIT(Door, d);
    while (self->app_running)
    {
        UPDATE(self->event_manager, 0);
    }
    CLEAN(d);
    
    return 0;
}


void  App_clean(App *self)
{
    CLEAN(self->event_manager);
    SDL_Quit();
}

