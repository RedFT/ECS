#include "mousesubsystem.h"
#include "debug.h"


void MouseSubsystem_init(void *_self)
{
    if (!_self)
        return;
    MouseSubsystem *self = _self;
    
    INIT(Subsystem, self->parent);  // init superclass
    
    INIT_SUBSYS("mousesubsystem", MouseSubsystem, self);
}


void MouseSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    MouseSubsystem *self = _self;
    
    int mouse_state = SDL_GetMouseState(&self->mouse[MOUSE_X_POS], &self->mouse[MOUSE_Y_POS]);
    if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT))
        self->mouse[MOUSE_LEFT] = 1;
    else
        self->mouse[MOUSE_LEFT] = 0;
        
    if (mouse_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))
        self->mouse[MOUSE_MIDDLE] = 1;
    else
        self->mouse[MOUSE_MIDDLE] = 0;
        
    if (mouse_state & SDL_BUTTON(SDL_BUTTON_RIGHT))
        self->mouse[MOUSE_RIGHT] = 1;
    else
        self->mouse[MOUSE_RIGHT] = 0;
}


void MouseSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    MouseSubsystem *self = _self;
    Subsystem_clean(&self->parent);
}


