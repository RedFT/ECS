#ifndef __MN_RENDER_H__
#define __MN_RENDER_H__

#include "ooc.h"
#include "mn_manager.h"
#include "ss_render.h"

#include <SDL2/SDL_render.h>


CLASS_EXT(RenderManager, Manager,
    SDL_Renderer *sdl_ren;
    RenderSubsystem render_ssys;  
)

void RenderManager_init(void *_self);
void RenderManager_clean(void *_self);
void RenderManager_update(void *_self, double sf);
void RenderManager_registerApp(void *_self, App *app);
void RenderManager_registerSubsystem(void *_self, Subsystem *ssys);
void RenderManager_registerEntity(void *_self, Entity *ent);

void RenderManager_renderScreen(RenderManager *self);

#endif /* __MN_RENDER_H__ */

