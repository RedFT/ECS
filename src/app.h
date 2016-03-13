#ifndef APP_H

#define APP_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>


#include "ooc.h"
#include "constants.h"
#include "mn_event.h"
#include "mn_scene.h"
#include "mn_render.h"


CLASS(App,
    int app_running;
    SDL_Window *win;
    SDL_Renderer *ren;
    EventManager event_manager;
    SceneManager scene_manager;
    RenderManager render_manager;
    
    
    void (*clean)(App *self);
)

int  App_init(App*self);
int  App_run(App *self);
void App_clean(App *self);

#endif /* end of include guard: APP_H */
