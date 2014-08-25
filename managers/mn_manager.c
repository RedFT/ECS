#include "mn_manager.h"
#include "ss_subsystem.h"
#include "en_entity.h"
#include "app.h"
#include "debug.h"


void     Manager_init(void *_self)
{
    if (!_self)
        return;
    Manager *self = _self;
    
    INIT_MAN("manager", Manager, self);
    
    self->app = NULL;
    self->subsystem_darray = g_array_sized_new(FALSE, FALSE, sizeof(Subsystem *), 10);
    self->entity_darray    = g_array_sized_new(FALSE, FALSE, sizeof(Entity *), 10);
}


void     Manager_clean(void *_self)
{
    if (!_self)
        return;
    Manager *self = _self;
    
    g_array_free(self->subsystem_darray, TRUE);
    _INFO("Free'd Subsystem array for: %s", self->manager_type);
    g_array_free(self->entity_darray, TRUE);
    _INFO("Free'd Entity array for: %s", self->manager_type);
}


void     Manager_update(void *_self, double sf)
{
    if (!_self)
        return;
    // Manager *self = _self;
}


void     Manager_registerApp(void *_self, App *app)
{
    if (!_self)
        return;
    Manager *self = _self;
    
    self->app = app;
    _INFO("Registered app to %s", self->manager_type);
}


void     Manager_registerSubsystem(void *_self, Subsystem *ssys)
{
    if (!_self)
        return;
    Manager *self = _self;
    g_array_append_val(self->subsystem_darray, ssys);
    _INFO("Added %s to %s's Subsystem List", ssys->subsystem_type, self->manager_type);
}


void     Manager_registerEntity(void *_self, Entity *ent)
{
    if (!_self)
        return;
    Manager *self = _self;
    g_array_append_val(self->entity_darray, ent);
    _INFO("Added %s to %s's Entity List", ent->entity_type, self->manager_type);
}
