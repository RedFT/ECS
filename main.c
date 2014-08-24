#include "app.h"

int main(int argc, const char *argv[])
{
    App *app = App_new();
    App_run(app);
    App_delete(app);
    
    return 0;
}
