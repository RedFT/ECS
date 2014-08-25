#include "manager.h"
#include "subsystem.h"
#include "entity.h"
#include "app.h"
#include "debug.h"


void     Manager_init(void *_self)
{
    if (!_self)
        return;
    Manager *self = _self;
    
    self->app = NULL;
    self->subsystem_darray = g_array_new(TRUE, TRUE, sizeof(Subsystem *));
    self->entity_darray    = g_array_new(TRUE, TRUE, sizeof(Entity *));
    INIT_MAN("manager", Manager, self);
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
    Manager *self = _self;
    
    self->app->app_running = 0;
}


void     Manager_registerApp(void *_self, App *app)
{
    if (!_self)
        return;
    Manager *self = _self;
    
    self->app = app;
}

