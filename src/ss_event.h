#ifndef __SS_EVENT_H__
#define __SS_EVENT_H__

#include "ooc.h"
#include "ss_subsystem.h"
#include "e_events.h"


CLASS_EXT(EventSubsystem, Subsystem,
    void (*notify)(void *_self, Entity *ent, char *event);
)

void EventSubsystem_init(void *_self);
void EventSubsystem_update(void *_self, double sf);
void EventSubsystem_clean(void *_self);


void EventSubsystem_notify(void *_self, Entity *ent, char *event);

#endif /* __SS_EVENT_H__ */

