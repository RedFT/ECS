#include "ss_subsystem.h"
#include "debug.h"


void Subsystem_init(void *_self)
{
    if (!_self)
        return;
    Subsystem *self = _self;
    INIT_SUBSYS("subsystem", Subsystem, self);
    self->entity_list    = NULL;
}

void Subsystem_update(void *_self, double sf) // meant to be overridden
{
    if (!_self)
        return;
    Subsystem *self = _self; 
    
    /* This function should not be called */
    
    _INFO("%s Update function unassigned\n", self->subsystem_type);
}

void Subsystem_clean(void *_self)
{
    
    if (!_self)
        return;
    Subsystem *self = _self;
    g_slist_free(self->entity_list);
    _INFO("Free'd Entity list for: %s", self->subsystem_type);
}

void Subsystem_registerEntity(void *_self, Entity *entity)
{
    if (!_self)
        return;
    Subsystem *self = _self;
    
    self->entity_list = g_slist_append(self->entity_list, entity);
    _INFO("Added %s to %s's Entity list", entity->entity_type, self->subsystem_type);
}
