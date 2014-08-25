#ifndef APP_H

#define APP_H

#include <SDL2/SDL.h>

#include "ooc.h"
#include "constants.h"
#include "eventmanager.h"


CLASS(App,
    int app_running;
    SDL_Window *win;
    SDL_Renderer *ren;
    EventManager event_manager;
    
    
    void (*clean)(App *self);
)

int  App_init(App*self);
int  App_run(App *self);
void App_clean(App *self);

#endif /* end of include guard: APP_H */
