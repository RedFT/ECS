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
    object->notify = class##_notify;    \
    object->getComponent = Entity_getComponent;


/* -------- Entity -------- */
CLASS(Entity,
    char entity_type[100];
	GSList *component_list;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
	void (*notify)(void *_self, struct Entity *entity, Event event);
	void *(*getComponent)(void *_self, char *component_type);
) 


void    Entity_init(void *_self);
void    Entity_update(void *_self, double sf);
void    Entity_clean(void *_self);
void    Entity_notify(void *_self, Entity *entity, Event event);    // Notification from 
                                                                    // EventSubsystem
                                                                    
void    *Entity_getComponent(void *_self, char *component_type);                                                                



/* ---- TEST ENTITY -----*/
CLASS_EXT(Door, Entity,
	void (*open)();
	void (*close)();
	
	TransformComponent transform_cmp;
	PhysicsComponent   physics_cmp;
	RenderComponent    render_cmp;
)


void o();
void c();

void    Door_init(void *_self);
void    Door_update(void *_self, double sf);
void    Door_clean(void *_self);
void    Door_notify(void *_self, Entity *entity, Event event);


#endif /* __ENTITY_H__ */

