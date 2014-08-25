#ifndef __MN_EVENT_H__
#define __MN_EVENT_H__

#include "mn_manager.h"
#include "ss_keyboard.h"
#include "ss_mouse.h"



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

#endif /* __MN_EVENT_H__ */

