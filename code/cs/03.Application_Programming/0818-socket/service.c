#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 256
int main(int argc,char *argv[])
{   
    struct sockaddr_in client_addr; //客户端地址结构体
    struct sockaddr_in server_addr; //主机端地址结构体
      
    //1.创建一个网络编程接口(socket)
    int sockfd = socket(AF_INET,SOCK_STREAM, 0);	
    if(sockfd == -1)
    {
        perror("sock error");
        return -1;
    }
 
    //2.bind函数，把一个协议地址赋予一个套接字
    memset(&server_addr,0,sizeof(server_addr)); //初始化server_addr为0，设置长度为sizeof...
    server_addr.sin_family = AF_INET;     //设置IPV 4
    server_addr.sin_port = htons(atoi(argv[2]));  //设置端口
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    //将sockfd指定的socket连接到server_addr描述的服务器
    int ret = bind(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr));
    if(ret == -1)
    {
        perror("bind error");
        close(sockfd);
        return -1;
    }
    
    //3.监听函数listen
    int li = listen(sockfd,100);
    if(li == -1)
    {
        perror("listen error");
        return -1;
    }

    //4.accept函数，用于从已完成连接队列队头返回下一个已完成连接
    socklen_t addlen = sizeof(client_addr);
    while (1)
    {
        //返回一个“连接套接字”
        //int *conp = (int *)malloc((sizeof int));
        int con_fd = accept(sockfd, (struct sockaddr *)&client_addr,&addlen);
        if(con_fd >0)
        {
            //可以创建一个线程通信
            printf("Client IP:%s\nPort:%u\n", inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
            char buf[256] = {0};
            ret = read(con_fd,buf,256);
            printf("ret = %d,buf:%s\n",ret,buf);

            write(con_fd,"bye",7);
            close(con_fd);

        }

    }
     
     
    return 0;
}