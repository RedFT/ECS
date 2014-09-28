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
    object->load   = class##_load;      \
    object->getComponent = Entity_getComponent;\
    object->registerComponent = Entity_registerComponent;


/* -------- Entity -------- */
CLASS(Entity,
    char entity_type[100];
	GSList *component_list;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
	void (*load)(void *_self);
	void (*notify)(void *_self, struct Entity *entity, char *event);
	void *(*getComponent)(void *_self, char *component_type);
	void (*registerComponent)(void *_self, Component *component);
) 


void    Entity_init(void *_self);
void    Entity_update(void *_self, double sf);
void    Entity_clean(void *_self);
void    Entity_load(void *_self);
void    Entity_notify(void *_self, Entity *entity, char *event);    // Notification from 
                                                                    // EventSubsystem
void    Entity_registerComponent(void *_self, Component *component);
                                                                    
void    *Entity_getComponent(void *_self, char *component_type);                                                                



/* ---- TEST ENTITY -----*/
CLASS_EXT(Pigeon, Entity,
	TransformComponent transform_cmp;
	PhysicsComponent   physics_cmp;
	RenderComponent    render_cmp;
)


void    Pigeon_init(void *_self);
void    Pigeon_update(void *_self, double sf);
void    Pigeon_clean(void *_self);
void    Pigeon_notify(void *_self, Entity *entity, char *event);
void    Pigeon_load(void *_self);


#endif /* __ENTITY_H__ */

