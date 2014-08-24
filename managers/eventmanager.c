#include "eventmanager.h"


void EventManager_init(void *_self)
{
    if (!_self)
        return;
    EventManager *self = _self;
    
    INIT(Manager, self->parent); // init superclass
    
    INIT_MAN(EventManager, self); // assign function pointers
}


void EventManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    //EventManager *self = _self;
}


void EventManager_clean(void *_self)
{
    if (!_self)
        return;
    EventManager *self = _self;
    Manager_clean(&self->parent);
    /*
    CLEAN(self->keyboard_ssys;
    CLEAN(self->mouse_ssys;
     */
}


void EventManager_registerApp(void *_self, App *app)
{
    if (!_self)
        return;
    EventManager *self = _self;
    self->app = app;
}
