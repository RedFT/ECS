#include "ss_event.h"
#include "debug.h"


void EventSubsystem_init(void *_self)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    INIT(Subsystem, self->parent);  // init superclass
    
    INIT_SUBSYS("eventsubsystem", EventSubsystem, self);
    
}


void EventSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    //EventSubsystem *self = _self;
}


void EventSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    Subsystem_clean(&self->parent);
}


void EventSubsystem_registerEntity(void *_self, Entity *entity)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    Subsystem_registerEntity(self, entity);
}





void EventSubsystem_notify(void *_self, Event event)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    Entity *ent = NULL;
    for (int i = 0; i < self->entity_darray->len; i++)
    {
        ent = &g_array_index(self->entity_darray, Entity, i);
        ent->notify(ent, event);
    }
}
