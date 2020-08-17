#include"copyfile.h"


void copydir(Pthread_pool *pool,char *src,char *dest) 
{
	//把src和dest都变成绝对路径
	char abs_src[PATHSIZE] = {0};
	char abs_dest[PATHSIZE] = {0};
	char abs_ori[PATHSIZE] = {0};  //记录进程的工作路径
	
	getcwd(abs_ori, PATHSIZE);
	//切换工作目录
	chdir(src);
	getcwd(abs_src, PATHSIZE);
	//切换会原工作目录创建目标目录,
	chdir(abs_ori);
	mkdir(dest,0777);
	chdir(dest);
	getcwd(abs_dest, PATHSIZE);

#ifdef DEBUG
	printf("scr:%s\n",abs_src);
	printf("dest:%s\n",abs_dest);
#endif	

	//打开目录(abs_src)
	DIR *dp_src;
	dp_src = opendir(abs_src);
	if(NULL == dp_src)
	{
		printf("%s ",abs_src);
		perror("opendir error");
		return;
	}
	//读取目录项
	struct dirent *ep;
	while(ep = readdir(dp_src))
	{
		//排除.和..
		if((!strcmp(ep->d_name,"."))||(!strcmp(ep->d_name,"..")))
		{
			continue;
		}
		chdir(abs_src);//回到原目录
		struct stat st;//保存文件属性
		stat(ep->d_name, &st);
		//判断读取到的目录项是文件还是目录
		if(S_ISDIR(st.st_mode))//是目录
		{
			//进入目录目录建立文件夹(ep->d_name)
			/*
			chdir(abs_dest); 
			mkdir(ep->d_name,0777);
			chdir(ep->d_name); 

			char dirpath[PATHSIZE] = {0};
			getcwd(dirpath,PATHSIZE);
			*/
			char dirpath[PATHSIZE] = {0};
			snprintf(dirpath,PATHSIZE,"%s/%s",abs_dest,ep->d_name);
			
#ifdef DEBUG
			printf("dirpath:%s\n",dirpath);
#endif 
			chdir(abs_src);
			copydir(pool,ep->d_name, dirpath);
		}else if(S_ISREG(st.st_mode))//是文件
		{
			//int fd[2] = {0};
			int *fd = (int *)malloc(sizeof(int)*2);
			//源文件文件描述符
			fd[0] = open(ep->d_name,O_RDONLY);
			//目标文件文件描述符
			chdir(abs_dest); 
			fd[1] = open(ep->d_name,O_WRONLY | O_CREAT | O_TRUNC,0664);
			if(fd[0] == -1 || fd[1] == -1)
			{
				perror("open file error");
				return;
			}
			/*
			//创建一个线程完成复制文件的过程
			pthread_t tid;
		    pthread_create(&tid, NULL,copyfile, (void *)fd);

		    //pthread_join(tid,NULL);
		    */
		    //copyfile((void*)fd);
			add_task(pool,copyfile,(void*)fd);
		    
		}else
		{
			printf("file format not support\n");
		}
	}
}

//复制文件
void *copyfile(void *arg)
{
	//分离线程
	int *p = (int *)arg;
	char buf[BUFSIZE] = {0};
	int nread,nwrite;
	while(1)
	{
		bzero(buf,BUFSIZE);
		nread = read(p[0],buf,BUFSIZE);
		if(nread == 0)
		{
			break;
		}else if(nread == -1)
		{
			perror("read,error");
			return NULL;
		}
		char *q = buf;
		while(nread > 0)
		{
			nwrite = write(p[1],q,nread);
			nread = nread - nwrite;
			q += nwrite;
		}
	}
	close(p[0]);
	close(p[1]);
	free(p);
}










