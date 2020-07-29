//1.打印一个目录下面所有的文件的绝对路径名(目录下面还可能有目录)
#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("bro,arg num error\n");
		return -1;
	}
	//打开一个目录,dp指向打开的目录
	DIR *dp = opendir(argv[1]);
	if(dp == NULL)
	{
		perror("opendir error");
		return -1;
	}
	//读目录中的目录项
	
	struct dirent *dirp = NULL;//指向目录项的指针
	while(dirp = readdir(dp)) //赋值表达式
	{
		//解析读取到的目录项
		printf("inode:%lu ",dirp->d_ino);
		printf("%s\n",dirp->d_name);
		//1.chdir(argv[1])
		//2.把文件的绝对路径弄出来

		char filename[512] = {0};
		sprintf(filename,"%s/%s",argv[1],dirp->d_name);
		printf("filename:%s\n",filename);
		struct stat st;
		int r = stat(filename,&st); //??????
		if(r == -1)
		{
			perror("stat error");
		}
	}

	//关闭目录
	closedir(dp);
	return 0;
}
