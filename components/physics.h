#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include "component.h"


// -- Physics -- //
CLASS_EXT(Physics, Component,
	int vx;  // velocity in x plane
	int vy;  // velocity in y plane
)

Physics *Physics_new();
void  Physics_delete(Physics *self);

#endif /* __PHYSICS_H__ */

