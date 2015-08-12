#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 7777

int main()
{
    // create socket descriptor
    int socketfd = 0;
    if ((socketfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("can not create socket descriptor.");
        exit(socketfd);
    }
    printf("socket descriptor = %d\n", socketfd);
    // create address
    struct sockaddr_in socket_addr;
    bzero(&socket_addr, sizeof(socket_addr));
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    socket_addr.sin_port = htons(PORT);
    socket_addr.sin_family = PF_INET;
    // try to connect
    if (connect(socketfd, (struct sockaddr*)(&socket_addr),
                sizeof(socket_addr)) < 0) {
        perror("can not connect by socket descriptor.");
        exit(-1);
    }
    while(1);
    return 0;
}
