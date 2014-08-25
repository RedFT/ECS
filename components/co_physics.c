#include "co_physics.h"


void        PhysicsComponent_init(void *_self)
{
    if (!_self)
        return;
    PhysicsComponent *self = _self;
    
    INIT(Component, self->parent);
    
    
	INIT_COMP("physicscomponent", PhysicsComponent, self);
	
	self->vx        = 0;
	self->vy        = 0;
	self->ax        = 0;
	self->ay        = 0;
	self->max_x     = 0;
	self->max_y     = 0;
}

void       PhysicsComponent_update(void *_self)
{
    if (!_self)
        return;
    // PhysicsComponent *self = _self;
}


void       PhysicsComponent_clean(void *_self)
{
    if (!_self)
        return;
    PhysicsComponent *self = _self;
    
    Component_clean(&self->parent);
}
