#include "TimeV1.h"
#include "network.h"


void TimeV1::mainLoop() {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    time_t ticks;
    
    if ( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("socket error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(191123);
    
    if (bind(listenfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
        error("bind error");
    
    if (listen(listenfd, 5) < 0)
        error("listen error");
   
    while (1) {
        if ( (connfd = accept(listenfd, (SA*)NULL, NULL)) < 0)
            break;
        
        ticks = time(NULL);
        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
        write(connfd, buf, strlen(buf));
        
        close(connfd);
    }
    
    close(listenfd);
    if (connfd < 0)
        error("accept error");
}