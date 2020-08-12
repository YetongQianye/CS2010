#include"mysem_com.h"

//创建一个systemV的信号量
int Mysem_get(int proj_id)
{
	//申请一个key(共享内存)
	key_t key = ftok(PATHNAME,proj_id);
	if(key == -1)
	{
		perror("ftok error");
		return -1;
	}
	//创建一个信号量(信号量集中只有一个信号量)
	int semid = semget(key,1, IPC_CREAT | 0664);
	if(-1 == semid)
	{
		perror("semget error");
		return -1;
	}
	return semid;
}

int Mysem_Init(int semid,int val)
{
	int r = semctl(semid,0,SETVAL,val);
	if(r == -1)
	{
		perror("semctl error");
		return -1;
	}
	return r;
}

int Mysem_P(int semid)
{
	struct sembuf sops[1];//操作数组
	sops[0].sem_num = 0;//信号量集中的信号量编号
	sops[0].sem_op = -1;//P操作
	sops[0].sem_flg = SEM_UNDO;
	int r = semop(semid,sops, 1);//阻塞
	if(r == -1)
	{
		perror("semop error");
		return -1;
	}
	return r;
}
int Mysem_V(int semid)
{
	struct sembuf sops[1];//操作数组
	sops[0].sem_num = 0;//信号量集中的信号量编号
	sops[0].sem_op = 1;//V操作
	sops[0].sem_flg = SEM_UNDO;
	int r = semop(semid,sops, 1);//阻塞
	if(r == -1)
	{
		perror("semop error");
		return -1;
	}
	return r;
}
void Mysem_Del(int semid)
{
	semctl(semid,0,IPC_RMID,NULL);
}




