#include "renderer.h"


void      Renderer_init(void *_self)
{
    if (!_self)
        return;
    Renderer *self = _self;
    
    INIT(Component, self->parent);
    INIT_COMP(RENDERER, Renderer, self);
    self->component_type = RENDERER;
	self->update = Renderer_update;
	self->clean  = Renderer_clean;
}


void       Renderer_update(void *_self)
{
    if (!_self)
        return;
    // Renderer *self = _self;
}


void       Renderer_clean(void *_self)
{
    if (!_self)
        return;
    Renderer *self = _self;
    CLEAN(self->parent);
    
}
