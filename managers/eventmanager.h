#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include "manager.h"
#include "keyboardsubsystem.h"
#include "mousesubsystem.h"



CLASS_EXT(EventManager, Manager,
    
    KeyboardSubsystem keyboard_ssys;
    const Uint8       *keyboard;        // Retrieved from keyboard_ssys
    
    MouseSubsystem    mouse_ssys;
    int               *mouse;           // Retrieved from mouse_ssys
)


void EventManager_init(void *_self);
void EventManager_clean(void *_self);
void EventManager_update(void *_self, double sf);
void EventManager_registerApp(void *_self, App *app);

#endif /* __EVENTMANAGER_H__ */

