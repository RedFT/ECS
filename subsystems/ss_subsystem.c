#include "ss_subsystem.h"
#include "debug.h"


void Subsystem_init(void *_self)
{
    if (!_self)
        return;
    Subsystem *self = _self;
    INIT_SUBSYS("subsystem", Subsystem, self);
    self->entity_darray    = g_array_new(TRUE, TRUE, sizeof(Entity *));
}

void Subsystem_update(void *_self, double sf) // meant to be overridden
{
    if (!_self)
        return;
    Subsystem *self = _self;
    fprintf(stderr, "%s Update function unassigned\n", self->subsystem_type);
}

void Subsystem_clean(void *_self)
{
    
    if (!_self)
        return;
    Subsystem *self = _self;
    g_array_free(self->entity_darray, TRUE);
    _INFO("Free'd Entity array for: %s", self->subsystem_type);
}

void Subsystem_registerEntity(void *_self, Entity *entity)
{
    if (!_self)
        return;
    Subsystem *self = _self;
    g_array_append_val(self->entity_darray, entity);
}
