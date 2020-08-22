#include<stdio.h>
#include<string.h>
#include<time.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//NTP获取的时间是从1900年1.1到现在的秒数

#define NTP_SEC 2208988800ull //1900~1970年的时间差(秒数)

int main(int argc,char *argv)
{
	//创建一个UDP套接字
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd == -1)
	{
		perror("socket error");
		return -1;
	}
	
	//初始化服务器的网络地址(你的数据包发给谁)
	//服务器地址:port 123       IP:182.92.12.11
	struct sockaddr_in sAddr;
	sAddr.sin_family = AF_INET;
	sAddr.sin_port = htons(123); //端口号
	sAddr.sin_addr.s_addr = inet_addr("182.92.12.11"); //服务器地址

	
	//发送网络时间协议数据包给服务器
	unsigned char buf[48] = {0};
	buf[0] = 0x1b; //00 011 011
	
	int res = sendto(sockfd,buf,48,0,(struct sockaddr *)&sAddr,sizeof(sAddr));
	
	//接受网络时间服务器的回应报文
	//保存发送方的地址
	struct sockaddr_in cAddr;
	socklen_t len = sizeof(cAddr);
	res = recvfrom(sockfd,buf,48,0,(struct sockaddr *)&cAddr,&len); //
	if(res > 0)
	{
		printf("res = %d\n",res);
		printf("server IP:%s,port:%d\n",inet_ntoa(cAddr.sin_addr),ntohs(cAddr.sin_port));
		//传送时间戳,1900年1月1日到现在的秒数(保存在前32位中)
		unsigned int rec_sec = *((int *)(buf+40));
		rec_sec = ntohl(rec_sec);//转换成主机字节序
		//ctime,把一个“秒数”转成时间字符串
		//time_t 这个类型可以表示1970年1月1日到现在的秒数
		time_t timep;//保存1970年1月1日到现在的秒数
		timep = rec_sec - NTP_SEC;
		printf("NTP time :%s\n",ctime(&timep));
	}
	
	//关闭socket
	close(sockfd);
	return 0;
}






















