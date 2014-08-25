#include "keyboardsubsystem.h"
#include "debug.h"

void KeyboardSubsystem_init(void *_self)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    
    strcpy(self->subsystem_name, "keyboardsubsystem");
    self->keyboard = NULL;
    self->update = KeyboardSubsystem_update;
    self->clean = KeyboardSubsystem_clean;
    self->registerKeyboard = KeyboardSubsystem_registerKeyboard;
}


void KeyboardSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    if (self->keyboard)
        self->keyboard = SDL_GetKeyboardState(NULL);
}


void KeyboardSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    //KeyboardSubsystem *self = _self;
}


void KeyboardSubsystem_registerKeyboard(void *_self, const Uint8 *keyboard)
{
    if (!_self)
        return;
    KeyboardSubsystem *self = _self;
    self->keyboard = keyboard;
}
