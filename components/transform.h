#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "component.h"


// -- Transform -- //
CLASS_EXT(Transform, Component,
	double x, y;
	double rot, size;
)

void       Transform_init(void *_self);
void       Transform_update(void *_self);
void       Transform_clean(void *_self);

#endif /* __TRANSFORM_H__ */

