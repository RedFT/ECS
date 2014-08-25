#ifndef __SS_KEYBOARD_H__
#define __SS_KEYBOARD_H__

#include "ooc.h"
#include "ss_subsystem.h"
#include <SDL2/SDL_keyboard.h>

CLASS_EXT(KeyboardSubsystem, Subsystem,
    const Uint8 *keyboard;
)


void KeyboardSubsystem_init(void *_self);
void KeyboardSubsystem_update(void *_self, double sf);
void KeyboardSubsystem_clean(void *_self);
void KeyboardSubsystem_registerEntity(void *_self, Entity *entity);

#endif /* __SS_KEYBOARD_H__ */
