#include "ss_event.h"
#include "debug.h"


void EventSubsystem_init(void *_self)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    INIT(Subsystem, self->parent);  // init superclass
    
    INIT_SUBSYS("eventsubsystem", EventSubsystem, self);
    self->notify = EventSubsystem_notify;
    
    _INFO("Initialized %s", self->subsystem_type);
}


void EventSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    _INFO("%s has %d entities", self->subsystem_type, self->entity_darray->len);
}


void EventSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    Subsystem_clean(&self->parent);
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
        _INFO("Notifying %s of event", ent->entity_type);
        ent->notify((*ent), event);
    }
}
