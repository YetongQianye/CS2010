#ifndef __MYSEM_COM_H__
#define __MYSEM_COM_H__
//假设信号量集中只有一个信号量

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

int Mysem_get(int proj_id);//创建或者打开一个system V信号量
int Mysem_Init(int semid,int val);//初始化一个信号量
int Mysem_P(int semid);
int Mysem_V(int semid);
void Mysem_Del(int semid);






#endif



