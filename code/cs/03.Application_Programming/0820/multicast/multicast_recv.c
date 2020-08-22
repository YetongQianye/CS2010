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
    if(argc !=3)
    {
        printf("arg num error");
        return -1;
    }

    //1.创建一个IPV4的UDP套接字
    int sockfd = socket(AF_INET,SOCK_DGRAM, 0);	
	if(sockfd == -1)
	{
		perror("create socket error");
		return -1;
	}

    //2.加入多播组
    struct ip_mreq
    {
        struct in_addr imr_multiaddr;   //多播组ip地址
        struct in_addr imr_interface;   //加入的客户端ip地址

    };
    struct ip_mreq mreq;
    memset(&mreq,0,sizeof(mreq));
    mreq.imr_multiaddr.s_addr = inet_addr(argv[1]);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    int r = setsockopt(sockfd,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&mreq,sizeof(mreq));
    if(r == -1)
    {
        perror("setsockopt error");
        return -1;
    }
    
    //3.绑定一个地址(ip+端口号)
    struct sockaddr_in Multiaddr;   //IPV4多播地址结构体
    memset(&Multiaddr,0,sizeof(Multiaddr));
    Multiaddr.sin_family = AF_INET;
    Multiaddr.sin_port = htons(atoi(argv[2]));  //端口号,"网络字节序"
    Multiaddr.sin_addr.s_addr = inet_addr(argv[1]); //网络多播地址 

    r = bind(sockfd,(struct sockaddr *)&Multiaddr,sizeof(Multiaddr));
    if(-1==r)
    {
        perror("bind error");
        close(sockfd);
        return -1;
    }
    //4.从多播组上读写消息
    char buf[1024] = {0};
    while (1)
    {
        //保存多播发送者的地址
        struct sockaddr_in addr;
        socklen_t addlen = sizeof(addr);
        memset(buf,0,1024);

        r = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&addr,&addlen);
        printf("---------------------------\n");
		printf("send IP:%s,Port:%u\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
		printf("ret = %d,buf:%s\n",r,buf);

        
    }
    close(sockfd);
 
    return 0;
}