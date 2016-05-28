#include "TimeV1.h"
#include "Test.h"
#include "EchoV1.h"
#include <iostream>

int main(int argc, const char * argv[]) {

    EchoV1 app;
    app.mainLoop();
    
    return 0;
}
