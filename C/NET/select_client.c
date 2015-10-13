/*************************************************************************
 *  --------->    FILE: select_client.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/13/2015    TIME:16:47:41
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define portnumber 8000

int main(int argc, char **argv) {
    int nbytes;
    int sockfd;
    char buffer[80];
    char buffer_2[80];
    struct sockaddr_in server_addr;
    struct hostent *host;

    if (argc != 2) {
        printf("Using hostname\n");
        exit(1);
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("get hostname error\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Socket error\n");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portnumber);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1) {
        printf("connect error\n");
        exit(1);
    }

    while (1) {
        printf("Please input char:\n");
        fgets(buffer, 1024, stdin);
        printf("len = %d, buffer = %s\n", strlen(buffer), buffer);
        write(sockfd, buffer, strlen(buffer));
        if ((nbytes = read(sockfd, buffer_2, 81)) == -1) {
            printf("read error\n");
            exit(1);
        }
        buffer_2[nbytes] = '\0';
        printf("Client received from Server %s\n", buffer_2);
    }
    close(sockfd);
    exit(0);
}
