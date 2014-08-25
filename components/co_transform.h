#ifndef __CO_TRANSFORM_H__
#define __CO_TRANSFORM_H__

#include "co_component.h"


// -- Transform -- //
CLASS_EXT(Transform, Component,
	double x, y;
	double rot, size;
)

void       Transform_init(void *_self);
void       Transform_update(void *_self);
void       Transform_clean(void *_self);

#endif /* __CO_TRANSFORM_H__ */

