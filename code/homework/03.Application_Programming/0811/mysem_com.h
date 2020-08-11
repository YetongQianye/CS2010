#ifndef __MYSEM_COM_H__
#define __MYSEM_COM_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>


void Mysem_get();
void Mysem_Init(); 
void Mysem_P(); 
void Mysem_V(); 
void Mysem_Del(); 

#endif