#ifndef __CO_PHYSICS_H__
#define __CO_PHYSICS_H__

#include "co_component.h"


// -- PhysicsComponent -- //
CLASS_EXT(PhysicsComponent, Component,
	double vx;      // velocity in x axis
	double vy;      // velocity in y axis
	double ax;      // acceleration in x axis
	double ay;      // acceleration in y axis
	double max_x;   // max velocity in x axis
	double max_y;   // max velocity in y axis
)

void        PhysicsComponent_init(void *_self);
void        PhysicsComponent_update(void *_self);
void        PhysicsComponent_clean(void *_self);


#endif /* __CO_PHYSICS_H__ */
