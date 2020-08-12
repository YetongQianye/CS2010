#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "dir.h"


//�����˳���־��1��ʾ�˳���0��ʾ���˳�
int terminate = 0;

//mpalyer�����˳���־��1��ʾ�Ѿ��˳���0��ʾû���˳�
int mplayer_exited = 0;

pid_t  mplayer_pid;

void sig_handler(int sig)
{
	switch(sig)
	{
		case SIGINT:
		case SIGTERM:
			terminate = 1;
			kill(mplayer_pid, SIGINT); //��mplayer������̷�һ��SIGINT���źţ�Ҳ�����˳�
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
		read(STDIN_FILENO,&ch, 1); // ��취����STDIN_FILENO => ��������ʽ��
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
	
	
	//step 1: ����һ��������һ��Ŀ¼��������Ҫ���ŵ� Ӱ�� �ļ�
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
