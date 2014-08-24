#include "manager.h"
#include "subsystem.h"
#include "entity.h"
#include "app.h"


Manager *Manager_new()
{
    Manager *self = malloc(sizeof(Manager));
    Manager_init(self);
    return self;
}


void     Manager_delete(void *_self)
{
    Manager *self = _self;
    g_array_free(self->subsystem_darray, TRUE);
    g_array_free(self->entity_darray, TRUE);
    FREE(self);
}


void     Manager_init(void *_self)
{
    Manager *self = _self;
    self->app = NULL;
    self->subsystem_darray = g_array_new(TRUE, TRUE, sizeof(Subsystem *));
    self->entity_darray    = g_array_new(TRUE, TRUE, sizeof(Entity *));
    self->update = Manager_update;
    self->delete = Manager_delete;
}


void     Manager_update(void *_self, float sf)
{
    if (!_self)
        return;
    Manager *self = _self;
    self->app->app_running = 0;
}


