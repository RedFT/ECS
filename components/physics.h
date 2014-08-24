#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include "component.h"


// -- Physics -- //
CLASS_EXT(Physics, Component,
	double vx;  // velocity in x plane
	double vy;  // velocity in y plane
	double ax;  // acceleration in x plane
	double ay;  // acceleration in y plane
	double max_x; // max velocity in x plane
	double max_y; // max velocity in y plane
)

void        Physics_init(void *_self);
void        Physics_update(void *_self);
void        Physics_clean(void *_self);


#endif /* __PHYSICS_H__ */

