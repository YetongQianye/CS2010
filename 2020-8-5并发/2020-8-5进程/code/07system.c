#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
 #include <sys/wait.h>

int main()
{
	printf("hello\n");
	//system("ls -l");
	//printf("world\n");
	
	system("./sum 123 456"); //创建一个子进程去指向指定的命令
							//等待子进程结束
	printf("world\n");
	
	return 0;
}


