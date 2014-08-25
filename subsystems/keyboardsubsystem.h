#ifndef __KEYBOARDSUBSYSTEM_H__
#define __KEYBOARDSUBSYSTEM_H__

#include "ooc.h"
#include "subsystem.h"
#include <SDL2/SDL_keyboard.h>

CLASS_EXT(KeyboardSubsystem, Subsystem,
    const Uint8 *keyboard;
    void (*registerKeyboard)(void *_self, const Uint8 *keyboard);
)


void KeyboardSubsystem_init(void *_self);
void KeyboardSubsystem_update(void *_self, double sf);
void KeyboardSubsystem_clean(void *_self);

#endif /* __KEYBOARDSUBSYSTEM_H__ */
