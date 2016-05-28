#ifndef __ECHO_V1_H__
#define __ECHO_V1_H__

#include "AppBase.h"

class EchoV1 : public AppBase {
public:
    virtual void mainLoop() override;
    
private:
    void strEcho(int sockfd);
};

#endif // __ECHO_V1_H__