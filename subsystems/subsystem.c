#include "subsystem.h"
#include "debug.h"



void Subsystem_init(void *_self)
{
    if (!_self)
        return;
    Subsystem *self = _self;
    strcpy(self->subsystem_name, "subsystem");
    self->entity_darray = g_array_new(TRUE, TRUE, sizeof(Component *));
}

void Subsystem_update(void *_self, double sf) // meant to be overridden
{
    if (!_self)
        return;
    Subsystem *self = _self;
    fprintf(stderr, "%s Update function unassigned\n", self->subsystem_name);
}

void Subsystem_clean(void *_self)
{
    
    if (!_self)
        return;
    Subsystem *self = _self;
    g_array_free(self->entity_darray, TRUE);
    INFO("Cleaned up subsystem");
}
