#include "ss_movement.h"
#include "debug.h"


void MovementSubsystem_init(void *_self)
{
    if (!_self)
        return;
    MovementSubsystem *self = _self;
    INIT_SUBSYS("movementsubsystem", MovementSubsystem, self);
    self->entity_list    = NULL;
}

void MovementSubsystem_update(void *_self, double sf)
{
    if (!_self)
        return;
    MovementSubsystem *self = _self; 
    
    Entity *ent;
    GSList *iterator;
    
    TransformComponent *transform_cmp = NULL;
    RenderComponent *render_cmp = NULL;
    PhysicsComponent *physics_cmp = NULL;
    
    for (iterator = self->entity_list; iterator; iterator = iterator->next)
    {
        ent = iterator->data;
        if (ent)
        {
            transform_cmp = ent->getComponent(ent, "transformcomponent");
            render_cmp    = ent->getComponent(ent, "rendercomponent");
            physics_cmp   = ent->getComponent(ent, "physicscomponent");
                
            if (transform_cmp && render_cmp && physics_cmp)
            {
                transform_cmp->x += physics_cmp->vx;
                transform_cmp->y += physics_cmp->vy;
                
                render_cmp->dst_rect.x = transform_cmp->x;
                render_cmp->dst_rect.y = transform_cmp->y;
                
            }
            else
            {/*
                if (!transform_cmp)
                    INFO("transform NOT FOUND");
                if (!render_cmp)
                    INFO("render NOT FOUND");
                if (!physics_cmp)
                    INFO("physics NOT FOUND");*/
            }
        }
    }
}

void MovementSubsystem_clean(void *_self)
{
    
    if (!_self)
        return;
    MovementSubsystem *self = _self;
    g_slist_free(self->entity_list);
    _INFO("Free'd Entity list for: %s", self->subsystem_type);
}
