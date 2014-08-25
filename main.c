#include "app.h"

int main(int argc, const char *argv[])
{
    int ret;
    App app;
    ret = INIT(App, app);
    if (ret)
        exit(1);
    App_run(&app);
    CLEAN(app);
    return 0;
}
