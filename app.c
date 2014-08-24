#include "app.h"
#include "debug.h"
#include <stdlib.h>

#include "entities/entity.h"


App *App_new()
{
    App *app = malloc(sizeof(App));
    App_init(app);
    return app;
}


void  App_delete(App *self)
{
    if (!self) 
        return;
    if (self->manager) DELETE(self->manager);
    //if (self->ren) SDL_DestroyRenderer(self->ren);
    //if (self->win) SDL_DestroyWindow(self->win);
    FREE(self);
}


int   App_init(App *self)
{
    if (!self)
        return 1;
    self->app_running = 1;
    self->manager = NEW(Manager);
    INIT(Manager, self->manager);
    self->manager->app = self;
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
    while (self->app_running)
    {
        UPDATE(self->manager, 0);
        Door *d = NEW(Door);
        DELETE(d);
    }
    
    return 0;
}



