#include "app.h"

int main(int argc, const char *argv[])
{
    App app;
    INIT(App, app);
    App_run(&app);
    CLEAN(app);
    return 0;
}
