#ifndef __CO_RENDERER_H__
#define __CO_RENDERER_H__


#include <SDL2/SDL_render.h>

#include "co_component.h"


// -- RenderComponent -- //
CLASS_EXT(RenderComponent,Component,
	SDL_Texture *texture;
	SDL_Rect     src_rect;
	SDL_Rect     dst_rect;
)

void        RenderComponent_init(void *_self);
void        RenderComponent_update(void *_self);
void        RenderComponent_clean(void *_self);


#endif /* __CO_RENDERER_H__ */

