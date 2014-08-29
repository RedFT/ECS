#ifndef __SS_MOUSE_H__
#define __SS_MOUSE_H__

#include <SDL2/SDL_mouse.h>


#include "ooc.h"
#include "ss_subsystem.h"


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
)

void MouseSubsystem_init(void *_self);
void MouseSubsystem_update(void *_self, double sf);
void MouseSubsystem_clean(void *_self);

#endif /* __SS_MOUSE_H__ */

