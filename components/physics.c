#include "physics.h"


void        Physics_init(void *_self)
{
    if (!_self)
        return;
    Physics *self = _self;
    
    INIT(Component, self->parent);
    
	INIT_COMP(PHYSICS, Physics, self);
	
	self->vx        = 0;
	self->vy        = 0;
	self->ax        = 0;
	self->ay        = 0;
	self->max_x     = 0;
	self->max_y     = 0;
}

void       Physics_update(void *_self)
{
    if (!_self)
        return;
    // Physics *self = _self;
}


void       Physics_clean(void *_self)
{
    if (!_self)
        return;
    Physics *self = _self;
    CLEAN(self->parent);
    
}
