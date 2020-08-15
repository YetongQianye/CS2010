#include<stdio.h>
#include"copyfile.h"

//把srcdir执行的目录复制为destdir指向的目录
//./main srcdir  destdir
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("arg num not yes\n");
		return -1;
	}
	
	//判断是否为目录
	copydir(argv[1],argv[2]);
	
	
	return 0;
}



