#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

#define PATHNAME "/home/china"
#define PROJ_ID 250

#define PATHNAME1 "/home/china"
#define PROJ_ID1 128

union semun {
   int              val;    /* Value for SETVAL */
   struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
   unsigned short  *array;  /* Array for GETALL, SETALL */
   struct seminfo  *__buf;  /* Buffer for IPC_INFO
                               (Linux-specific) */
};



int main()
{
	//申请一个key(共享内存)
	key_t key = ftok(PATHNAME,PROJ_ID);
	if(key == -1)
	{
		perror("ftok error");
		return -1;
	}

	//申请一个key(信号量)
	key_t key1 = ftok(PATHNAME1,PROJ_ID1);
	if(key1 == -1)
	{
		perror("ftok error");
		return -1;
	}
	
	//申请一个IPC对象(共享内存)
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
	//创建一个信号量(信号量集中只有一个信号量)
	int semid = semget(key1,1, IPC_CREAT | 0664);
	if(-1 == semid)
	{
		perror("semget error");
		shmdt(p);
		return -1;
	}

	//初始化信号量(永远只要被初始化一次)
	/*
	//SETVAL
	union semun se;
	se.val = 1;
	int r = semctl(semid,0,SETVAL,se.val);
	//SETALL
	se.array = malloc(sizeof(short)*nsems);
	se.array[0] = 1;
	....
	int r = semctl(semid,0,SETALL,se.array);
	free(se.array);
	*/
	int r = semctl(semid,0,SETVAL,1);
	if(r == -1)
	{
		perror("semctl error");
		return -1;
	}
	int val = semctl(semid,0,GETVAL);
	printf("sem_val = %d\n",val);
	
	pid_t pid = fork();
	if(pid >0)//父进程
	{	
		int i = 1000000;
		//LOCK
		struct sembuf sops[1];//操作数组
		sops[0].sem_num = 0;//信号量集中的信号量编号
		sops[0].sem_op = -1;//P操作
		sops[0].sem_flg = SEM_UNDO;
		semop(semid,sops, 1);//阻塞
		while(i--)
		{
			(*p)++; //临界区
		}
		//UNLOCK
		sops[0].sem_num = 0;//信号量集中的信号量编号
		sops[0].sem_op = 1;//V操作
		sops[0].sem_flg = SEM_UNDO;
		semop(semid,sops, 1);//阻塞
		wait(NULL);
		printf("father value:%d\n",*p);
		//分离共享内存
		shmdt(p);
		shmctl(shmid,IPC_RMID,NULL);
		semctl(semid,0,IPC_RMID,NULL);
		
	}else if(pid == 0)//子进程
	{	
		int i = 1000000;
		//LOCK
		struct sembuf sops[1];//操作数组
		sops[0].sem_num = 0;//信号量集中的信号量编号
		sops[0].sem_op = -1;//P操作
		sops[0].sem_flg = SEM_UNDO;
		semop(semid,sops, 1);//阻塞
		while(i--)
		{
			(*p)++; //临界区
		}
		printf("child value:%d\n",*p);
		//UNLCOK
		sops[0].sem_num = 0;//信号量集中的信号量编号
		sops[0].sem_op = 1;//V操作
		sops[0].sem_flg = SEM_UNDO;
		semop(semid,sops, 1);//阻塞
		
		//分离共享内存
		shmdt(p);
	}else 
	{
		perror("fork error");
		return -1;
	}
	return 0;
}


























