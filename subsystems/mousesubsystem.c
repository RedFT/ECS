#include "mousesubsystem.h"
#include "debug.h"


void MouseSubsystem_init(void *_self)
{
    if (!_self)
        return;
    MouseSubsystem *self = _self;
    
    strcpy(self->subsystem_name, "mousesubsystem");
    
    self->update = MouseSubsystem_update;
    self->clean = MouseSubsystem_clean;
    self->registerMouse = MouseSubsystem_registerMouse;
}


void MouseSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    MouseSubsystem *self = _self;
    
    if (self->mouse)
    {
        int mouse_state = SDL_GetMouseState(&self->mouse[4], &self->mouse[5]);
        if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT))
            self->mouse[1] = 1;
        else
            self->mouse[1] = 0;
            
        if (mouse_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))
            self->mouse[2] = 1;
        else
            self->mouse[2] = 0;
            
        if (mouse_state & SDL_BUTTON(SDL_BUTTON_RIGHT))
            self->mouse[3] = 1;
        else
            self->mouse[3] = 0;
    }
}


void MouseSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    //MouseSubsystem *self = _self;
}


void MouseSubsystem_registerMouse(void *_self, int *mouse)
{
    if (!_self)
        return;
    MouseSubsystem *self = _self; 
    self->mouse = mouse;
}


