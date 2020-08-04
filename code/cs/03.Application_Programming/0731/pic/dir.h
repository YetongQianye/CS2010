#ifndef __DIR__H__
#define __DIR__H__

#include<stdio.h>
#include <sys/types.h> //for open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //for close
#include <sys/mman.h> //mmap
#include <sys/ioctl.h> //ioctl

#include <sys/types.h>
#include <dirent.h>
#include"LinkedList.h"

//把目录下面所有的图片文件路径名以链表保存起来
LinkedList *fun_dir_bmp(const char *pathname,LinkedList *head);
//判断一个文件是否为BMP图片
//如果是 返回 1，否则 返回0
int isBMP(char *filename);
//判断一个文件是否为JPG图片
//如果是 返回 1，否则 返回0
int isJPG(char *filename);

#endif