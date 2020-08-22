#include <unistd.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define ERR_EXIT(m)\
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main()
{
    int sockfd = socket(AF_INET,SOCK_STREAM, 0);	
    if(sockfd == -1)
    {
        perror("sock error");
        return -1;
    }

    struct sockaddr_un server_addr;
    server_addr.sun_family = AF_UNIX; //这里指定unix域协议
    strcpy(server_addr.sun_path, "test socket");

    //start connect to the server
    //if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    //    ERR_EXIT("connect failed");
    //int ret = connect(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr));
    if(connect(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr)) < 0)
    {
        perror("connect error");
        close(sockfd);
        return -1;
    }
    printf("connect success\n");

    char buf[1024];
    while (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        write(sockfd, buf, strlen(buf));
        read(sockfd, buf, sizeof(buf));//read reply from server

        printf("received from server: %s\r\n", buf);
        memset(buf, 0, sizeof(buf));
    }

    close(sockfd);
}