#include"pthread_pool.h"

/*	
	init_pool:初始化一个指定的线程池,线程池中开始有thread_num个线程
	@pool:指针,执行你要初始化的线程池
	@thread_num:指定你要初始化的线程池中开始的线程数量
	返回值:
		成功返回0
		失败返回-1
*/
int init_pool(Pthread_pool *pool,unsigned int thread_num)
{
	//初始化线程池结构体(给结构体中的每一个成员赋值)
	//初始化线程互斥锁和条件变量
	pthread_mutex_init(&pool->mutex,NULL);
	pthread_cond_init(&pool->cond,NULL);

	pool->shutdown = false;//开机

	//pool->task_list = NULL;
	//创建一个空的任务结点
	pool->task_list = (struct task*)malloc(sizeof(struct task));
	pool->tids = (pthread_t*)malloc(sizeof(pthread_t)*MAX_ACTIVE_THREADS);
	if(pool->task_list == NULL || pool->tids == NULL)
	{
		perror("malloc error");
		return -1;
	}
	pool->task_list->next = NULL;
	pool->max_waiting_task = MAX_WAITING_TASKS;
	pool->active_threads = thread_num;
	pool->cur_waiting_task = 0;

	//循环的创建thread_num个线程,让所有的线程都去执行任务分配函数,并且记录所有的线程ID
	int i;
	for(i=0;i<thread_num;i++)
	{
		//创建线程且执行任务分配函数
		if(pthread_create(&(pool->tids)[i],NULL,routine,(void *)pool) !=0)
		{
			perror("create thread error");
			return -1;
		}

		printf("[%lu]:[%s]===>tids[%d]:[%lu] is create\n",pthread_self(),__FUNCTION__,i,pool->tids[i]);

	}
}


//线程清理函数,当线程死亡时,先执行此清理函数
void handler(void *arg)
{
	pthread_mutex_unlock((pthread_mutex_t *)arg);
}




/*
	routine:任务分配函数,所有的“消费者”线程开始的时候都会执行这个函数,
			次函数会不断的从“线程池”的任务队列中取下任务结点,去执行取下的任务
			任务结点中包含了任务的“函数指针”和“参数”
	arg:表示你的线程池
				
*/
void *routine(void *arg)
{
	//arg表示你的线程池
	Pthread_pool *pool = (Pthread_pool *)arg;

	struct task *p = NULL;//指向取出的任务结点
	//任务队列是一个共享资源
	while(1)
	{
		//注册一个线程清理函数,防止此线程被带锁取消
		pthread_cleanup_push(handler,(void *)(&pool->mutex));
		//获取线程互斥锁 LOCK
		pthread_mutex_lock(&pool->mutex);
		
		//访问arg表示的线程池,从线程池的任务链表中取下一个“结点”
		//1.没有退出 && 没有任务
		//if(!pool->shutdown && pool->cur_waiting_task == 0)
		while(!pool->shutdown && pool->cur_waiting_task == 0)
		{
			//线程休眠
			pthread_cond_wait(&pool->cond,&pool->mutex);
			//在哪里唤醒呢?添加任务时,销毁线程池时
		}
		//2.没有任务 && 线程池退出
		if(pool->shutdown == true && pool->cur_waiting_task == 0)
		{
			pthread_mutex_unlock(&pool->mutex);//防止带锁退出
			pthread_exit(NULL);//线程退出
		}
		//3.不管有没有退出只要有任务就执行任务

		p = pool->task_list->next;//第一个任务结点中没有任务
		pool->task_list->next = p->next;//取下任务结点
		pool->cur_waiting_task--;
		
		//释放线程互斥锁 UNLOCK
		pthread_mutex_unlock(&pool->mutex);
		//删除上面建立的线程清理函数
		pthread_cleanup_pop(0);
		//p就指向了取到的任务结点(copyfile)
		//执行“结点”表示的任务

		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
		(p->do_task)(p->arg); //执行指定的文件复制任务
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
		
		//释放结点
		free(p);
	}	
}

/*
add_task:往线程池中添加任务,把指定的任务(函数)和任务参数(函数参数)保存到一个任务结点中,添加到pool指向的线程池的任务队列中
@pool:你要把任务添加到哪一个线程池
@do_task:函数指针,指向你要添加的任务函数
@arg:函数的参数
返回值:
	成功返回0
	失败返回-1
*/
int add_task(Pthread_pool *pool,void *(*do_task)(void *arg),void *arg)
{
	//开辟一个任务结点
	//把第二个参数和第三个参数保存到任务结点中
	struct task *new_task = (struct task *)malloc(sizeof(struct task));
	if(new_task == NULL)
	{
		perror("malloc error");
		return -1;
	}
	//给新的任务结点赋值
	new_task->do_task = do_task;
	new_task->arg = arg;
	new_task->next = NULL;
	//加入到pool的任务队列中
	pthread_mutex_lock(&pool->mutex);
	//注意“任务队列”是一个共享资源

	//当线程池任务达到了最大值
	if(pool->cur_waiting_task >= MAX_WAITING_TASKS)
	{
		//解锁并且释放结点空间
		pthread_mutex_unlock(&pool->mutex);
		free(new_task);
		fprintf(stderr,"too many tasks\n");
		return -1;
	}

	//把结点按照尾插法加入任务队列
	struct task *tmp = pool->task_list;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;//找到最后一个结点
	}

	tmp->next= new_task;
	pool->cur_waiting_task++;

	pthread_mutex_unlock(&pool->mutex);	
	
	//加入后要唤醒等待的线程
	pthread_cond_signal(&pool->cond);
	return 0;
}


/*
destory_pool:销毁一个线程池
			销毁前要保证所有的任务都已经完成
			相当于把这个函数做成一个阻塞的函数
@pool:你要销毁的线程池					
*/
int destory_pool(Pthread_pool *pool)
{
	//等待所有任务执行完毕
	//只需要把shutdown赋值为true
	pool->shutdown = true;
	//唤醒所有线程
	pthread_cond_broadcast(&pool->cond);
	//利用join函数等待所有的线程
	int i;
	for(i=0;i<pool->active_threads;i++)
	{
		errno = pthread_join(pool->tids[i],NULL);
		if(errno != 0)
		{
			printf("join tids[%d] error:%s\n",i,strerror(errno));
		}
		printf("[%lu]:[%s]===>join tids[%d]:[%lu]\n",pthread_self(),
			__FUNCTION__,i,pool->tids[i]);
	}
	//回收所有动态分配的空间
	free(pool->task_list);
	free(pool->tids);
	return 0;
}



//往线程池中增加活动线程
//返回实际增加的线程数量
int add_threads(Pthread_pool *pool,unsigned int add_num)
{
	if(add_num == 0)
		return 0;
	
	unsigned total_threads = pool->active_threads + add_num;
	int i,actual_inc = 0;
	for(i=pool->active_threads;i<total_threads&&i<MAX_ACTIVE_THREADS;i++)
	{
		//创建线程且执行任务分配函数
		if(pthread_create(&(pool->tids)[i],NULL,routine,(void *)pool) !=0)
		{
			perror("create thread error");
			break;
		}
		actual_inc++;
		printf("[%lu]:[%s]===>tids[%d]:[%lu] is create\n",pthread_self(),__FUNCTION__,i,pool->tids[i]);
	}
	pool->active_threads += actual_inc;
	return actual_inc;
	
}

//减少线程池中活动线程
//返回减少后的剩余的线程数
int remove_threads(Pthread_pool *pool,unsigned int remove_num)
{
	if(remove_num == 0)
		return pool->active_threads;
	//目的是减少线程而不是删除线程池
	int remaining_thread = pool->active_threads - remove_num;
	//至少保留一个线程
	remaining_thread = remaining_thread >0?remaining_thread:1;
	int i;
	for(i=pool->active_threads-1;i>remaining_thread-1;i--)
	{
		errno = pthread_cancel(pool->tids[i]);
		if(errno != 0)
		{
			break;
		}
		printf("[%lu]:[%s]===>cancel tids[%d]:[%lu]\n",pthread_self(),
			__FUNCTION__,i,pool->tids[i]);
	}

	if(i == pool->active_threads -1)
	{
		return -1;//取消失败
	}else 
	{
		//删除成功,返回剩余的线程数量
		pool->active_threads = i+1;
		return i+1;
	}

}










