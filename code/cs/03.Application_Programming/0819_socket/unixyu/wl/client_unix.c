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
    int sock;
    if ((sock = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
        ERR_EXIT("create unix socket failed");

    struct sockaddr_un servaddr;
    servaddr.sun_family = AF_UNIX; //这里指定unix域协议
    strcpy(servaddr.sun_path, "test socket");

    //start connect to the server
    if (connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
        ERR_EXIT("connect failed");

    char buf[1024];
    while (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        write(sock, buf, strlen(buf));
        read(sock, buf, sizeof(buf));//read reply from server

        printf("received from server: %s\r\n", buf);
        memset(buf, 0, sizeof(buf));
    }

    close(sock);
}