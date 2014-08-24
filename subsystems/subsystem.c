#include "subsystem.h"


Subsystem *Subsystem_new()
{
    Subsystem *self = malloc(sizeof(Subsystem));
    self->entity_darray = g_array_new(TRUE, TRUE, sizeof(Component *));
    return self;
}

void Subsystem_update(void *_self, float sf) // meant to be overridden
{
    //Subsystem *self = _self;
    fprintf(stderr, "Update function unassigned\n");
}

void Subsystem_delete(void *_self)
{
    Subsystem *self = _self;
    g_array_free(self->entity_darray, TRUE);
    FREE(self);
}
