#ifndef __SS_RENDER_H__
#define __SS_RENDER_H__

#include "ooc.h"
#include "ss_subsystem.h"

/* Requires an entity to have a render component */
CLASS_EXT(RenderSubsystem, Subsystem,
    SDL_Renderer *sdl_ren;
)

void RenderSubsystem_init(void *_self);
void RenderSubsystem_update(void *_self, double sf);
void RenderSubsystem_clean(void *_self);
void RenderSubsystem_registerEntity(void *_self, Entity *entity);

#endif /* __SS_RENDER_H__ */

