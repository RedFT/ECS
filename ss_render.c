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
    
    self->registerEntity = RenderSubsystem_registerEntity;
    
    _INFO("Initialized %s", self->subsystem_type);
}


void RenderSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    RenderSubsystem *self = _self;
    
    Entity *ent = NULL;
    GSList *iterator = NULL;
    RenderComponent *render_cmp = NULL;
    for (iterator = self->entity_list; iterator; iterator = iterator->next)
    {
        ent = iterator->data;
        if (ent)
        {
            render_cmp = ent->getComponent(ent, "rendercomponent");
                
            if (render_cmp)
            {
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


void RenderSubsystem_registerEntity(void *_self, Entity *entity)
{
    if (!_self)
        return;
    RenderSubsystem *self = _self;
    RenderComponent *ren_cmp = entity->getComponent(entity, "rendercomponent");
    if (ren_cmp)
    {
        INFO("FOUND RenderComponent");
        ren_cmp->ren = self->sdl_ren;
        entity->load(entity);
    }
    else
    {
        INFO("Couldn't find RenderComponent");
    }
    self->entity_list = g_slist_append(self->entity_list, entity);
    _INFO("Added %s to %s's Entity list", entity->entity_type, self->subsystem_type);
}
