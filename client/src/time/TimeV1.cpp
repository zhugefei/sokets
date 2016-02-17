#include "TimeV1.h"
#include "network.h"


void TimeV1::mainLoop() {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    
    const char *ip = "127.0.0.1";
    
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("soket error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(191123);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0)
        error("ip error");
    
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
        error("connect error");
    
    while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)
            error("fputs error");
    }
    
    if (n < 0)
        error("read error");
}
