#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/un.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#define UNIX_PATH "/home/china/p1.socket"
//./Udpserver 

int main(int argc,char *argv[])
{
	//1.创建一个UNIX的UDP套接字
	int sockfd = socket(AF_UNIX,SOCK_DGRAM, 0);	
	if(sockfd == -1)
	{
		perror("create socket error");
		return -1;
	}

	//2.为UNIX服务器绑定一个UNIX地址(首先得自己有一个地址结构体)
	struct sockaddr_un Saddr;//服务器的地址结构体
	memset(&Saddr,0,sizeof(Saddr));
	Saddr.sun_family = AF_UNIX;
	strcpy(Saddr.sun_path,UNIX_PATH);
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
		//保存客户端的地址
		struct sockaddr_un Caddr;
		socklen_t addlen = sizeof(Caddr); 
		//读取客户端的消息,并且保存客户端的地址信息
		int ret = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&Caddr,&addlen);
		printf("Client PATH:%s\n",Caddr.sun_path);
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

