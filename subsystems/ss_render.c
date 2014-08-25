#include "ss_render.h"
#include "en_entity.h"

#include "debug.h"


void RenderSubsystem_init(void *_self)
{
    if (!_self)
        return;
    RenderSubsystem *self = _self;
    
    INIT(Subsystem, self->parent);  // init superclass
    
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
            _INFO("Retrieving Render Component from %s", ent->entity_type);
            render_cmp = ent->getComponent(ent, "rendercomponent");
            if (render_cmp)
            {
                _INFO("Rendering %s", ent->entity_type);
                SDL_RenderCopy(self->sdl_ren,
                    render_cmp->texture,
                    &render_cmp->src_rect,
                    &render_cmp->dst_rect);
            }
            else
            {
                _INFO("Couldn't Render %s", ent->entity_type);
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
