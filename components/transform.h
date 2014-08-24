#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "component.h"


// -- Transform -- //
CLASS_EXT(Transform, Component,
	int x, y;
	float rot;
	float size;
)

Transform *Transform_new();
void       Transform_delete(Transform *self);

#endif /* __TRANSFORM_H__ */

