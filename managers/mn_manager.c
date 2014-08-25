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
    self->subsystem_list = NULL;
    self->entity_list    = NULL;
}


void     Manager_clean(void *_self)
{
    if (!_self)
        return;
    Manager *self = _self;
    
    g_slist_free(self->subsystem_list);
    _INFO("Free'd Subsystem list for: %s", self->manager_type);
    g_slist_free(self->entity_list);
    _INFO("Free'd Entity list for: %s", self->manager_type);
}


void     Manager_update(void *_self, double sf)
{
    if (!_self)
        return;
    Manager *self = _self;
    Subsystem *ssys = NULL;
    
    GSList *iterator;
    for (iterator = self->subsystem_list; iterator; iterator = iterator->next)
    {
        ssys = iterator->data;
        UPDATE(*ssys, 0);
    }
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
    self->subsystem_list = g_slist_append(self->subsystem_list, ssys);
    _INFO("Added %s to %s's Subsystem list", ssys->subsystem_type, self->manager_type);
}


void     Manager_registerEntity(void *_self, Entity *ent)
{
    if (!_self)
        return;
    Manager *self = _self;
    self->entity_list = g_slist_append(self->entity_list, ent);
    _INFO("Added %s to %s's Entity list", ent->entity_type, self->manager_type);
}
