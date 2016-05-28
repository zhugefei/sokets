#include "EchoV1.h"
#include "network.h"


void EchoV1::mainLoop() {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
        error("socket error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(191123);
    
    if (bind(listenfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
        error("bind error");
    
    if (listen(listenfd, 5) < 0)
        error("listen error");
    
    for(;;) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (SA*)&cliaddr, &clilen);
        if (connfd < 0)
            break;
        
        if ( (childpid = fork()) == 0) {
            close(listenfd);
            strEcho(connfd);
            exit(0);
        }
        close(connfd);
    }
    
    close(listenfd);
    if (connfd < 0)
        error("accept error");
}

void EchoV1::strEcho(int sockfd) {
    char buf[MAXLINE];
    
again:
    ssize_t n = read(sockfd, buf, MAXLINE);
    if (n > 0) {
        write(sockfd, buf, n);
    } else if (n < 0) {
        if (errno == EINTR)
            goto again;
        
        error("serEcho: read error");
    }
    close(sockfd);
    std::cout << "close connfd" << std::endl;
}