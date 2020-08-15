#ifndef __COPY_FILE_H__
#define __COPY_FILE_H__

#include<stdio.h>
#include<string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>

//调试总开关
#define DEBUG

#define PATHSIZE 256
#define BUFSIZE 4096

//把src指向的目录复制为dest表示的目录
//假定dest都不存在
void copydir(char *src,char *dest);

//复制文件
void *copyfile(void *arg);



#endif
