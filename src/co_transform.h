#ifndef __CO_TRANSFORM_H__
#define __CO_TRANSFORM_H__

#include "co_component.h"


// -- TransformComponent -- //
CLASS_EXT(TransformComponent, Component,
	double x, y;
	double rot, size;
)

void       TransformComponent_init(void *_self);
void       TransformComponent_update(void *_self);
void       TransformComponent_clean(void *_self);

#endif /* __CO_TRANSFORM_H__ */

