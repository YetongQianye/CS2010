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
    if(argc !=3)
    {
        printf("argc num error");
        return -1;
    }

    //1.创建一个网络编程接口(socket)
    int sockfd = socket(AF_INET,SOCK_STREAM, 0);	
    if(sockfd == -1)
    {
        perror("sock error");
        return -1;
    }
    

    //2.连接服务器(connect)
    //连接前要设置好服务器的IP地址
    struct sockaddr_in Saddr;   //IPV4服务器的地址结构体
    memset(&Saddr,0,sizeof(Saddr)); //初始化Saddr为0，设置长度为sizeof...
    Saddr.sin_family = AF_INET;     //设置IPV 4
    Saddr.sin_port = htons(atoi(argv[2]));  //设置端口
    
    Saddr.sin_addr.s_addr = inet_addr(argv[1]);
    
    //将sockfd指定的socket连接到Saddr描述的服务器
    int ret = connect(sockfd, (struct sockaddr *)&Saddr,sizeof(Saddr));
    if(-1 == ret)
    {
        perror("connect error");
        close(sockfd);
        return -1;
    }
    printf("connect success\n");
    
    //3.往套接字上面发送数据/接收数据 
    char buf[BUFSIZ] = {0};
    int i = 5;
    while(i--)
    {
        #if 0
        memset(buf,0,BUFSIZ);
        fgets(buf,BUFSIZE,stdin);
        ret = send(sockfd,buf,strlen(buf)+1,0);
        printf("sent ret = %d\n",ret);
        memset(buf,0,BUFSIZE);
		//ret = recv(sockfd,buf,BUFSIZE,0);

		struct sockaddr_in addr;//保存IPV4消息发送方的地址
		memset(&addr,0,sizeof(addr));
		socklen_t addlen = sizeof(addr);
		printf("before recvform:addlen = %d\n",addlen);

       /*  //接收
		ret = recvfrom(sockfd,buf,BUFSIZE,0,(struct sockaddr *)&addr,&addlen);
		printf("after recvform:addlen = %d\n",addlen);
		printf("server IP:%s,Port:%u\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port)); 
				
		printf("recv ret = %d\n",ret);
		printf("buf:%s\n",buf);   */
        #endif
        memset(buf,0,BUFSIZE);
		fgets(buf,BUFSIZE, stdin);
		ret = send(sockfd,buf,strlen(buf)+1,0);
		printf("sent ret = %d\n",ret);
		
		memset(buf,0,BUFSIZE);
		ret = recv(sockfd,buf,BUFSIZE,0);

        printf("recv ret = %d\n",ret);
		printf("buf:%s\n",buf);
    }
    

    //4.关闭套接字
	close(sockfd);
 
    return 0;
}