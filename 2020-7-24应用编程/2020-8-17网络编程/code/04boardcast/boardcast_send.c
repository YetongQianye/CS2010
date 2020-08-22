#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//广播地址的IP和端口号通过命令行参数传递
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

	//2.设置套接字选项,使能广播
	int flag = 1;		
	int r = setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,(void *)&flag,sizeof(flag));	
	if(-1 == r)
	{
		perror( "setsockopt error");
		close(sockfd);
		return -1;
	}
	//3.初始化一个广播地址
	struct sockaddr_in Baddr;//IPV4广播的地址结构体
	memset(&Baddr,0,sizeof(Baddr));
	Baddr.sin_family = AF_INET;
	Baddr.sin_port = htons(atoi(argv[2]));//端口号,"网络字节序"
	//inet_aton("192.168.2.255",&(Saddr.sin_addr));
	Baddr.sin_addr.s_addr = inet_addr(argv[1]); //网络IP地址
	
	//4.发送消息到广播地址
	while(1)
	{
		r = sendto(sockfd,"bro,can miximixi",20,0,(struct sockaddr *)&Baddr,sizeof(Baddr));
		//printf("ret = %d\n",r);
		sleep(1);
	}		

	close(sockfd);
	return 0;
}

























