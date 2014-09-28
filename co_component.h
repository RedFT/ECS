/* NOTES --
    Should probably remove the update
    functions and function pointers
 */

#ifndef __CO_COMPONENT_H__
#define __CO_COMPONENT_H__

#include "ooc.h"
#include <string.h>

#define INIT_COMP(type,class,object)   \
    strcpy(self->component_type, type);           \
    object->update = class##_update;         \
    object->clean  = class##_clean;         \
    object->registerEntity = Component_registerEntity;
    

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


typedef struct Entity Entity;


CLASS(Component,
	Entity *owner;             // reference to owner
	char component_type[100];   // for ID'ing component's type
	void (*update)(void *_self);
	void (*clean)(void *_self);
	void (*registerEntity)(void *_self, Entity *ent);
)

void        Component_init(void *_self);        // probably wont be used
void        Component_update(void *_self); 		// probably wont be used
void        Component_clean(void *_self); 		// probably wont be used
void        Component_registerEntity(void *_self, Entity *ent);

#endif /* __CO_COMPONENT_H__ */

