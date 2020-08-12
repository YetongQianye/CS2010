#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include"mysem_com.h"

#include <fcntl.h>            
#include <sys/stat.h>         
#include <semaphore.h>

#define PATHNAME "/home/oliver"
#define PROJ_ID 250

int main()
{
	//申请一个key
	key_t key = ftok(PATHNAME,PROJ_ID);
	if(key == -1)
	{
		perror("ftok error");
		return -1;
	}
	
	//申请一个IPC对象
	int shmid =  shmget(key,1024,IPC_CREAT | 0664);
	if(shmid == -1)
	{
		perror("shmget error");
		return -1;
	}
	//初始化共享内存区域的前面四个字节
	int *p = (int *)shmat(shmid,NULL,0);
    if(NULL == p)
	{
		perror("shmat error");
		return -1;
	}
	*p = 0;
	//shmdt(p);
	//创建一个信号量
	 
	//初始化信号量(永远只会被初始化一次)
    sem_t *sp = sem_open("sem.test",O_CREAT,0664,1);
	pid_t pid = fork();
	if(pid >0)//父进程
	{	
		int i = 1000000;
		//LOCK
		sem_wait(sp);
		while(i--)
		{
			(*p)++; //临界区
		}
		//UNLOCK
		sem_post(sp);
		wait(NULL);
		printf("father value:%d\n",*p);
		shmdt(p);
		shmctl(shmid,IPC_RMID,NULL);
		sem_close(sp);
        sem_unlink("/sem.test");
	}else if(pid == 0)//子进程
	{	
		int i = 1000000;
		//LOCK
		sem_wait(sp);
		while(i--)
		{
			(*p)++; //临界区
		}
		//UNLOCK
		sem_post(sp);
		printf("child value:%d\n",*p);
		shmdt(p);
	}else 
	{
		perror("fork error");
		return -1;
	}
	return 0;
}





