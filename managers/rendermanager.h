#ifndef __RENDERMANAGER_H__
#define __RENDERMANAGER_H__

#include "ooc.h"
#include "manager.h"
#include <SDL2/SDL_render.h>


CLASS_EXT(RenderManager, Manager,
    SDL_Renderer *sdl_ren;
)

void RenderManager_init(void *_self);
void RenderManager_clean(void *_self);
void RenderManager_update(void *_self, double sf);
void RenderManager_registerApp(void *_self, App *app);


void RenderManager_renderScreen(RenderManager *self);

#endif /* __RENDERMANAGER_H__ */

