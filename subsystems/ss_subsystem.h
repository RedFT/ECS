#ifndef __SS_SUBSYSTEM_H__
#define __SS_SUBSYSTEM_H__

#include <glib.h>

#include "ooc.h"

#include "en_entity.h"
#include "co_component.h"


#define INIT_SUBSYS(type,class,object)  \
    strcpy(self->subsystem_type, type); \
    self->update = class##_update;      \
    self->clean  = class##_clean;       \
    self->registerEntity = Subsystem_registerEntity \


CLASS(Subsystem,
    char   subsystem_type[100];
	GArray *entity_darray;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
	void (*registerEntity)(void *_self, Entity *entity);
)


void       Subsystem_init(void *_self);
void       Subsystem_update(void *_self, double sf);
void       Subsystem_clean(void *_self);
void       Subsystem_registerEntity(void *_self, Entity *entity);

#endif /* __SS_SUBSYSTEM_H__ */
