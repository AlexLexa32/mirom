#include <iostream>
#include "App.h"

int32_t main() {
//    save(17, {}, light(), "goida");
    App app(1800, 800, "miror");
    app.render();
    return 0;
}
