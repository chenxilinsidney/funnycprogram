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
    // create ipv4 address
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    server_addr.sin_family = PF_INET;
#if 0
    // expression from int to string for ip address
    char str[INET_ADDRSTRLEN] = "0.0.0.0";
    int ton = 0;
    if ((ton = inet_pton(PF_INET, str, (void*)(&(server_addr.sin_addr)))) == 1)
        printf("expression to n = %d\n", ton);
    if (inet_ntop(PF_INET, (void*)(&(server_addr.sin_addr)),
                str, INET_ADDRSTRLEN) != NULL)
        printf("expression to p = %s\n", str);
#endif
    // set port reuse faster
    int reuse = 1;
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &reuse,
                sizeof(reuse)) < 0) {
        perror("can not set socket option.");
        close(socketfd);
        exit(errno);
    }
    // bind socket with address
    if (bind(socketfd, (struct sockaddr*)(&server_addr),
                sizeof(server_addr)) < 0) {
        perror("can not bind socket descriptor with address.");
        close(socketfd);
        exit(errno);
    }
    // start listen as an server
    if (listen(socketfd, SOMAXCONN) < 0) {
        perror("can not start listen by socket descriptor.");
        close(socketfd);
        exit(errno);
    }
    while (1) {
        // request for client
        int connfd = -1;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        if ((connfd = accept(socketfd, (struct sockaddr*)(&client_addr), &client_len)) < 0) {
            perror("can not accept by server.");
            close(socketfd);
            exit(errno);
        }
        // print client information
        printf("client address = %s, port = %d\n", inet_ntoa(client_addr.sin_addr),
                ntohs(client_addr.sin_port));
        pid_t pid;
        pid = fork();
        if (pid < 0) {
            perror("can not fork.");
            close(connfd);
            close(socketfd);
            exit(errno);
        } else if (pid == 0) {
            // close socket fd
            close(socketfd);
            // transmission
            while (1) {
                // get data
                bzero(buf, sizeof(buf));
                int len = recv(connfd, buf, BUFLEN, 0);
                // check if getting data success
                if (len == -1) {
                    perror("can not receive from client.");
                    close(socketfd);
                    exit(errno);
                } else if (len == 0) {
                    printf("finish trans!\n");
                    break;
                }
                // data to stdout
                printf("client message: %s\n", buf);
            }
            // close connect fd
            close(connfd);
            exit(EXIT_SUCCESS);
        } else {
            // close connect fd
            close(connfd);
        }
    }
    return 0;
}
