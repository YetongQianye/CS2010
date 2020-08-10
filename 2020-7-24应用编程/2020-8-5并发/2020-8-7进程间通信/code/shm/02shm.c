#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/shm.h>

#define PATHNAME "/home/china"
#define PROJ_ID 250

int main()
{
	//利用ftok生成一个IPC的key
	key_t key = ftok(PATHNAME,PROJ_ID);
	if(key == -1)
	{
		perror("ftok error");
		return -1;
	}
	
	//使用key申请一个IPC对象(共享内存)
	int shmid =  shmget(key,1024,IPC_CREAT | 0664);
	if(shmid == -1)
	{
		perror("shmget error");
		return -1;
	}
	//把共享内存映射到进程地址空间
    char *p = (char *)shmat(shmid,NULL,0);
    if(NULL == p)
	{
		perror("shmat error");
		return -1;
	}
	//操作共享内存区域
	printf("*p = %c\n",*p);
	printf("%s\n",p+1);
	
	//解映射
	shmdt(p);
	return 0;
}
