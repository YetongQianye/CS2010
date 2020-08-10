#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/shm.h>

//得到的key是相同的
#define PATHNAME "/home/qianye"
#define PROJ_ID 250

int main()
{	 
	//利用ftok生成一个“key”
	key_t key = ftok(PATHNAME,PROJ_ID);
	if(key == -1)
	{
		perror("ftok error");
		return -1;
	}
	//创建或者打开system V的共享内存 shmget
	int shmid =  shmget(key, 1024,IPC_CREAT | 0664);
	if(shmid == -1)
	{
		perror("shmget error");
		return -1;
	}

	//映射(shmat)进行进程间通信 
	char *p = (char *)shmat( shmid, NULL, 0);
	if(NULL == p)
	{
		perror("shmat error");
		return -1;
	}
	//操作
	printf("*p = %c\n",*p);
	printf("*p = %s\n",p+1);
	//解映射
	shmdt(p);
 
	 
	return 0;
}








