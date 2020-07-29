#include<stdio.h>
#include<errno.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//argc:命令行参数个数  
//argv:指针数组,每一个成员都是一个字符指针,指向参数“字符串”
//./myls 1.txt  2.txt       argc==3
//argv[0] ==>"./myls"  argv[1] ==>"1.txt"

int main(int argc,char *argv[])
{
	//struct stat *st = malloc(sizeof(*st));
	//获取文件的属性
	struct stat st;
	int r = stat(argv[1], &st);
	if(-1 == r)
	{
		perror("stat error");
		return -1;
	}
	//解析结构体
	char buf[512] = {0};
	r = 0;
	//获取文件类型
	if(S_ISREG(st.st_mode))
	{
		//格式化打印到内存地址,返回实际打印的字符个数
		r += sprintf(buf+r,"-");
	}else if(S_ISDIR(st.st_mode))
	{
		r += sprintf(buf+r,"d");
	}
	else if(S_ISCHR(st.st_mode))
	{
		r += sprintf(buf+r,"c");
	}
	else if(S_ISBLK(st.st_mode))
	{
		r += sprintf(buf+r,"b");
	}
	else if(S_ISFIFO(st.st_mode))
	{
		r += sprintf(buf+r,"p");
	}
	else if(S_ISLNK(st.st_mode))
	{
		r += sprintf(buf+r,"l");
	}
	else if(S_ISSOCK(st.st_mode))
	{
		r += sprintf(buf+r,"s");
	}

	//文件权限
	if(st.st_mode & S_IRUSR)
	{
		r += sprintf(buf+r,"r");
	}else
	{
		r += sprintf(buf+r,"-");
	}
	if(st.st_mode & S_IWUSR)
	{
		r += sprintf(buf+r,"w");
	}else
	{
		r += sprintf(buf+r,"-");
	}
	if(st.st_mode & S_IXUSR)
	{
		r += sprintf(buf+r,"x");
	}else
	{
		r += sprintf(buf+r,"-");
	}

	if(st.st_mode & S_IRGRP)
	{
		r += sprintf(buf+r,"r");
	}else
	{
		r += sprintf(buf+r,"-");
	}
	if(st.st_mode & S_IWGRP)
	{
		r += sprintf(buf+r,"w");
	}else
	{
		r += sprintf(buf+r,"-");
	}
	if(st.st_mode & S_IXGRP)
	{
		r += sprintf(buf+r,"x");
	}else
	{
		r += sprintf(buf+r,"-");
	}

	if(st.st_mode & S_IROTH)
	{
		r += sprintf(buf+r,"r");
	}else
	{
		r += sprintf(buf+r,"-");
	}
	if(st.st_mode & S_IWOTH)
	{
		r += sprintf(buf+r,"w");
	}else
	{
		r += sprintf(buf+r,"-");
	}
	if(st.st_mode & S_IXOTH)
	{
		r += sprintf(buf+r,"x");
	}else
	{
		r += sprintf(buf+r,"-");
	}

	//硬链接数量
	r += sprintf(buf+r," %lu ",st.st_nlink);
	//etc/group  //etc/passwd
	//用户名和组用户名
	r += sprintf(buf+r,"%d %d ",st.st_uid,st.st_gid);

	//文件大小
	r += sprintf(buf+r,"%lu ",st.st_size);

	//最后修改时间
	time_t tm = st.st_mtim.tv_sec;  //1970年到修改时间的秒数

	r += sprintf(buf+r,"%s",ctime(&tm));
	buf[r-1] = ' ';	
	//文件名
	r += sprintf(buf+r,"%s ",argv[1]);
	
	printf("%s\n",buf);
	return 0;
}

















