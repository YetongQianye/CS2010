#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/epoll.h>

int main()
{

    //1.创建一个epoll的实例
    int ep_fd = epoll_create(100);
    if(ep_fd == -1)
    {
        perror("epoll_create error");
        return -1;
    }
    //2.把所有的需要监听的文件描述符加入到epoll实例
    //把服务器的监听套接字加入文件描述符
    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data = sock_fd;//把sockfd当做用户数据存储起来
    int r = epoll_ctl(ep_fd,EPOLL_CTL_ADD,sock_fd,&event);
    //把所有的客户端连接套接字加入文件描述符
    while(???)
    {
        struct epoll_event event;
        event.events = EPOLLIN;
        event.data = con_fd;//把连接套接字当做用户数据存储起来
        int r = epoll_ctl(ep_fd,EPOLL_CTL_ADD,con_fd,&event);
    }
    
    //3.开始对epoll实例中所有文件描述符的监听
    
    while(!terminate)
    {
        struct epoll_event ev[1024] = {0};
        //把所有就绪的事件保存到events表示的数组中
        r = epoll_wait(ep_fd,ev,1024,1000);
        if(r == 0)
        {
            continue;
        }else if(r == -1)
        {
            perror("epoll_wait error");
            close(ep_fd);
            return -1;
        }

        //处理就绪的事件
        int i;
        for(i=0;i<r;i++)
        {
            //ev[i].data 就是表示已经就绪的文件描述符
            if(ev[i].data == sock_fd) //服务器就绪
            {
                accept();
            }else //客户端就绪 
            {
                read();
            }
        }
    }	

}