#include "en_entity.h"
#include "debug.h"

#include "ss_event.h"

#include <SDL2/SDL_image.h>



void     Entity_init(void *_self)
{
    if (!_self)
        return;
    Entity *self = _self;
    INIT_ENT("entity",Entity, self);
    self->component_list = NULL;
}


void    Entity_update(void *_self, double sf)
{
    if (!_self)
        return;
    //Entity *self = _self;
}


void    Entity_clean(void *_self)
{
    if (!_self)
        return;
    Entity *self = _self;
    g_slist_free(self->component_list);
    _INFO("Free'd Component list for: %s", self->entity_type);
}


void    Entity_load(void *_self)
{
    if (!_self)
        return;
    //Pigeon *self = _self;
    // probably won't be called
    
}


void    Entity_notify(void *_self, Entity *entity, char *event)
{
    if (!_self)
        return;
    //Entity *self = _self;
}


void    *Entity_getComponent(void *_self, char *component_type)
{
    if (!_self)
        return NULL;
    Entity *self = _self;
    
    Component *cmp = NULL;
    GSList *iterator = NULL;
    
    for (iterator = self->component_list; iterator; iterator = iterator->next)
    {
        cmp = iterator->data;
        if (!strcmp(cmp->component_type, component_type))
        {
            return cmp;
        }
    }
    return NULL;
}




void    Entity_registerComponent(void *_self, Component *component)
{
    if (!_self)
        return;
    Entity *self = _self;
    
    self->component_list = g_slist_append(self->component_list, component);
    REGISTER(*component, Entity, *self)
    _INFO("Added %s to %s's Component list", component->component_type, self->entity_type);
}


void     Pigeon_init(void *_self)
{
    if (!_self)
        return;
    Pigeon *self = _self;
    
    INIT(Entity, self->parent); // init super class
    
    INIT_ENT("pigeon", Pigeon, self);
    
    
	INIT(TransformComponent, self->transform_cmp);
    INIT(PhysicsComponent,   self->physics_cmp);
	INIT(RenderComponent,    self->render_cmp);
	
	/* Register Each Component To Itself */
	/* Extra Components Can Be Added Externally */
	REGISTER(self->parent, Component, self->transform_cmp);
	REGISTER(self->parent, Component, self->physics_cmp);
	REGISTER(self->parent, Component, self->render_cmp);
	
	sprintf(self->render_cmp.image_filename, "%s", "./res/images/Pigeon64x32.png");
        
    self->render_cmp.src_rect.w = 64;
    self->render_cmp.src_rect.h = 32;
    
    self->render_cmp.src_rect.x=0;
    self->render_cmp.src_rect.y=0;
    self->render_cmp.src_rect.w=64;
    self->render_cmp.src_rect.h=32;
    
    self->render_cmp.dst_rect.x=0;
    self->render_cmp.dst_rect.y=0;
    self->render_cmp.dst_rect.w=64;
    self->render_cmp.dst_rect.h=32;
    
    self->transform_cmp.x = 320;
    
    /*
    // Iterate through components_list
    Component *cmp = NULL;
    GSList *iterator = NULL;
    
    for (iterator = self->component_list; iterator; iterator = iterator->next)
    {
        cmp = iterator->data;
        _INFO("%s", cmp->component_type);
    }
     */
}


void    Pigeon_load(void *_self)
{
    if (!_self)
        return;
    Pigeon *self = _self;
    
    SDL_Surface *tmp = IMG_Load(self->render_cmp.image_filename);
    if (!tmp)
        INFO("Couldn't Load IMG");
        
    self->render_cmp.texture = SDL_CreateTextureFromSurface(self->render_cmp.ren, tmp);
    if (!self->render_cmp.texture)
        INFO("Couldn't Create TEX");
        
    if (tmp)
        SDL_FreeSurface(tmp);
}


void    Pigeon_update(void *_self, double sf)
{
    if (!_self)
        return;
    
    Pigeon *self = _self;
    
    
    self->physics_cmp.vy = 0;
    self->physics_cmp.vx = 0;
}


void  Pigeon_clean(void *_self)
{
    if (!_self)
        return;
    Pigeon *self = _self;
    Entity_clean(&self->parent);
}


void    Pigeon_notify(void *_self, Entity *entity, char *event)
{
    if (!_self)
        return;
    Pigeon *self = _self;
    
    if (!strcmp(event, "UP"))
    {
        self->physics_cmp.vy = -.5;
    }
    if (!strcmp(event, "DOWN"))
    {
        self->physics_cmp.vy = .5;
    }
    if (!strcmp(event, "LEFT"))
    {
        self->physics_cmp.vx = -.5;
    }
    if (!strcmp(event, "RIGHT"))
    {
        self->physics_cmp.vx = .5;
    }
    //Pigeon *self = _self;
}
