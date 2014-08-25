#ifndef __CO_RENDERER_H__
#define __CO_RENDERER_H__


#include <SDL2/SDL_render.h>

#include "co_component.h"


// -- Renderer -- //
CLASS_EXT(Renderer,Component,
	SDL_Renderer *ren;
)

void        Renderer_init(void *_self);
void        Renderer_update(void *_self);
void        Renderer_clean(void *_self);


#endif /* __CO_RENDERER_H__ */

