#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/msg.h>

//得到的key是相同的
#define PATHNAME "/home/qianye"
#define PROJ_ID 250

struct msgbuf
{
	long mtype;
	char mtext[1024];
};

int main()
{
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

	//利用IPC对象进行进程间通信(接收)
	struct msgbuf buf;
	ssize_t size = msgrcv(msgid,&buf,sizeof(buf.mtext),0,0);
	if(size >0)
	{
		printf("type:%ld\n",buf.mtype);
		printf("data:%s\n",buf.mtext);
	}
	//删除
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}








