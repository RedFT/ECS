#ifndef __SUBSYSTEM_H__
#define __SUBSYSTEM_H__

#include <glib.h>

#include "ooc.h"

#include "entities/entity.h"
#include "components/component.h"


#define INIT_SUBSYS(type,class,object)  \
    strcpy(self->subsystem_type, type); \
    self->update = class##_update;      \
    self->clean  = class##_clean;       \


CLASS(Subsystem,
    char   subsystem_type[100];
	GArray *entity_darray;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
)


void       Subsystem_init(void *_self);
void       Subsystem_update(void *_self, double sf);
void       Subsystem_clean(void *_self);


#endif /* __SUBSYSTEM_H__ */
