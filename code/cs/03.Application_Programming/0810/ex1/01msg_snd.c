#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/msg.h>

#define PATHNAME "/home/qianye"
#define PROJ_ID 250

struct msgbuf
{
	long mtype;
	char mtext[0];//柔性数组,长度自由控制
};

int main()
{
	printf("sizeof(msgbuf) = %lu\n",sizeof(struct msgbuf));

	//利用ftok生成一个“key”
	key_t key = ftok(PATHNAME,PROJ_ID);
	if(key == -1)
	{
		perror("ftok error");
		return -1;
	}
	//利用“key”创建一个IPC对象
	int msgid =  msgget(key, IPC_CREAT | 0664);
	if(msgid == -1)
	{
		perror("msgget error");
		return -1;
	}

	//利用IPC对象进行进程间通信(发送)
	char buf[128] = {0};
	fgets(buf,128,stdin);
	
	struct msgbuf *p = malloc(sizeof(*p)+strlen(buf)+1);
	p->mtype = 1024;//程序员自定义
	memcpy(p->mtext,buf,strlen(buf)+1);
	int r = msgsnd(msgid,(const void *)p, strlen(buf)+1, 0);
	if(-1 == r)
	{
		perror("msgsnd error");
		return -1;
	}
	
	//删除
	free(p);
	return 0;
}








