#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 256

//服务器的IP和端口号通过命令行参数传递
//./TcpClient  IP  Port

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("arg num not Yes\n");
		return -1;
	}
	//1.创建一个IPV4的TCP套接字
	int sockfd = socket(AF_INET,SOCK_STREAM, 0);	
	if(sockfd == -1)
	{
		perror("create socket error");
		return -1;
	}
	
	
	//2.连接服务器
	//连接前要设置好服务器的IP地址
	struct sockaddr_in Saddr;//IPV4服务器的地址结构体
	memset(&Saddr,0,sizeof(Saddr));
	Saddr.sin_family = AF_INET;
	Saddr.sin_port = htons(atoi(argv[2]));//端口号,"网络字节序"
	//inet_aton("192.168.2.2",&(Saddr.sin_addr));
	Saddr.sin_addr.s_addr = inet_addr(argv[1]); //网络IP地址
	//将sockfd指定的socket连接到Saddr描述的服务器
	int ret = connect(sockfd, (struct sockaddr *)&Saddr,sizeof(Saddr));	
	if(-1 == ret)
	{
		perror("connect error");
		close(sockfd);
		return -1;
	}
	printf("connect success\n");
	//3.发送和接收消息
	char buf[BUFSIZE] = {0};
	int i = 5;
	while(i--)
	{
		memset(buf,0,BUFSIZE);
		fgets(buf,BUFSIZE, stdin);
		ret = send(sockfd,buf,strlen(buf)+1,0);
		printf("sent ret = %d\n",ret);
		
		memset(buf,0,BUFSIZE);
		ret = recv(sockfd,buf,BUFSIZE,0);

		//struct sockaddr_in addr;//保存IPV4消息发送方的地址
		//memset(&addr,0,sizeof(addr));
		//socklen_t addlen = sizeof(addr);
		//printf("before recvform:addlen = %d\n",addlen);
		//ret = recvfrom(sockfd,buf,BUFSIZE,0,(struct sockaddr *)&addr,&addlen);
		//printf("after recvform:addlen = %d\n",addlen);
		//printf("server IP:%s,Port:%u\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
				
		printf("recv ret = %d\n",ret);
		printf("buf:%s\n",buf);
	}

	//4.关闭套接字
	close(sockfd);
	return 0;
}




