#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//服务器的IP和端口号通过命令行参数传递
//./TcpServer  IP  Port

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
	//2.为服务器绑定一个IP地址(首先得自己有一个地址结构体)
	struct sockaddr_in Saddr;//IPV4服务器的地址结构体
	memset(&Saddr,0,sizeof(Saddr));
	Saddr.sin_family = AF_INET;
	Saddr.sin_port = htons(atoi(argv[2]));//端口号,"网络字节序"
	//inet_aton("192.168.2.2",&(Saddr.sin_addr));
	Saddr.sin_addr.s_addr = inet_addr(argv[1]); //网络IP地址
	//将sockfd指定的socket连接到Saddr描述的服务器
	int ret = bind(sockfd,(struct sockaddr *)&Saddr,sizeof(Saddr));
	if(-1 == ret)
	{
		perror("bind error");
		close(sockfd);
		return -1;
	}

	//3.开启对一个socket的监听
	listen(sockfd,100);
	//4.accept,处理一个已经完成三次握手的请求

	struct sockaddr_in Caddr;//保存IPV4客户端的地址结构体
	socklen_t addlen = sizeof(Caddr);

	while(1)
	{
		//返回一个“连接套接字”
		//int *conp = (int *)malloc(sizeof(int));
		int confd = accept(sockfd, (struct sockaddr *)&Caddr, &addlen);
		if(confd > 0)
		{
			//可以创建一个线程通信
			printf("Client IP:%s,Port:%u\n",inet_ntoa(Caddr.sin_addr),ntohs(Caddr.sin_port));
			char buf[256] = {0};
			ret = read(confd,buf,256);
			printf("ret = %d,buf:%s\n",ret,buf);

			write(confd,"byebye",7);
			close(confd);
		}

	}

	return 0;
}

