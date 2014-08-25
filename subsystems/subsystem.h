#ifndef __SUBSYSTEM_H__
#define __SUBSYSTEM_H__

#include <glib.h>

#include "ooc.h"

#include "entities/entity.h"
#include "components/component.h"


CLASS(Subsystem,
    char   subsystem_name[100];
	GArray *entity_darray;
	void (*update)(void *_self, double sf);
	void (*clean)(void *_self);
)


void       Subsystem_init(void *_self);
void       Subsystem_update(void *_self, double sf);
void       Subsystem_clean(void *_self);


#endif /* __SUBSYSTEM_H__ */
