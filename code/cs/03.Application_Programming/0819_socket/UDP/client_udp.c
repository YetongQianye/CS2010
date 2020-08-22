#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

 
int main(int argc,char *argv[])
{
    if(argc !=3)
    {
        printf("arg num error");
        return -1;
    }
    //连接前要设置好服务器的IP地址
     
    struct sockaddr_in client_addr; //客户端地址结构体
    struct sockaddr_in server_addr; //主机端地址结构体

    memset(&server_addr,0,sizeof(server_addr)); //初始化server_addr为0，设置长度为sizeof...
    server_addr.sin_family = AF_INET;     //设置IPV 4
    server_addr.sin_port = htons(atoi(argv[2]));  //设置端口  
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    //1.创建一个IPV4的UDP套接字(socket)
    int sockfd = socket(AF_INET,SOCK_DGRAM, 0);	
    if(sockfd == -1)
    {
        perror("sock error");
        return -1;
    }

  
    //2.sendto函数
    char buf[1024] = {0};
    fgets(buf,1024,stdin);
    int ret = sendto(sockfd,buf, 128, 0,(struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("ret = %d\n",ret);
    
    /* memset(buf,0,BUFSIZE);
    int re = recvfrom( sockfd, buf, 128, 0,(struct sockaddr *)&client_addr, &client_addr_len);
    printf("recv ret = %d\n",re);
    printf("buf:%s\n",buf); */

    //从自己的socket中读取一个消息
	//保存消息发送者的地址
	 
	socklen_t addlen = sizeof(client_addr); 
	memset(buf,0,1024);
	//读取发送者发送给我的消息,并且保存发送者的地址信息
	ret = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&client_addr,&addlen);
	printf("send IP:%s,Port:%u\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	printf("ret = %d,buf:%s\n",ret,buf);
   
    
    //4.关闭套接字
	close(sockfd);
 
    return 0;
}