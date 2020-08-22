#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//多播地址的IP和端口号通过命令行参数传递
//./boardcast_send  IP  Port

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

	//2.初始化一个多播地址
	struct sockaddr_in Baddr;//IPV4多播的地址结构体
	memset(&Baddr,0,sizeof(Baddr));
	Baddr.sin_family = AF_INET;
	Baddr.sin_port = htons(atoi(argv[2]));//端口号,"网络字节序"
	//inet_aton("224.0.0.250",&(Saddr.sin_addr));
	Baddr.sin_addr.s_addr = inet_addr(argv[1]); //网络多播地址 224.0.0.250
	
	//4.发送消息到多播组
	while(1)
	{
		//int r = sendto(sockfd,"bro,can miximixi",20,0,(struct sockaddr *)&Baddr,sizeof(Baddr));
		//printf("ret = %d\n",r);
		//sleep(1);
		char buf[256] = {0};
		fgets(buf,256,stdin);
		int r = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&Baddr,sizeof(Baddr));
		printf("ret = %d\n",r);
	}		

	close(sockfd);
	return 0;
}

























