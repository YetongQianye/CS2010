#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("hello"); //只打印一次
	fork();
	printf("world\n"); //打印两次
	return 0;
}

