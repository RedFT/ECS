#include "component.h"



void        Component_init(void *_self)
{
    if (!_self)
        return;
    Component *self = _self;
    INIT_COMP(COMPONENT, Component, self);
}

      
void        Component_update(void *_self)
{
}

 	
void        Component_clean(void *_self)
{
}

 
