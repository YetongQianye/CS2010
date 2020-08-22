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

void handle_subprocess(int conn)
{
    char buf[1024];
    int ret;
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        ret = read(conn, buf, sizeof(buf));
        if (ret == -1)
        {
            if (ret == EINTR)
                continue;
            ERR_EXIT("read failed");
        }
        if (ret == 0)
        {
            printf("client closed\r\n");
            break;
        }
        printf("%s\r\n", buf);
        write(conn, buf, strlen(buf));
    }
    close(conn);
}

int main()
{
    
    //1.仍然使用socket函数创建socket，协议族指定为PF_UNIX
    /*  if ((sock = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
        ERR_EXIT("create unix socket failed"); */
    int sockfd = socket(AF_INET,SOCK_STREAM, 0);	
    if(sockfd == -1)
    {
        perror("sock error");
        return -1;
    }
    
    unlink("test socket");//先删除之前留下的socket文件
    struct sockaddr_un server_addr;
    server_addr.sun_family = AF_UNIX; //这里指定unix域协议
    strcpy( server_addr.sun_path, "test socket"); //指定socket文件，会再目录下生成该名称的文件

    //2.bind
    int ret = bind(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr));
    if(ret == -1)
    {
        perror("bind error");
        close(sockfd);
        return -1;
    }

    //3.listen监听函数
    if(listen(sockfd, SOMAXCONN) == -1)
    {
        perror("listen error");
        return -1;
    }

    int conn;
    pid_t pid;
    while(1)
    {
        conn = accept(sockfd, NULL, NULL);
        if (conn == -1)
        {
            if (conn == EINTR)
                continue;
            ERR_EXIT("accept failed");
        } 
        pid = fork();
        if (pid == -1)
            ERR_EXIT("fork failed");
        if (pid == 0)//子进程
        {
            close(sockfd);
            handle_subprocess(conn);
            exit(EXIT_SUCCESS);
        }
        else
        {
            close(conn);
        }
    }
    close(sockfd);
    return 0;
}