#include "mn_scene.h"
#include "app.h"
#include "debug.h"


void SceneManager_init(void *_self)
{
    if (!_self)
        return;
    SceneManager *self = _self;
    
    INIT(Manager, self->parent); // init superclass
    
    INIT_MAN("scenemanager", SceneManager, self); // assign function pointers
    self->registerApp = SceneManager_registerApp;
    
    INIT(EventSubsystem, self->event_ssys);
}


void SceneManager_update(void *_self, double sf)
{
    if (!_self)
        return;
    //SceneManager *self = _self;
}


void SceneManager_clean(void *_self)
{
    if (!_self)
        return;
    SceneManager *self = _self;
    
    
    CLEAN(self->event_ssys);
    
    Manager_clean(&self->parent);
}


void SceneManager_registerApp(void *_self, App *app)
{
    if (!_self)
        return;
    SceneManager *self = _self;
    self->app = app;
    _INFO("Registered app to %s", self->manager_type);
}
