#include "ss_render.h"
#include "en_entity.h"

#include "debug.h"


void RenderSubsystem_init(void *_self)
{
    if (!_self)
        return;
    RenderSubsystem *self = _self;
    
    INIT(Subsystem, self->parent);  // init superclass
    
    self->sdl_ren = NULL;
    INIT_SUBSYS("rendersubsystem", RenderSubsystem, self);
    
    _INFO("Initialized %s", self->subsystem_type);
}


void RenderSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    RenderSubsystem *self = _self;
    
    Entity *ent;
    GSList *iterator;
    RenderComponent *render_cmp = NULL;
    for (iterator = self->entity_list; iterator; iterator = iterator->next)
    {
        ent = iterator->data;
        if (ent)
        {
            render_cmp = ent->getComponent(ent, "rendercomponent");
            _INFO("src_rect: x: %d, y: %d, w: %d, h: %d", 
                render_cmp->src_rect.x,
                render_cmp->src_rect.y,
                render_cmp->src_rect.w,
                render_cmp->src_rect.h);
            
            _INFO("dst_rect: x: %d, y: %d, w: %d, h: %d", 
                render_cmp->dst_rect.x,
                render_cmp->dst_rect.y,
                render_cmp->dst_rect.w,
                render_cmp->dst_rect.h);
                
            if (render_cmp)
            {
                _INFO("Rendering: %s", ent->entity_type);
                SDL_RenderCopy(self->sdl_ren,
                    render_cmp->texture,
                    &render_cmp->src_rect,
                    &render_cmp->dst_rect);
            }
            else
            {
            }
        }
    }
}


void RenderSubsystem_clean(void *_self)
{
    if (!_self)
        return;
    RenderSubsystem *self = _self;
    
    Subsystem_clean(&self->parent);
}
