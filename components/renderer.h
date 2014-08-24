#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "component.h"


// -- Renderer -- //
CLASS_EXT(Renderer,Component,
	// SDL_Renderer *ren; 
	int render_dummy;
)

Renderer *Renderer_new();
void      Renderer_delete(Renderer *self);


#endif /* __RENDERER_H__ */

