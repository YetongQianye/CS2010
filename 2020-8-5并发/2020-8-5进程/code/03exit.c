#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun()
{
	printf("haha\n");
	exit(123); //退出程序
	//return 0;
}


int main()
{
	printf("hello");
	//_exit(1024); //任意时刻调用exit都会退出函数
	fun();
	printf("world\n");
	return 0;
}


