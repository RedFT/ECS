#include "app.h"
#include "debug.h"
#include <stdlib.h>

#include "entities/entity.h"


int   App_init(App *self)
{
    if (!self)
        return 1;
    
    int ret = SDL_Init(SDL_INIT_EVERYTHING);
    ERR(!ret, "%s", SDL_GetError());
    
    
    self->win = SDL_CreateWindow("Example",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            SDL_WINDOW_SHOWN); // | SDL_WINDOW_OPENGL);
    ERR(self->win, "%s", SDL_GetError());
    
    self->ren = SDL_CreateRenderer(self->win,
            -1, 0);
    ERR(self->ren, "%s", SDL_GetError());
    
    SDL_SetRenderDrawColor(self->ren, 0, 0, 0, 255);
    
    self->app_running = 1;
    self->clean = App_clean;
    INIT(EventManager, self->event_manager);
    //INIT(SceneManager, self->scene_manager);
    INIT(RenderManager, self->render_manager);
    
    REGISTER(self->event_manager, App, self);
    //REGISTER(self->scene_manager, App, self);
    REGISTER(self->render_manager, App, self);
    
    
    return 0;
error:
    return 1;
}



int   App_run(App *self)
{
    Door d;
    INIT(Door, d);
    while (self->app_running)
    {
        UPDATE(self->event_manager, 0);
        //UPDATE(self->scene_manager, 0);
        UPDATE(self->render_manager, 0);
    }
    CLEAN(d);
    
    return 0;
}


void  App_clean(App *self)
{
    CLEAN(self->event_manager);
    //CLEAN(self->scene_manager);
    CLEAN(self->render_manager);
    
    if (self->ren)
        SDL_DestroyRenderer(self->ren);
    if (self->win)
        SDL_DestroyWindow(self->win);
    
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    SDL_Quit();
}

