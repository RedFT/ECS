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
    
    REGISTER(self->parent, Subsystem, self->keyboard_ssys);
    REGISTER(self->parent, Subsystem, self->mouse_ssys);
}


void EventManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    EventManager *self = _self;
    SDL_PumpEvents();
    
    
    Manager_update(self, 0);
    
    self->keyboard = self->keyboard_ssys.keyboard;
    self->mouse    = self->mouse_ssys.mouse;
    
    if (SDL_HasEvent(SDL_QUIT))
    {
        if (self->app)
            self->app->app_running = 0;
        INFO("QUITTING SDL_QUIT");
    }
    
    if (self->keyboard[SDL_SCANCODE_ESCAPE])
    {
        if (self->app)
            self->app->app_running = 0;
        INFO("QUITTING ESCAPE PRESSED");
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
