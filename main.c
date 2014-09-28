#include "app.h"

int main(int argc, const char *argv[])
{
    int ret;
    App app;
    ret = INIT(App, app);
    assert(ret == 0);
    App_run(&app);
    CLEAN(app);
    return 0;
}
