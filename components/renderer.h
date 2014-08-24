#ifndef __RENDERER_H__
#define __RENDERER_H__


#include <SDL2/SDL_render.h>

#include "component.h"


// -- Renderer -- //
CLASS_EXT(Renderer,Component,
	SDL_Renderer *ren;
)

void        Renderer_init(void *_self);
void        Renderer_update(void *_self);
void        Renderer_clean(void *_self);


#endif /* __RENDERER_H__ */

