#include"mysem_com.h"
 
void Mysem_get()   //创建或者打开一个system V信号量
{
    
    int semid = semget(key1,1, IPC_CREAT | 0664);
	if(-1 == semid)
	{
		perror("semget error");
		shmdt(p);
		return -1;
	}
}

void Mysem_Init() //初始化一个信号量
{
   
	if(-1 == semid)
	{
		perror("semget error");
		shmdt(p);
		return -1;
	}

    int r = semctl(semid,0,SETVAL,1);
	if(r == -1)
	{
		perror("semctl error");
		return -1;
	}
	int val = semctl(semid,0,GETVAL);
	printf("sem_val = %d\n",val);
}

void Mysem_P()     //P操作
{
    
    sops[0].sem_num = 0;//信号量集中的信号量编号
    sops[0].sem_op = -1;//P操作
    sops[0].sem_flg = SEM_UNDO;
    semop(semid,sops, 1);//阻塞
    while(i--)
    {
        (*p)++; //临界区
    }
}

void Mysem_V()     //V操作
{
    sops[0].sem_num = 0;//信号量集中的信号量编号
    sops[0].sem_op = 1;//V操作
    sops[0].sem_flg = SEM_UNDO;
    semop(semid,sops, 1);//阻塞
   
}

/* void Mysem_Del();   //删除
{

} */






