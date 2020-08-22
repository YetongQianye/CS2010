#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//服务器的IP和端口号通过命令行参数传递
//./Udpserver  IP  Port

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("arg num not Yes\n");
		return -1;
	}

	//1.创建一个IPV4的UDP套接字
	int sockfd = socket(AF_INET,SOCK_DGRAM, 0);	
	if(sockfd == -1)
	{
		perror("create socket error");
		return -1;
	}

	//2.为UDP服务器绑定一个IP地址(首先得自己有一个地址结构体)
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

	//3.从sockfd中读取其他客户端发送给我的消息
	while(1)
	{
		char buf[1024] = {0};
		//int ret = recvfrom(sockfd,buf,1024,0,NULL,NULL);
		//保存客户端的地址
		struct sockaddr_in Caddr;
		socklen_t addlen = sizeof(Caddr); 
		//读取客户端的消息,并且保存客户端的地址信息
		int ret = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&Caddr,&addlen);
		printf("Client IP:%s,Port:%u\n",inet_ntoa(Caddr.sin_addr),ntohs(Caddr.sin_port));
		printf("ret = %d,buf:%s\n",ret,buf);

		memset(buf,0,1024);
		fgets(buf,1024,stdin);
		//必须指定目的地的地址
		ret = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&Caddr,sizeof(Caddr));
		printf("ret = %d\n",ret);
		
	}		

	close(sockfd);
	return 0;
}














