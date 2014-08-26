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
    
    self->registerApp       = RenderManager_registerApp;
    self->registerSubsystem = RenderManager_registerSubsystem;
    //self->registerEntity    = RenderManager_registerEntity;
    
    INIT(RenderSubsystem, self->render_ssys);
    
    REGISTER(self->parent, Subsystem, self->render_ssys);
}


void RenderManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    
    Manager_update(self, 0);
    
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
    
    Subsystem *ssys = NULL;
    GSList *iterator = NULL;
    /* FIND AND ASSIGN AN SDL_Renderer TO THE RENDERING SUBSYSTEM */
    for (iterator = self->subsystem_list; iterator; iterator = iterator->next)
    {
        ssys = iterator->data;
        if (!strcmp(ssys->subsystem_type, "rendersubsystem"))
        {
            ((RenderSubsystem *) ssys)->sdl_ren = self->sdl_ren;
        }
    }
    _INFO("Registered app to %s", self->manager_type);
}


void     RenderManager_registerSubsystem(void *_self, Subsystem *ssys)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    Manager_registerSubsystem(self, ssys);
}


void     RenderManager_registerEntity(void *_self, Entity *ent)
{
    if (!_self)
        return;
    RenderManager *self = _self;
    
    //Manager_registerEntity(self, ent);
    self->entity_list = g_slist_append(self->entity_list, ent);
    _INFO("Added %s to %s's Entity list", ent->entity_type, self->manager_type);
    
    
    REGISTER(self->render_ssys, Entity, ent);
}



void RenderManager_renderScreen(RenderManager *self)
{
    SDL_RenderPresent(self->sdl_ren);
    SDL_RenderClear(self->sdl_ren);
}
