#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <glib.h>

#include "co_transform.h"
#include "co_physics.h"
#include "co_renderer.h"
#include "e_events.h"


#define INIT_ENT(type,class,object)     \
    strcpy(object->entity_type, type);  \
    object->update = class##_update;    \
    object->clean  = class##_clean;     \
    object->notify = class##_notify;


/* -------- Entity -------- */
CLASS(Entity,
    char entity_type[100];
	GArray *component_darray;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
	void (*notify)(void *_self, Event event);
) 


void    Entity_init(void *_self);
void    Entity_update(void *_self, double sf);
void    Entity_clean(void *_self);
void    Entity_notify(void *_self, Event event);    // Notification from 
                                                    // EventSubsystem



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
void    Door_notify(void *_self, Event event);


#endif /* __ENTITY_H__ */

