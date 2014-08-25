#ifndef __CO_PHYSICS_H__
#define __CO_PHYSICS_H__

#include "co_component.h"


// -- PhysicsComponent -- //
CLASS_EXT(PhysicsComponent, Component,
	double vx;  // velocity in x plane
	double vy;  // velocity in y plane
	double ax;  // acceleration in x plane
	double ay;  // acceleration in y plane
	double max_x; // max velocity in x plane
	double max_y; // max velocity in y plane
)

void        PhysicsComponent_init(void *_self);
void        PhysicsComponent_update(void *_self);
void        PhysicsComponent_clean(void *_self);


#endif /* __CO_PHYSICS_H__ */

