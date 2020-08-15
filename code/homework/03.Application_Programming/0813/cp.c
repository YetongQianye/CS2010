#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>

//线程函数
void *func(void *arg)
{	
 
	pthread_t tid = pthread_self();
	int *p = (int *)malloc(sizeof(int));
	*p = 250;
	while(1)
	{
		printf("tid = %lu\n",tid);
		sleep(2);
		pthread_exit((void *)p);
	}
}

//copy函数
void my_cp(int argc,char *argv[])
{
	//打开文件
	int fd1 = open(argv[1],O_RDONLY); //源文件
	int fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0664); //目标文件
	if(fd1 == -1 || fd2 == -1) //如果出错
	{
		perror("open error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");
	//把fd1中的数据读取出来,放到fd2中去
	char buf[1024];
	while(1)
	{
		long x = read(fd1,buf,1024);
		if(x == 0)
		{
			break;
		}else if(x == -1)
		{
			perror("read error");
		}
		write(fd2,buf, x);
	}

	//关闭文件
	close(fd1);
	close(fd2);

}

//开线程
void cp_dir(char *src,char *dest)
{
    //打开一个目录 
	DIR *dp = opendir(src);
	if(NULL == dp)
	{
		printf("%s ",src);
		perror("opendir error");
		return;
	}
	//读取打开的目录的目录项,分情况讨论
	struct dirent *dirp;
    while(dirp = readdir(dp))
    {
        //如果读取到子目录
		struct stat st;
		stat(src, &st);
		if(S_ISDIR(st.st_mode))
		{
			cp_dir();
			
		}else if(S_ISREG(st.st_mode))
		{
			/* pthread_t tid;
			int r = pthread_create(&tid,NULL,func, NULL);
			if(r == -1)
			{
				perror("pthread_create error");
				return -1;
			}
			
			pthread_join(tid,NULL); */
			my_cp();

		}        
        
    }
}

int main(int argc,char *argv[])
{
	if(argc !=3)
	{
		printf("arg num not right\n");
		return -1;
	}
	cp_dir(argv[1],argv[2]);

	
	return 0;
}