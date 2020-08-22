#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

 
int main(int argc,char *argv[])
{   
    if(argc !=3)
    {
        printf("arg num error");
        return -1;
    }
    
    struct sockaddr_in client_addr; //客户端地址结构体
    struct sockaddr_in server_addr; //主机端地址结构体
      
    //1.创建一个网络编程接口(socket)
    int sockfd = socket(AF_INET,SOCK_DGRAM, 0);	
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
    int ret = bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    if(ret == -1)
    {
        perror("bind error");
        close(sockfd);
        return -1;
    }
    
     

    //4.从sockfd中读取其他客户端发送给我的消息
    while(1)
    {
       /*  char buf[1024] = {0};
        int ret = recvfrom(sockfd,buf,1024,0,NULL,NULL);
        printf("ret = %d,buf:%s\n",ret,buf);
        */

        char buf[1024] = {0};
		//int ret = recvfrom(sockfd,buf,1024,0,NULL,NULL);
		//保存客户端的地址
	 
		socklen_t addlen = sizeof(client_addr); 
		//读取客户端的消息,并且保存客户端的地址信息
		int ret = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&client_addr,&addlen);
		printf("Client IP:%s,Port:%u\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		printf("ret = %d,buf:%s\n",ret,buf);

		memset(buf,0,1024);
		fgets(buf,1024,stdin);
		//必须指定目的地的地址
		ret = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&client_addr,sizeof(client_addr));
		printf("ret = %d\n",ret);
    }
    
     
    close(sockfd);
    return 0;
}