#include "network.h"

using namespace std;

void error(const char* msg) {
    cout << msg << ", " << strerror(errno) << endl;
    fflush(stdout);
    exit(0);
}

void log(const char* msg) {
    cout << msg << ", " << strerror(errno) << endl;
}
