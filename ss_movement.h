#ifndef __SS_MOVEMENT_H__
#define __SS_MOVEMENT_H__

#include "ooc.h"
#include "ss_subsystem.h"


CLASS_EXT(MovementSubsystem, Subsystem,
    int dummy;
)


void       MovementSubsystem_init(void *_self);
void       MovementSubsystem_update(void *_self, double sf);
void       MovementSubsystem_clean(void *_self);

#endif /* __SS_MOVEMENT_H__ */
