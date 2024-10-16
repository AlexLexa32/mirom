#include <iostream>
#include "App.h"

int32_t main() {
//    save(17, {}, light(), "goida");
    App app(1000, 800, "miror");
    while(app.render());
    return 0;
}
