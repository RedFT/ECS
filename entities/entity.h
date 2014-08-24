#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <glib.h>

#include "components/transform.h"
#include "components/physics.h"
#include "components/renderer.h"


/* -------- Entity -------- */
CLASS(Entity,
	/* Future Implementation */
	void (*delete)(void *self);
	GArray *component_darray;
	// SceneRenderer scene_renderer
) 


Entity *Entity_new();
int     Entity_init(void *self);
void    Entity_delete(void *self);


/* TEST ENTITY */
CLASS_EXT(Door, Entity,
	void (*open)();
	void (*close)();
	
	Transform *transform;
	Physics   *physics;
	Renderer  *renderer;
)

void o();
void c();

Door *Door_new();
void  Door_delete(void *self);



#endif /* __ENTITY_H__ */

