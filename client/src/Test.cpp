#include "Test.h"
#include "network.h"

void Test::mainLoop() {
    union {
        short s;
        char c[sizeof(short)];
    } un;
    
    un.s = 0x0102;
    if (un.c[0] == 1 && un.c[1] == 2) {
        std::cout << "big-endian" << std::endl;
    } else if (un.c[0] == 2 && un.c[1] == 1) {
        std::cout << "little-endian" <<std::endl;
    }
    std::cout << std::hex << un.s << std::endl;
}