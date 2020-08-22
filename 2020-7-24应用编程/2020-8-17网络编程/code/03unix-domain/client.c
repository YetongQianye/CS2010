#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>

#define UNIX_PATH "/home/china/p1.socket"
#define UNIX_PATH_1 "/home/china/p2.socket"

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

	//2.为自己绑定一个UNIX地址(首先得自己有一个地址结构体)
	struct sockaddr_un Saddr;//本进程的地址结构体
	memset(&Saddr,0,sizeof(Saddr));
	Saddr.sun_family = AF_UNIX;
	strcpy(Saddr.sun_path,UNIX_PATH_1);
	int ret = bind(sockfd,(struct sockaddr *)&Saddr,sizeof(Saddr));
	if(-1 == ret)
	{
		perror("bind error");
		close(sockfd);
		return -1;
	}


	while(1)
	{
		char buf[1024] = {0};
		struct sockaddr_un Caddr;
		memset(&Caddr,0,sizeof(Caddr));
		Caddr.sun_family = AF_UNIX;
		strcpy(Caddr.sun_path,UNIX_PATH);

		fgets(buf,1024,stdin);
		//必须指定目的地的地址
		ret = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&Caddr,sizeof(Caddr));
		printf("ret = %d\n",ret);



		socklen_t addlen = sizeof(Caddr); 
		//读取客户端的消息,并且保存客户端的地址信息
		memset(buf,0,1024);
		int ret = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&Caddr,&addlen);
		printf("Client PATH:%s\n",Caddr.sun_path);
		printf("ret = %d,buf:%s\n",ret,buf);
	}		

	close(sockfd);
	return 0;
}

