#include "en_entity.h"
#include "debug.h"

#include "ss_event.h"



void     Entity_init(void *_self)
{
    if (!_self)
        return;
    Entity *self = _self;
    INIT_ENT("entity",Entity, self);
    self->component_darray = g_array_sized_new(FALSE, FALSE, sizeof(Component *), 10);
}


void    Entity_update(void *_self, double sf)
{
    if (!_self)
        return;
    //sEntity *self = _self;
}


void    Entity_clean(void *_self)
{
    if (!_self)
        return;
    Entity *self = _self;
    g_array_free(self->component_darray, TRUE);
    _INFO("Free'd Component array for: %s", self->entity_type);
}


void    Entity_notify(void *_self, Event event)
{
    if (!_self)
        return;
    //Entity *self = _self;
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
    
    
	INIT(Transform, self->transform);
    INIT(Physics,   self->physics);
	INIT(Renderer,  self->renderer);
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


void    Door_notify(void *_self, Event event)
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
