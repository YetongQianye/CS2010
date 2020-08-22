#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
    
#define  PORT 1234
#define  BACKLOG 1

int main()
{
    int  listen_fd, connect_fd;
    struct  sockaddr_in server;
    struct  sockaddr_in client;
    socklen_t  addrlen;
    if((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Creating  socket failed.");
        exit(1);
    }
    int opt =SO_REUSEADDR;
    setsockopt(listen_fd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr= htonl (INADDR_ANY);
    if(bind(listen_fd, (struct sockaddr *)&server, sizeof(server)) == -1) 
    {
        perror("Binderror.");
        exit(1);
    }   
    if(listen(listen_fd,BACKLOG)== -1)
    {  /* calls listen() */
        perror("listen()error\n");
        exit(1);
    }
    addrlen =sizeof(client);
    if((connect_fd = accept(listen_fd,(struct sockaddr*)&client,&addrlen))==-1) 
    {
        perror("accept()error\n");
        exit(1);
    }
    printf("Yougot a connection from cient's ip is %s, prot is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
    send(connect_fd,"Welcometo my server.\n",22,0);
    close(connect_fd);
    close(listen_fd);
    return 0;
}