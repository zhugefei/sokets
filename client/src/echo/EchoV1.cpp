#include "EchoV1.h"
#include "network.h"

void EchoV1::mainLoop() {
    int sockfd;
    struct sockaddr_in servaddr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("socket error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(191123);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
        error("connet error");
    
    strCli(stdin, sockfd);
    
    exit(0);
}

void EchoV1::strCli(FILE *fp, int sockfd) {
    char sendline[MAXLINE], recvline[MAXLINE];
    
    static int i = 0;
    
    while (fgets(sendline, MAXLINE, fp) != NULL) {
        if (write(sockfd, sendline, strlen(sendline)) < 0)
            error("write error");
        
        if (i == 1) {
            write(sockfd, sendline, strlen(sendline));
            write(sockfd, sendline, strlen(sendline));
            write(sockfd, sendline, strlen(sendline));
        }
        i++;
        
        bzero(recvline, sizeof(recvline));
        if (read(sockfd, recvline, MAXLINE) == 0)
            error("read error");
        
        fputs(recvline, stdout);
    }
}