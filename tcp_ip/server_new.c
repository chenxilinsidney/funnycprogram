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
    // expression
    char str[INET_ADDRSTRLEN] = "0.0.0.0";
    int ton = 0;
    if ((ton = inet_pton(PF_INET, str, (void*)(&(socket_addr.sin_addr)))) == 1)
        printf("expression to n = %d\n", ton);
    if (inet_ntop(PF_INET, (void*)(&(socket_addr.sin_addr)), str, INET_ADDRSTRLEN) != NULL)
        printf("expression to p = %s\n", str);
    // bind socket with address
    if (bind(socketfd, (struct sockaddr*)(&socket_addr),
                sizeof(socket_addr)) < 0) {
        perror("can not bind socket descriptor with address.");
        exit(-1);
    }
    // start listen as an server
    if (listen(socketfd, SOMAXCONN) < 0) {
        perror("can not start listen by socket descriptor.");
        exit(-1);
    }
    while(1);
    return 0;
}
