#ifndef __TOUCH__H__
#define __TOUCH__H__

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>

//滑动方向
enum drec
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NOT
};

//获取手指滑动方向
enum drec get_touch();

#endif