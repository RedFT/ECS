#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <glib.h>

#include "ooc.h"


#define INIT_MAN(type,class,object)               \
    strcpy(object->manager_type, type);      \
    object->update      = class##_update;    \
    object->clean       = class##_clean;     \
    object->registerApp = class##_registerApp;

typedef struct App App;

CLASS(Manager,
    char manager_type[100];
    App *app;
    GArray *subsystem_darray;
    GArray *entity_darray;
    void (*update)(void *_self, double sf);
    void (*clean)(void *_self);
    void (*registerApp)(void *_self, App *app);
)

void     Manager_init(void *_self);
void     Manager_clean(void *_self);
void     Manager_update(void *_self, double sf);
void     Manager_registerApp(void *_self, App *app);

#endif /* __MANAGER_H__ */

