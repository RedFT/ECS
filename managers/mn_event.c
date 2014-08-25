#include "mn_event.h"
#include "app.h"
#include "debug.h"


void EventManager_init(void *_self)
{
    if (!_self)
        return;
    EventManager *self = _self;
    
    INIT(Manager, self->parent); // init superclass
    
    INIT_MAN("eventmanager", EventManager, self); // assign function pointers
    
    INIT(KeyboardSubsystem, self->keyboard_ssys);
    INIT(MouseSubsystem, self->mouse_ssys);
    
    g_array_append_val(self->subsystem_darray, self->keyboard_ssys);
    g_array_append_val(self->subsystem_darray, self->mouse_ssys);
}


void EventManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    EventManager *self = _self;
    SDL_PumpEvents();
    
    
    Subsystem *tmp = NULL;
    for (int i = 0; i < self->subsystem_darray->len; i++)
    {
        INFO("HERE");
        tmp = &g_array_index(self->subsystem_darray, Subsystem, i);
        _INFO("NAME: %s", tmp->subsystem_type);
        UPDATE(*tmp, 0);
        INFO("HEERE");
    }
    
    self->keyboard = self->keyboard_ssys.keyboard;
    self->mouse    = self->mouse_ssys.mouse;
    
    if (SDL_HasEvent(SDL_QUIT))
    {
        if (self->app)
            self->app->app_running = 0;
    }
    
    if (self->keyboard[SDL_SCANCODE_ESCAPE])
    {
        if (self->app)
            self->app->app_running = 0;
    }
}


void EventManager_clean(void *_self)
{
    if (!_self)
        return;
    EventManager *self = _self;
    
    CLEAN(self->keyboard_ssys);
    CLEAN(self->mouse_ssys);
    
    Manager_clean(&self->parent);
}
