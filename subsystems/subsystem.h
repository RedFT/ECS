#ifndef __SUBSYSTEM_H__
#define __SUBSYSTEM_H__

#include <glib.h>

#include "ooc.h"

#include "entities/entity.h"
#include "components/component.h"


CLASS(Subsystem,
	GArray *entity_darray;
	
)


Subsystem *Subsystem_new();
void       Subsystem_update(void *self, float sf);
void       Subsystem_delete(void *self);


#endif /* __SUBSYSTEM_H__ */
