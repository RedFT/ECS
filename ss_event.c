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
    //EventSubsystem *self = _self;
}


void EventSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    Subsystem_clean(&self->parent);
}





void EventSubsystem_notify(void *_self, Entity *src_ent, char *event)
{
    if (!_self)
        return;
    EventSubsystem *self = _self;
    
    //_INFO("%s's Entity list has %d entities", self->subsystem_type, g_slist_length(self->entity_list));
    Entity *dst_ent = NULL;
    GSList *iterator;
    for (iterator = self->entity_list; iterator; iterator = iterator->next)
    {
        
        dst_ent = iterator->data;
        NOTIFY(*dst_ent, src_ent, event);
    }
}
