#include "en_entity.h"
#include "debug.h"

#include "ss_event.h"



void     Entity_init(void *_self)
{
    if (!_self)
        return;
    Entity *self = _self;
    INIT_ENT("entity",Entity, self);
    self->component_list = NULL;
}


void    Entity_update(void *_self, double sf)
{
    if (!_self)
        return;
    //Entity *self = _self;
}


void    Entity_clean(void *_self)
{
    if (!_self)
        return;
    Entity *self = _self;
    g_slist_free(self->component_list);
    _INFO("Free'd Component list for: %s", self->entity_type);
}


void    Entity_notify(void *_self, Entity *entity, Event event)
{
    if (!_self)
        return;
    //Entity *self = _self;
}


void    *Entity_getComponent(void *_self, char *component_type)
{
    if (!_self)
        return NULL;
    Entity *self = _self;
    
    Component *cmp = NULL;
    GSList *iterator = NULL;
    
    for (iterator = self->component_list; iterator; iterator = iterator->next)
    {
        cmp = iterator->data;
        if (!strcmp(cmp->component_type, component_type))
        {
            return cmp;
        }
    }
    return NULL;
}


void    Entity_registerComponent(void *_self, Component *component)
{
    if (!_self)
        return;
    Entity *self = _self;
    
    self->component_list = g_slist_append(self->component_list, component);
    REGISTER(*component, Entity, *self)
    _INFO("Added %s to %s's Component list", component->component_type, self->entity_type);
}


void o() 
{
    printf("Open\n");
}

void c() 
{
    printf("Close\n");
}


void     Door_init(void *_self)
{
    if (!_self)
        return;
    Door *self = _self;
    
    INIT(Entity, self->parent); // init super class
    
    INIT_ENT("door", Door, self);
    
    
	INIT(TransformComponent, self->transform_cmp);
    INIT(PhysicsComponent,   self->physics_cmp);
	INIT(RenderComponent,    self->render_cmp);
	
	REGISTER(self->parent, Component, self->transform_cmp);
	REGISTER(self->parent, Component, self->physics_cmp);
	REGISTER(self->parent, Component, self->render_cmp);
}


void    Door_update(void *_self, double sf)
{
    if (!_self)
        return;
    //Door *self = _self;
}


void  Door_clean(void *_self)
{
    if (!_self)
        return;
    Door *self = _self;
    Entity_clean(&self->parent);
}


void    Door_notify(void *_self, Entity *entity, Event event)
{
    if (!_self)
        return;
    //Door *self = _self;
    switch (event)
    {
        case OPEN_EVENT:
            o();
            break;
        
        case CLOSE_EVENT:
            c();
            break;
        
        default:
            break;
    }
    
}
