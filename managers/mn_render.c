#include "mn_render.h"
#include "app.h"
#include "debug.h"


void RenderManager_init(void *_self)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    
    INIT(Manager, self->parent); // init superclass
    
    INIT_MAN("rendermanager", RenderManager, self); // assign function pointers
    self->registerApp = RenderManager_registerApp;
}


void RenderManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    
    
    RenderManager_renderScreen(self);
}


void RenderManager_clean(void *_self)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    
    Manager_clean(&self->parent);
}


void RenderManager_registerApp(void *_self, App *app)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    self->app = app;
    self->sdl_ren = self->app->ren;
    _INFO("Registered app to %s", self->manager_type);
}



void RenderManager_renderScreen(RenderManager *self)
{
    SDL_RenderPresent(self->sdl_ren);
    SDL_RenderClear(self->sdl_ren);
}
