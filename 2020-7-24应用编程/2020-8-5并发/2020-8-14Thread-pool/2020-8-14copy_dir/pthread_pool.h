#ifndef __PTHREAD_POOL_H__
#define __PTHREAD_POOL_H__

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include <pthread.h>

#define MAX_ACTIVE_THREADS 256
#define MAX_WAITING_TASKS 1024
//任务结点,可以完整的描述一个任务就可以
struct task
{
	//数据域“函数指针+函数的参数”
	void *(*do_task)(void *arg);//函数指针,指向要完成的任务函数(copyfile)
	void *arg;//任务函数的参数
	//指针域
	struct task *next;//指向下一个任务
};
//管理结构体
typedef struct pthread_pool
{
	//线程互斥锁,保护“任务队列”,避免竞争
	pthread_mutex_t mutex;	
	//线程条件变量,表示“任务队列”是否存在任务
	pthread_cond_t cond;
	//任务队列(链表)
	//产生任务的时候,把任务加入到任务队列,
	//所有的消费者线程都需要从"任务队列"获取任务
	struct task *task_list; //指向任务队列的第一个任务
	
	bool shutdown;//表示线程池是否退出
					//flase 表示不退出
					//true 表示退出
	
	//保存线程池中所有线程的线程ID
	pthread_t *tids;
	
	//线程池中正在服役的线程数量,当前的线程数
	unsigned int active_threads;
	
	//线程池任务队列的最大任务数
	unsigned int max_waiting_task;
	
	//线程池任务队列的当前任务数
	unsigned int cur_waiting_task;
}Pthread_pool;


/*	
	init_pool:初始化一个指定的线程池,线程池中开始有thread_num个线程
	@pool:指针,执行你要初始化的线程池
	@thread_num:指定你要初始化的线程池中开始的线程数量
	返回值:
		成功返回0
		失败返回-1
*/
int init_pool(Pthread_pool *pool,unsigned int thread_num);

/*
	routine:任务分配函数,所有的“消费者”线程开始的时候都会执行这个函数,
			次函数会不断的从“线程池”的任务队列中取下任务结点,去执行取下的任务
			任务结点中包含了任务的“函数指针”和“参数”
	arg:表示你的线程池
				
*/
void *routine(void *arg);

//线程清理函数,当线程死亡时,先执行此清理函数
void handler(void *arg);


/*
add_task:往线程池中添加任务,把指定的任务(函数)和任务参数(函数参数)保存到一个任务结点中,添加到pool指向的线程池的任务队列中
@pool:你要把任务添加到哪一个线程池
@do_task:函数指针,指向你要添加的任务函数
@arg:函数的参数
返回值:
	成功返回0
	失败返回-1
*/
int add_task(Pthread_pool *pool,void *(*do_task)(void *arg),void *arg);

/*
destory_pool:销毁一个线程池
			销毁前要保证所有的任务都已经完成
			相当于把这个函数做成一个阻塞的函数
@pool:你要销毁的线程池					
*/
int destory_pool(Pthread_pool *pool);

//往线程池中增加活动线程
int add_threads(Pthread_pool *pool,unsigned int add_num);

//减少线程池中活动线程
int remove_threads(Pthread_pool *pool,unsigned int remove_num); 

#endif