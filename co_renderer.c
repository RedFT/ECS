#include "co_renderer.h"


void      RenderComponent_init(void *_self)
{
    if (!_self)
        return;
    RenderComponent *self = _self;
    self->ren = NULL;
    
    INIT(Component, self->parent);
    
    INIT_COMP("rendercomponent", RenderComponent, self);
    
    self->texture = NULL;
    self->src_rect = (SDL_Rect) {0, 0, 0, 0};
    self->dst_rect = (SDL_Rect) {0, 0, 0, 0};
}


void       RenderComponent_update(void *_self)
{
    if (!_self)
        return;
    // RenderComponent *self = _self;
}


void       RenderComponent_clean(void *_self)
{
    if (!_self)
        return;
    RenderComponent *self = _self;
    
    Component_clean(&self->parent);
    
}
