#include"LinkedList.h"


/*
create_list:创建一个带头节点单链表(只需要开辟一个头结点并且初始化即可)
返回值:
	成功返回创建的带头节点单链表的头结点指针
	失败返回NULL
*/
Head *create_list()
{
	//头结点就表示一个链表
	Head *h = (Head *)malloc(sizeof(Head));
	h->first = h->last = NULL;
	h->num = 0; //暂时还没有数据结点
	
	return h;
}


/*
insert_element:往带头节点单链表中插入一个元素(实现头插法,尾插法,建立有序链表)
@x:你要插入的元素
@h:你要增加元素的链表的头结点地址
返回值:
	无
*/
void insert_element(ElemType x,Head *h)
{
	//为x分配一个结点空间且初始化
	Node *p = (Node *)malloc(sizeof(*p));
	p->next = NULL;
	p->data = x;

	//把p表示的结点加入链表h
	if(h->first == NULL)
	{
		//链表中没有数据结点
		h->first = h->last = p;
	}else
	{
		//头插法
		//p->next = h->first;
		//h->first = p;
		
		//尾插法
		h->last->next = p;
		h->last = p;
#if 0
		//建立有序链表
		//找插入位置
		Node *pk = h->first;//指向链表中第一个比p大的结点
		Node *pr = h->first;//指向pk的前一个结点
		while(pk)
		{
			if(pk->data > p->data)
			{
				break;
			}
			pr = pk;
			pk = pk->next;
		}
		//分情况插入,分三种情况,头插，尾插，中间
		if(pk == h->first)
		{
			p->next = h->first;
			h->first = p;
		}else if(pk == NULL)
		{
			h->last->next = p;
			h->last = p;
		}else
		{
			pr->next = p;
			p->next = pk;
		}
#endif		
	}
	h->num++;
}



//打印指定的链表
void print_list(Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		printf("no data node\n");
		return ;
	}
	printf("elem num:%d,data node:",h->num);
	Node *p = h->first;
	while(p)
	{
		printf("%d ",p->data); 
		p = p->next;
	}
	printf("\n");
}

//查找元素值为x的结点
Node *find_x(ElemType x,Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		return NULL;
	}	
	Node *p = h->first;
	while(p)
	{
		if(p->data == x)
		{
			break;
		}
		p = p->next;
	}
	return p;
}

//删除元素值为x的结点
void delete_x(ElemType x,Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		return ;
	}
	Node *px = NULL; //指向要删除的结点
	Node *pr = NULL; //指向要删除的结点的前一个结点
	
	//先找到要删除的结点
	px = h->first;
	while(px)
	{
		if(px->data == x)
		{
			break;
		}
		pr = px;
		px = px->next;
	}
	//分情况删除
	if(px == NULL) //没找到
	{
		return;
	}

	//删除分三种情况
	//第一个结点 px == h->first
	//最后一个结点 px == h->last
	//删除中间
	if(px == h->first)
	{
		h->first = px->next;
		if(h->first == NULL) //只有一个数据结点
		{
			h->last = NULL;
		}
	}else if(px == h->last)
	{
		pr->next = NULL;
		h->last = pr;
	}else
	{
		pr->next = px->next;
	}
	px->next = NULL;
	h->num --;
	free(px);
}
//删除所有元素值为x的结点
void delete_all_x(ElemType x,Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		return;
	}
	Node *px = NULL; //指向要删除的结点
	Node *pr = NULL; //指向要删除的结点的前一个结点
	Node *p = h->first;
	while(1)
	{
		//先找到要删除的结点
		px = p;
		while(px)
		{
			if(px->data == x)
			{
				p = px->next;
				break;
			}
			pr = px;
			px = px->next;
		}
		//分情况删除
		if(px == NULL) //没找到
		{
			return;
		}

		//删除分三种情况
		//第一个结点 px == h->first
		//最后一个结点 px == h->last
		//删除中间
		if(px == h->first)
		{
			h->first = px->next;
			if(h->first == NULL) //只有一个数据结点
			{
				h->last = NULL;
			}
		}else if(px == h->last)
		{
			pr->next = NULL;
			h->last = pr;
		}else
		{
			pr->next = px->next;
		}
		px->next = NULL;
		h->num --;
		free(px);
	}
}


//清空链表(释放所有数据结点)
void clear_list(Head *h)
{
	if(h == NULL || h->num == 0)
	{
		//链表不存在或者没有数据结点
		return ;
	}
	//删除所有的数据结点
	Node *p = h->first;
	while(p)
	{
		h->first = p->next;
		p->next = NULL;
		free(p);
		p = h->first;
	}

	h->first = h->last = NULL;
	h->num = 0;
	return ;
	
}
//删除链表(先释放所有数据结点,再释放头结点)
void delete_list(Head *h)
{
	clear_list(h);
	free(h);
}


/*
归并两个有序链表(利用原有空间),并且使归并后的链表任然有序
		la:1 3 5 7 9
		lb:1 2 3 4 5 6 7 8 9 
		结果链表:1 1 2 3 3 4 5 5 6 7 7 8 9 9

思路1:
	以其中一个链表为基准,把另一个链表的所有结点取下来,插入到第一个链表中
思路2:
	把两个链表连起来
	遍历一次链表,把所有的结点的值保存到数组中
	排序后再依次赋值

思路3:
	把两个链表连起来
	利用冒泡排序排一次序

思路4:
	取原两链表中的最小结点(哪一个结点小,就把哪一个结点取下来)
	把取下来的结点按照“尾插法”加入新的链表(单链表)
	使用原来的头结点(la)来管理次单链表
*/
Head *Merge(Head *la,Head *lb)
{
	if(la == NULL || la->first == NULL)
	{
		return lb;
	}
	if(lb == NULL || lb->first == NULL)
	{
		return la;
	}

	//指向b链表中取出的结点
	Node *p = NULL;
	
	p = lb->first;
	Node *pk = la->first; //指向la链表中第一个大于待插入结点(p)的结点
	Node *pr = NULL;
	
	while(p)
	{
		//取下第一个结点
		lb->first = p->next;
		lb->num--;
		p->next = NULL;

		//把p指向的结点加入a链表
		//找插入位置
		while(pk)
		{
			if(pk->data > p->data)
			{
				//找到了
				break; //跳出循环,pk刚好就新指向la链表中第一个大于待插入结点(p)的结点
			}
			//pr永远指向pk前面那一个结点
			pr = pk;
			pk = pk->next;
		}
		//pk指向第一个大于p的结点
		
		//分情况加入
		if(pk == la->first) //la中第一个数据结点就比p大“头插法”
		{
			p->next = la->first;
			la->first = p;
		}else if(pk == NULL)//p的值比la中所有结点都大 “尾插法”
		{
			la->last->next = p;
			la->last = p;
		}else
		{
			pr->next = p;
			p->next = pk;
			//更新pr的指向
			pr = p;
		}
		la->num++;
		//继续取lb中的第一个结点
		p = lb->first;
	}
	return la;
}


Head *Merge2(Head *la,Head *lb)
{
	if(la == NULL || la->first == NULL)
	{
		return lb;
	}
	if(lb == NULL || lb->first == NULL)
	{
		return la;
	}
	//把lb的所有数据结点都加入到了la中
	la->last->next = lb->first;
	la->last = lb->last;
	la->num += lb->num;

	//冒泡排序
	//每一趟找出一个最值,n个元素需要n-1趟
	//每一趟中,相邻的数两两比较，交换位置,每一趟比较中需要多少次比较
	//n个元素,第一趟需要n-1次比较,随着趟数的增加,比较次数可以减少
	int i,j,k;
	Node *p;
	Node *q;
	
	for(i=0;i<la->num-1;i++)//n个元素需要n-1趟
	{
		for(j=0;j<la->num-1-i;j++)
		{
			k = j;
			p = la->first;
			//找到第j个元素
			while(j--)
			{
				p = p->next;
			}
			q = p->next;
			if(p->data > q->data)
			{
				ElemType tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}	
		}
	}
	return la;
}


Head *Merge3(Head *la,Head *lb)
{
	if(la == NULL || la->first == NULL)
	{
		return lb;
	}
	if(lb == NULL || lb->first == NULL)
	{
		return la;
	}
	//指向新的单链表的头和尾
	Node *first = NULL;
	Node *last = NULL;
	//指向取下来的最小结点
	Node *p = NULL;
	//循环的取下原来两个链表中的最小结点且加入新链表
	while(la->first && lb->first)
	{
		//取原来两个链表中的最小结点
		if(la->first->data < lb->first->data)
		{
			p = la->first;
			la->first = p->next;
			p->next = NULL;
		}else
		{
			p = lb->first;
			lb->first = p->next;
			p->next = NULL;
		}
		
		//尾插法加入first表示的单链表
		if(first == NULL)
		{
			first = last = p;
		}else
		{
			last->next = p;
			last = p;
		}
	}
	//肯定有一个先结束,直接把剩下的链表加入到单链表
	//last->next = la->first?la->first:lb->first;
	
	if(la->first == NULL)
	{
		last->next = lb->first;
		last = lb->last;
	}else
	{
		last->next = la->first;
		last = la->last;
	}
	
	//把单链表找一个头结点来管理
	la->first = first;
	la->last = last;
	la->num += lb->num;
	return la;
}


/*
无序链表head有正有负,写一个函数,把负数放到正数前面,原有顺序保持不变
	如:
	head: 1 -4 -7 2 5 -8  6
	处理后的链表:-4 -7 -8 1 2 5 6
	
思路1:
	把所有负数依次取出来,按照尾插法建立一个新链表
	把负数链表加入到原链表	
思路2:
	建立两个单链表,一个保存正数,一个保存负数
	依次把原链表的结点取出来,分情况按照尾插法加入两个链表
	把两个链表都交给头结点管理
思路3:
	把数值放到两个数组中
	再依次赋值
	
*/
void change_list(Head *h)
{
	if(h == NULL || h->first ==NULL)
	{
		return;
	}
	//保存新的负数链表
	Node *first = NULL;
	Node *last = NULL;
	
	Node *pk = NULL;//指向取出来的负数结点	
	Node *pr = NULL;//指向需要取出来的前一个
	Node *p = h->first; //遍历使用的指针
	while(p)
	{
		
		if(p->data < 0) //操作完后,pr还是p的前一个
		{	
			pk = p;
			p = p->next;
			
			//分情况把pk取出来
			if(pk == h->first)
			{
				h->first = pk->next;
				pk->next = NULL;
			}else if(pk == h->last)
			{
				h->last = pr;
				pr->next = NULL;
			}else
			{
				pr->next = pk->next;
				pk->next = NULL;
			}
			//把取出来的结点按照尾插法加入新链表
			if(first == NULL)
			{
				first = last = pk;
			}else
			{	
				last->next = pk;
				last = pk;
			}
		}
		else
		{
			pr = p;
			p = p->next;
		}
	}
	
	if(last != NULL)
	{
		last->next = h->first;
		h->first = first;
	}
}

/*
有两个链表la,lb,写一个函数,判断la是否为lb的子序列
		如果是子序列返回1,否则返回0
		la:4 5 7
		lb:1 4 5 7 2 9
		la是lb的子序列
思路:
	先在lb中找到一个和la第一个结点相同的结点
	然后再依次比较后面的结点,如果都相同(la结束),则B完整的包含A
*/
int La_is_son_of_lb(Head *la,Head *lb)
{
	if(la == NULL || la->first == NULL)
	{
		return 1;
	}
	if(lb == NULL || lb->first == NULL)
	{
		return 0;
	}
	Node *pa = la->first; //la链表的第一个数据结点
	Node *pb = lb->first;
	Node *pf = lb->first;

	while(pb)
	{
		//尝试找第一个相同的结点
		if(pb->data != pa->data)
		{
			pb = pb->next;
			continue;
		}
		//记录pb的下一个位置,作为下一次开始查找的位置
		pf = pb->next;
		//pb指向的结点的值和pa指向的结点的值相等
		//pb指向的位置,可能存在子序列,验证(一起往后比较)
		while(pa && pb)
		{
			if(pa->data != pb->data)
			{
				break;
			}
			pa = pa->next;
			pb = pb->next;
		}
		if(pa == NULL)
		{
			return 1;//有子序列
		}else if(pb == NULL)
		{
			return 0;//肯定没有子序列
		}

		//因为break而退出前面的循环，寻找下一个可能存在子序列的位置
		pa = la->first;
		pb = pf;
	}
}


/*
返回一个链表中,倒数第k个结点的指针
思路1:
	倒数第k个
	就是顺数的num-k+1个

思路2：
	遍历一次链表,把每一个结点的指针保存到一个数组中(指针数组)
	return a[h->num-k];
思路3: 哨兵
	两个哨兵(指针)
	先让a走k步,然后a和b一起走,直到a为NULL
	b就是指向倒数第k个
*/
Node *reverse_K(Head *h,int k)
{
	if( k > h->num || k<=0)
	{
		return NULL;
	}
	Node *p = h->first;
	int i=0;
	while(i < h->num-k+1)
	{
		p = p->next;
		i++;
	}
	return p;

}


/*
有一个链表La,判断la中是否存在环？
	环:最后一个数据结点的指针指向前面数据结点构成环

思路1:
	使用两个哨兵A,B,A每一次移动一个结点,B每一次移动两个结点。
	假设la有环,A和B一定会相遇。
*/
int have_loop(Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		return 0;
	}
	Node *pa = h->first;
	Node *pb = h->first;

	while(pa && pa->next)
	{
		pa = pa->next->next;
		pb = pb->next;
		if(pa == pb)
		{
			return 1; //有环
		}
	}
	return 0; 
}



/*
找一个链表的中间结点(只允许遍历一次链表)
算法1:
	拍两个哨兵A,B
	A走两步,B走一步,当A走到尾(A==NULL)的时候，B刚好就是中间

算法2:
	利用h->num
	指针向后一定(h->num)/2个结点

算法3:
	创建一个指针数组,遍历一次,把每一个结点的指针保存到指针数组中
	再返回中间的结点的指针

*/
Node *middle(Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		return NULL;
	}
	Node *pa = h->first;
	Node *pb = h->first;

	while(pa) //pa != NULL
	{
		if(pa->next)
		{
			pa = pa->next->next;
		}else
		{
			break;
		}
		
		if(pa == NULL)
		{
			break;
		}
		pb = pb->next;
	}
	return pb;

}

/*
有两个链表A,B,求A,B的交集,A,B,升序,要求C升序
不管A,B中是否存在重复元素,C中不允许存在重复元素。
如:
	la:1 2 2 3 3 4 4 4 5 6 8
	lb:2 2 2 6 6 6 7 8 8 8 9 
	lc:2 6 8 

思路:
	一个元素既存在于la,又存在于lb则这个元素是lc中的一个元素
	遍历la链表,以la当前结点为基准,到lb,lc中去寻找这个结点
	如果这个结点的值存在于lb但是不存在于lc，则这个结点加入lc

思路2:
	先把la和lb中重复的元素去掉
	在把la插入到lb中
	再把重复的元素取出来

思路3：
	同时遍历,哪一个小哪一个往后移动,相同则取值

*/		
Head *Intersection(Head *la,Head *lb)
{
	Head *lc = create_list();
	//看pa指向的结点是否存在于lb中
	Node *pa = la->first;
	Node *pb = lb->first;
	Node *pk = NULL;
	while(pa)
	{
		//看pa是否存在于lb中
		Node *p = find_x(pa->data,lb);
		Node *q = find_x(pa->data,lc);
		if(p != NULL && q == NULL)
		{
			//需要把pa指向的值加入到lc中
			pk = malloc(sizeof(*pk));
			pk->data = pa->data;
			pk->next = NULL;

			if(lc->first == NULL)
			{
				lc->first = lc->last = pk;
			}else
			{
				lc->last->next = pk;
				lc->last = pk;
			}
			lc->num++;
		}
		pa = pa->next;
	}
	return lc;
}


Head *Intersection2(Head *la,Head *lb)
{
	Head *lc = create_list();
	Node *pa = la->first;
	Node *pb = lb->first;
	Node *pk;
	while(pa && pb)
	{
		if(pa->data < pb->data)
		{
			pa = pa->next;
		}else if(pa->data > pb->data)
		{
			pb = pb->next;
		}else //相等
		{
			//把相等的值加入到lc
			pk = malloc(sizeof(*pk));
			pk->data = pa->data;
			pk->next = NULL;

			if(lc->first == NULL)
			{
				lc->first = lc->last = pk;
				lc->num++;
			}else
			{
				if(pk->data != lc->last->data)
				{
					lc->last->next = pk;
					lc->last = pk;
					lc->num++;
				}else
				{
					free(pk);
				}
			}
			
			pa = pa->next;
			pb = pb->next;
		}
	}
	return lc;
}





