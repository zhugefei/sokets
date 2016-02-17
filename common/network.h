#ifndef __NETWORK_H__
#define __NETWORK_H__


#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>


#define	MAXLINE		4096
#define SA      struct sockaddr


void error(const char* msg);
void log(const char* msg);


#endif // __NETWORK_H__
