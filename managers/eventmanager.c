#include "eventmanager.h"
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
}


void EventManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    EventManager *self = _self;
    SDL_PumpEvents();
    
    UPDATE(self->keyboard_ssys, 0);
    UPDATE(self->mouse_ssys, 0);
    
    self->keyboard = self->keyboard_ssys.keyboard;
    self->mouse    = self->mouse_ssys.mouse;
    
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


void EventManager_registerApp(void *_self, App *app)
{
    if (!_self)
        return;
    EventManager *self = _self;
    self->app = app;
}
