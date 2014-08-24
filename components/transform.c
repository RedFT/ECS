#include "transform.h"


Transform *Transform_new()
{
	Transform *self = malloc(sizeof(Transform));
	self->component_type = TRANSFORM;
	self->x = 0;
	self->y = 0;
	self->rot = 0;
	self->size = 0;
	return self;
}

void       Transform_delete(Transform *self)
{
	FREE(self);
}
