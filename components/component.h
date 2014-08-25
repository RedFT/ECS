#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "ooc.h"
#include <string.h>

#define INIT_COMP(type,class,object)   \
    strcpy(self->component_type, type);           \
    object->update = class##_update;         \
    object->clean  = class##_clean;
    

/* ------- Component -------*/
// COMPONENT_TYPE enum -- used to ID components // unused. Using strings to ID
/*
typedef enum
{
    COMPONENT = 0,
	TRANSFORM,
	RENDERER,
	PHYSICS,
	COMPONENT_TYPE_N
} ComponentType;
*/

CLASS(Component,
	// Object *object // Reference to the owning object
	char component_type[100];   // for ID'ing components
	void (*update)(void *_self);
	void (*clean)(void *_self);
)

void        Component_init(void *_self);        // probably wont be used
void        Component_update(void *_self); 		// probably wont be used
void        Component_clean(void *_self); 		// probably wont be used


#endif /* __COMPONENT_H__ */

