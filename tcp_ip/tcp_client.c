#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 7777
#define BUFLEN 4096
char buf[BUFLEN];    

int main()
{
    // create socket descriptor
    int socketfd = 0;
    if ((socketfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("can not create socket descriptor.");
        exit(socketfd);
    }
    printf("socket descriptor = %d\n", socketfd);
    // create address for server
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
    while (1) {
        // get message from stdin
        printf("enter your message:");
        bzero(buf, BUFLEN);
        fgets(buf, BUFLEN, stdin);
        // special case blank input
        if (!strcmp(buf, "\n")) {
            printf("client stop\n");
            break;
        }
        // send without '\n'
        int len = send(socketfd, buf, strlen(buf) - 1, 0);
        if (len > 0)
            printf("send successful\n");            
        else
            printf("send failed\n");
    }
    // close socket
    close(socketfd);
    return 0;
}
