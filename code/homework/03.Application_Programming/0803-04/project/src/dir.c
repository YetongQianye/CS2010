#include "dir.h"

//把目录下面所有的图片文件路径名以链表保存起来

LinkedList *fun_dir_bmp(const char *pathname,LinkedList *head)
{
	//打开目录	
	DIR *dir = opendir(pathname);
	if(dir == NULL)
	{
		perror("opendir error");
		return;
	}
	//读目录项
	struct dirent *dirp = NULL;
	//readdir  返回目录项数组中的一个目录项指针
	while(dirp = readdir(dir))
	{
		//解析dirp指向的目录项
		//1.排除 .和 ..
		if(!strcmp(dirp->d_name,".") || !strcmp(dirp->d_name,"..") )
			continue;
		//2.判断是 目录还是普通文件
		
		char filename[512];//表示正确的相对路径
		sprintf(filename,"%s/%s",pathname,dirp->d_name);
		struct stat st;
		//获取指定文件的属性
		
		stat(filename,&st);
		if(S_ISDIR(st.st_mode))
		{
			head = fun_dir_bmp(filename,head);
			
		}else if(S_ISREG(st.st_mode))
		{
			if(isBMP(filename) || isJPG(filename))
			{
				//printf("%s\n",filename);
				head = insert_node(head,filename);
			}
		}
	}

	//关闭目录
	closedir(dir);
	return head;
}
//判断一个文件是否为BMP图片
//如果是 返回 1，否则 返回0
int isBMP(char *filename)
{
	int x = strlen(filename);
	char s[512] = {0};
	strcpy(s,(filename+x-4));
	x = strcmp(".bmp",s);
	if(x == 0)
	{
		return 1;
	}else
	{
		return 0;
	}
	
}
//判断一个文件是否为JPG图片
//如果是 返回 1，否则 返回0
int isJPG(char *filename)
{
	int x = strlen(filename);
	char s[512] = {0};
	strcpy(s,(filename+x-4));
	x = strcmp(".jpg",s);
	int y = strcmp("jpeg",s);
	if(x == 0 || y == 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}



