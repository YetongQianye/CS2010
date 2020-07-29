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
/*
	char *s = "123456";
	size_t r = fwrite(s,1,6,fp);
	printf("r = %lu\n",r);
*/	
/*
	int buf[10] = {65,66,67,68,69,70,71,72,73,74};
	size_t r = fwrite(buf,4,10,fp);
	printf("r = %lu\n",r);
*/
	int buf[10] = {0};
	size_t r = fread(buf,4,10,fp);
	printf("r = %lu\n",r);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",buf[i]);
	}
	printf("\n");
	//关闭文件流
	fclose(fp);
	return 0;
}
