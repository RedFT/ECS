#include "app.h"
#include "debug.h"
#include <stdlib.h>

#include "en_entity.h"


int   App_init(App *self)
{
    ERR(self, "%s", "App is NULL");
    
    int ret = SDL_Init(SDL_INIT_EVERYTHING);
    ERR(!ret, "%s", SDL_GetError());
    
    /* WINDOW */
    self->win = SDL_CreateWindow("Example",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            SDL_WINDOW_SHOWN); // | SDL_WINDOW_OPENGL);
    ERR(self->win, "%s", SDL_GetError());
    
    
    /* RENDERER */
    self->ren = SDL_CreateRenderer(self->win,
            -1, 0);
    ERR(self->ren, "%s", SDL_GetError());
    SDL_SetRenderDrawColor(self->ren, 0, 0, 0, 255);
    
    
    /* MANAGERS */
    INIT(EventManager, self->event_manager);
    INIT(SceneManager, self->scene_manager);
    INIT(RenderManager, self->render_manager);
    
    REGISTER(self->event_manager, App, *self);
    REGISTER(self->scene_manager, App, *self);
    REGISTER(self->render_manager, App, *self);
    
    self->clean = App_clean;
    self->app_running = 1;
    
    return 0;
error:
    return 1;
}



int   App_run(App *self)
{
    Pigeon p;
    INIT(Pigeon, p);
    REGISTER(self->scene_manager,  Entity, p);
    REGISTER(self->render_manager, Entity, p);
    
    
    while (self->app_running)
    {
        UPDATE(self->event_manager, 0);
        UPDATE(self->scene_manager, 0);
        UPDATE(self->render_manager, 0);
    }
    
    CLEAN(p);
    
    return 0;
}


void  App_clean(App *self)
{
    CLEAN(self->event_manager);
    CLEAN(self->scene_manager);
    CLEAN(self->render_manager);
    
    if (self->ren)
        SDL_DestroyRenderer(self->ren);
    if (self->win)
        SDL_DestroyWindow(self->win);
    
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    SDL_Quit();
}

