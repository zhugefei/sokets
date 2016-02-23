#ifndef __TEST_H__
#define __TEST_H__

#include "AppBase.h"


class Test : public AppBase {
public:
    virtual void mainLoop() override;
};

#endif // __TEST_H__