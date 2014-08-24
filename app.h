#ifndef APP_H

#define APP_H

#include <SDL2/SDL.h>

#include "ooc.h"
#include "constants.h"
#include "manager.h"


CLASS(App,
    int app_running;
    SDL_Window *win;
    SDL_Renderer *ren;
    Manager *manager;
    // EventManager event_manager;
)

App *App_new();
void App_delete(App *self);

int  App_init(App*self);
int  App_run(App *self);

#endif /* end of include guard: APP_H */
