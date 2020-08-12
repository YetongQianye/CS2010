#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "dir.h"


//程序退出标志，1表示退出，0表示不退出
int terminate = 0;

//mpalyer进程退出标志，1表示已经退出，0表示没有退出
int mplayer_exited = 0;

pid_t  mplayer_pid;

void sig_handler(int sig)
{
	switch(sig)
	{
		case SIGINT:
		case SIGTERM:
			terminate = 1;
			kill(mplayer_pid, SIGINT); //给mplayer这个进程发一个SIGINT的信号，也让他退出
			break;

		case SIGCHLD:
			mplayer_exited = 1;
			break;
			
		default:
			break;
	}
}


void get_user_cmd()
{
	char ch;
	int fd = open("/tmp/test.fifo", O_WRONLY);
	if (fd == -1)
	{
		perror("open /tmp/test.fifo error");
		return ;
	}


	while (!terminate && !mplayer_exited )
	{
		//scanf("%c", &ch); // <=>  read(STDIN_FILENO, &ch, 1)
		read(STDIN_FILENO,&ch, 1); // 想办法，把STDIN_FILENO => 非阻塞方式读
		switch(ch)
		{
			case 'p':
			{
				write(fd, "pause\n", 6);

				break;
			}
			case 'k':
			{
				write(fd, "seek +3\n", 8);
				break;
			}
			default:
				break;
				
		}
	}

	close(fd);
}


int main(int argc, char *argv[])
{
	int r ;
	pid_t pid;

	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGCHLD, sig_handler);

	system("unlink /tmp/test.fifo");
	system("mkfifo  /tmp/test.fifo");
	
	
	//step 1: 创建一个链表保存一个目录下面所有要播放的 影音 文件
	struct fList *f = search_movies(argv[1]);

	struct fNode *p = f->first;

	pid = fork();
	if ( pid == 0 ) //B
	{
		get_user_cmd();
		exit(0);
	}


	while (!terminate && p &&!mplayer_exited)
	{
		pid = fork();
		if (pid > 0)
		{
			mplayer_pid = pid;
			mplayer_exited = 0;
			
			//waitpid(); //wait mplayer dead 
			
		}
		else if (pid == 0)
		{
			r = execlp("mplayer", "mplayer", " -slave",  " -input" , "file=/tmp/test.fifo",
				"-really-quiet", "-zoom", "-x", "800", "-y", "480",
				p->filename, "&", NULL);
			if (r == -1)
			{
				perror("execlp error:");
				exit(-1);
			}
		}

		p = p->next;
		if (p == NULL)
		{
			p = f->first;
		}
		
	}
	return 0;
}
