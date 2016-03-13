#include "co_transform.h"
#include "debug.h"

void        TransformComponent_init(void *_self)
{
    if (!_self)
        return;
    TransformComponent *self = _self;
	
	INIT(Component, self->parent);
	
	
    INIT_COMP("transformcomponent", TransformComponent, self);
	INFO("INITIALIZED TRANSFORM_COMPONENT");
	self->x = 0;
	self->y = 0;
	self->rot = 0;
	self->size = 0;
}


void       TransformComponent_update(void *_self)
{
    if (!_self)
        return;
    //TransformComponent *self = _self;
    
}


void       TransformComponent_clean(void *_self)
{
    if (!_self)
        return;
    TransformComponent *self = _self;
    
    Component_clean(&self->parent);
}
