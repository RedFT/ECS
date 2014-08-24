#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "ooc.h"

/* ------- Component -------*/
// COMPONENT_TYPE enum -- used to ID components
enum
{
	TRANSFORM = 0,
	RENDERER,
	PHYSICS,
	COMPONENT_TYPE_N
} COMPONENT_TYPE;

CLASS(Component,
	// Object *object // Reference to the owning object
	unsigned int component_type;   // for ID'ing components
)

Component *Component_new();     // probably wont be used
void Component_delete(); 		// probably wont be used


#endif /* __COMPONENT_H__ */

