#include "entity.h"


Entity *Entity_new()
{
    Entity *self = malloc(sizeof(Entity));
    Entity_init(self);
    return self;
}

int     Entity_init(void *_self)
{
    Entity *self = _self;
    self->component_darray = g_array_new(TRUE, TRUE, sizeof(Component *));
    return 0;
}

void    Entity_delete(void *_self)
{
    Entity *self = _self;
    g_array_free(self->component_darray, TRUE);
	FREE(self);
}


void o() 
{
    printf("Open\n");
}

void c() 
{
    printf("Close\n");
}

Door *Door_new()
{
	Door *self = malloc(sizeof(Door));
	self->delete = Door_delete;
	self->open = o;
	self->close = c;
	
	self->transform = Transform_new();
	self->physics   = Physics_new();
	self->renderer  = Renderer_new();
	return self;
}


int     Door_init(void *_self)
{
    Door *self = _self;
    Entity_init(&self->parent);
    return 0;
}


void  Door_delete(void *_self)
{
    Door *self = _self;
    if (self->transform)
        Transform_delete(self->transform);
	if (self->physics)
	    Physics_delete(self->physics);
	if (self->renderer)
	    Renderer_delete(self->renderer);
	
	FREE(self);
}
