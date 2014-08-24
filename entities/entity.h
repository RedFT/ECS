#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <glib.h>

#include "components/transform.h"
#include "components/physics.h"
#include "components/renderer.h"


#define INIT_ENT(class,object)   \
    object->update = class##_update;         \
    object->clean  = class##_clean;


/* -------- Entity -------- */
CLASS(Entity,
	GArray *component_darray;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
) 


void    Entity_init(void *_self);
void    Entity_update(void *_self, double sf);
void    Entity_clean(void *_self);


/* ---- TEST ENTITY -----*/
CLASS_EXT(Door, Entity,
	void (*open)();
	void (*close)();
	
	Transform transform;
	Physics   physics;
	Renderer  renderer;
)

void o();
void c();

void    Door_init(void *_self);
void    Door_update(void *_self, double sf);
void    Door_clean(void *_self);


#endif /* __ENTITY_H__ */

