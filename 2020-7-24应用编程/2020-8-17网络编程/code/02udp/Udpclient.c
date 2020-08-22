#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//服务器的IP和端口号通过命令行参数传递(你的消息要发给谁)
//./Udpclient  IP  Port

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

	//2.给指定的服务器发送消息
	//先指定服务器的地址
	struct sockaddr_in Saddr;//IPV4服务器的地址结构体
	memset(&Saddr,0,sizeof(Saddr));
	Saddr.sin_family = AF_INET;
	Saddr.sin_port = htons(atoi(argv[2]));//端口号,"网络字节序"
	//inet_aton("192.168.2.2",&(Saddr.sin_addr));
	Saddr.sin_addr.s_addr = inet_addr(argv[1]); //网络IP地址
	//发送一个消息给服务器
	char buf[1024] = {0};
	fgets(buf,1024,stdin);
	int ret = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&Saddr,sizeof(Saddr));
	printf("sendto ret = %d\n",ret);

	//从自己的socket中读取一个消息
	//保存消息发送者的地址
	struct sockaddr_in addr;
	socklen_t addlen = sizeof(addr); 
	memset(buf,0,1024);
	//读取发送者发送给我的消息,并且保存发送者的地址信息
	ret = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&addr,&addlen);
	printf("send IP:%s,Port:%u\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
	printf("ret = %d,buf:%s\n",ret,buf);

	close(sockfd);
	return 0;
}

