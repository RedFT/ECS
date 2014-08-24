#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <glib.h>

#include "ooc.h"

typedef struct App App;

CLASS(Manager,
    App *app;
    GArray *subsystem_darray;
    GArray *entity_darray;
    void (*update)(void *_self, float sf);
    void (*delete)(void *_self);
)

Manager *Manager_new();
void     Manager_delete(void *_self);
void     Manager_init(void *_self);
void     Manager_update(void *_self, float sf);

#endif /* __MANAGER_H__ */

