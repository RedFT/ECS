#include "renderer.h"


Renderer *Renderer_new()
{
    Renderer *self = malloc(sizeof(Renderer));
    self->component_type = RENDERER;
    return self;
}
void      Renderer_delete(Renderer *self)
{
    FREE(self);
}
