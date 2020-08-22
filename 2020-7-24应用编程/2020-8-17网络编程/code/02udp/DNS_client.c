#include <sys/types.h>          /* See NOTES */		   
#include <sys/socket.h>
#include <sys/socket.h>			   
#include <netinet/in.h>			   
#include <arpa/inet.h>
#include <linux/socket.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int sock;
struct sockaddr_in sa;
/*
	generate_question:解析域名数据
*/
void generate_question(char*dns_name,char*buf,int*len)
{
	char*pos = dns_name;//指向域名当前位置
	char*ptr = buf;
	int n = 0;
	*len = 0;
	
	while(1)
	{
		n = strlen(pos) - (strstr(pos , ".") ? strlen(strstr(pos , ".")) : 0);
		*ptr ++ = (unsigned char)n;
		memcpy(ptr,pos,n);
		*len += n + 1;
		ptr += n;
		if(!strstr(pos , ".")){
			*ptr = (unsigned char)0;
			ptr ++;
			*len += 1;
			break;
		}
		pos += n + 1;
	}
	
}
/*
	send_dns_request:解析域名数据，并发送数据包
*/
void send_dns_request(char * dns_name)
{
	unsigned char request[256] = {0}; //保存整个请求报文
	unsigned char *ptr = request;
	unsigned char question[128];//存储域名解析数据
	int question_len;
	
	//产生请求(把字符串表示的域名转换成DNS要求的格式)
	generate_question(dns_name , question ,&question_len);
	
	*((unsigned short*)ptr) = htons(0x2222);
	ptr += 2;
	*((unsigned short*)ptr) = htons(0x0100);
	ptr += 2;
	*((unsigned short*)ptr) = htons(1);
	ptr += 2;
	*((unsigned short*)ptr) = 0;
	ptr += 2;
	*((unsigned short*)ptr) = 0;
	ptr += 2;
	*((unsigned short*)ptr) = 0;
	ptr += 2;
	//把域名(www.baidu.com)装换为相应的问题格式保存在此处,以\0结尾
	memcpy(ptr , question , question_len);
	ptr += question_len;
	
	*((unsigned short*)ptr) = htons(1); //获取IPV4地址
	ptr += 2;
	
	*((unsigned short*)ptr) = htons(1); //指互联网地址

	int re = sendto(sock, request,question_len+16 ,0, (struct sockaddr*)&sa, sizeof(sa));
	printf("re = %d\n",re);
	int i;
	for(i=0;i<re;i++)//以16进制格式打印出来
	{
		printf("%02X ",(unsigned char)request[i]);
	}  

	printf("===================\n");
}

/*
	recv_dns_response:获取域名所对应的IP地址，并打印
*/
void recv_dns_response()
{
	struct sockaddr src_addr;
	socklen_t addrlen = sizeof(src_addr);
	
	char buf[255] = {0};
	int r =   recvfrom(sock, buf, 255, 0, (struct sockaddr*) &src_addr,&addrlen);
	if(r > 0)//收到大于0的数据
    {
		int i;
  		for(i=r-4;i<r;i++)//以16进制格式打印出来
		{
			if(i != r-1)
				printf("%d.",(unsigned char)buf[i]);
			else
				printf("%d\n",(unsigned char)buf[i]);
		}      
    }
}
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage : %s <domain name>\n",argv[0]);
		return -1;
	}
	
	//step 1: 创建一个套接字
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
	{
		perror("socket error:");
		return -1;
	}

	//step 2: 绑定一个地址(ip+端口号)
	memset(&sa, 0,sizeof(sa));

	sa.sin_family = AF_INET;
	sa.sin_port = htons(53);  //按"网络字节序"来保存一个整数
	sa.sin_addr.s_addr = inet_addr("114.114.114.114");

	
	//发送解析请求
	send_dns_request(argv[1]);
 
	//接收分析结果
	recv_dns_response();
 
	
	close(sock);
	
	return 0;
}


