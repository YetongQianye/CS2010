#include<stdio.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("bro,arg num error\n");
		return -1;
	}
	//打开一个文件流
	FILE *fp = fopen(argv[1],"r+");
	if(fp == NULL)
	{
		perror("fopen error");
		return -1;
	}

	printf("fopen success\n");
	
	//关闭文件流
	fclose(fp);
	return 0;
}




