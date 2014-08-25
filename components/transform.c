#include "transform.h"


void        Transform_init(void *_self)
{
    if (!_self)
        return;
    Transform *self = _self;
	
	INIT(Component, self->parent);
    INIT_COMP("transform", Transform, self);
	
	self->x = 0;
	self->y = 0;
	self->rot = 0;
	self->size = 0;
}


void       Transform_update(void *_self)
{
    if (!_self)
        return;
    //Transform *self = _self;
    
}


void       Transform_clean(void *_self)
{
    if (!_self)
        return;
    Transform *self = _self;
    CLEAN(self->parent);
    
}
