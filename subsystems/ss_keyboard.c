#include "ss_keyboard.h"
#include "debug.h"

void KeyboardSubsystem_init(void *_self)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    
    INIT(Subsystem, self->parent);  // init superclass
    
    INIT_SUBSYS("keyboardsubsystem", KeyboardSubsystem, self);
}


void KeyboardSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    self->keyboard = SDL_GetKeyboardState(NULL);
}


void KeyboardSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    
    Subsystem_clean(&self->parent);
}


void KeyboardSubsystem_registerEntity(void *_self, Entity *entity)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    
    Subsystem_registerEntity(self, entity);
}
