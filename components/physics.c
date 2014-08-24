#include "physics.h"


Physics *Physics_new()
{
	Physics *self = malloc(sizeof(Physics));
	self->component_type = PHYSICS;
	self->vx = 0;
	self->vy = 0;
	return self;
}

void       Physics_delete(Physics *self)
{
	FREE(self);
}
