#ifndef __MOUSESUBSYSTEM_H__
#define __MOUSESUBSYSTEM_H__

#include <SDL2/SDL_mouse.h>


#include "ooc.h"
#include "subsystem.h"


enum
{
    MOUSE_UNUSED = 0,
    MOUSE_LEFT,
    MOUSE_MIDDLE,
    MOUSE_RIGHT,
    MOUSE_X_POS,
    MOUSE_Y_POS
};


CLASS_EXT(MouseSubsystem, Subsystem,
    int mouse[6];
    void (*registerMouse)(void *_self, int *mouse);
)

void MouseSubsystem_init(void *_self);
void MouseSubsystem_update(void *_self, double sf);
void MouseSubsystem_clean(void *_self);

#endif /* __MOUSESUBSYSTEM_H__ */

