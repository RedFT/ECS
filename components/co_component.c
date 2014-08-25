#include "co_component.h"
#include "en_entity.h"



void        Component_init(void *_self)
{
    if (!_self)
        return;
    Component *self = _self;
    INIT_COMP("component", Component, self);
}

      
void        Component_update(void *_self)
{
}

 	
void        Component_clean(void *_self)
{
}

 
