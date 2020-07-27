#include"BiTree.h"

/*
create_tree_by_str:根据用户输入的字符串,建立一颗二叉树
返回值:
返回建立的二叉树的根节点的指针
*/
//const:不能通过str这个指针去修改str指向的值
BiTNode *create_tree_by_str(const char *str)
{
	BiTNode *root = NULL;//创建了一颗空树
	BiTNode *pi = NULL;//指向新创建的结点
	
	while(*str) //str指向不为NULL
	{
		//把字符串中的字符拿出来
		//创建一个结点保存字符的值(用户数据)
		pi = (BiTNode *)malloc(sizeof(BiTNode));
		pi->data = *str++; //===>*str;str++
		pi->lchild = pi->rchild = NULL;

		//把创建的结点插入二叉排序树
		if(root == NULL)
		{
			root = pi;
		}else
		{
			//找插入位置(遍历root表示的二叉树,找到一个合适的位置)
			//pi成为查找路径上面最后一个结点的左子或者右子
			//pr记录查找路径上面最后一个结点的指针
			BiTNode *p = root;//遍历使用的指针
			BiTNode *pr = root;//遍历使用的指针
			while(p)
			{
				if(p->data < pi->data) //当前结点的值小于待插入结点的值(往右走)
				{
					pr = p; //记录p的父节点
					p = p->rchild;
				}
				else if(p->data > pi->data)
				{
					pr = p;
					p = p->lchild;
				}else
				{
					free(pi);
					break;
				}
			}
			//p肯定为NULL,pr指向路径上面最后一个结点
			//pi放到p的位置
			if(pi->data > pr->data)
			{
				pr->rchild = pi;
			}else if(pi->data < pr->data)
			{
				pr->lchild = pi;
			}
		}
	}
	return root;
}

//把元素e插入到t表示的二叉树中
BiTNode *insert_node_to_tree(BiTNode *t,TElemType e)
{
	BiTNode *pi = NULL;
	//创建结点保存e的值
	pi = (BiTNode *)malloc(sizeof(BiTNode));
	pi->data = e;
	pi->lchild = pi->rchild = NULL;
	//把结点插入t表示的二叉树
	//把创建的结点插入二叉排序树
	if(t == NULL)
	{
		t = pi;
	}else
	{
		//找插入位置(遍历root表示的二叉树,找到一个合适的位置)
		//pi成为查找路径上面最后一个结点的左子或者右子
		//pr记录查找路径上面最后一个结点的指针
		BiTNode *p = t;//遍历使用的指针
		BiTNode *pr = t;//遍历使用的指针
		while(p)
		{
			if(p->data < pi->data) //当前结点的值小于待插入结点的值(往右走)
			{
				pr = p; //记录p的父节点
				p = p->rchild;
			}
			else if(p->data > pi->data)
			{
				pr = p;
				p = p->lchild;
			}else
			{
				free(pi);
				break;
			}
		}
		//p肯定为NULL,pr指向路径上面最后一个结点
		//pi放到p的位置
		if(pi->data > pr->data)
		{
			pr->rchild = pi;
		}else if(pi->data < pr->data)
		{
			pr->lchild = pi;
		}
	}
	return t;
}


//先序遍历二叉树
void pre_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	printf("%c ",t->data);
	pre_order(t->lchild);
	pre_order(t->rchild);
}

//中序遍历二叉树
void mid_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	//中序遍历左子树
	mid_order(t->lchild);
	//根节点
	printf("%c ",t->data);
	//中序遍历右子树
	mid_order(t->rchild);
}

//后序遍历二叉树
void last_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	//后序遍历左子树
	last_order(t->lchild);
	//后序遍历右子树
	last_order(t->rchild);
	//根结点
	printf("%c ",t->data);
}



//层次遍历t表示的二叉树
void level_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	//利用队列
	SqQueue *s = InitQueue(4096);
	int level[4096] = {0};//记录数中每一个元素所在的层次
	//level[0]记录根节点的层次
	//约定访问一个结点后,让它入队列
	//访问根节点并且入队
	printf("%c ",t->data);
	EnQueue(s,t);	
	int j = 0; //下标,相当于按层次遍历时,每一个元素的序号
	level[j++]=1;//记录根节点的层次
	int i = 0;
	while(!QueueIsEmpty(s))//队列不为NULL
	{	
		//i表示出队元素本身的层次
		//出队列,
		BiTNode *x = NULL; //存储出队元素  NULL(0x0)
		DeQueue(s,&x);
		//在调用函数后,x就指向出队元素(保存出队指针)		
		//访问出队元素的左子结点和右子结点,访问完需要入队
		if(x->lchild)
		{
			printf("%c ",x->lchild->data);
			EnQueue(s,x->lchild);	
			level[j++] = level[i]+1;
		}
		if(x->rchild)
		{
			printf("%c ",x->rchild->data);
			EnQueue(s,x->rchild);
			level[j++] = level[i]+1;
		}
		i++; 
	}
	DestoryQueue(s);
	printf("\n");
	for(i=0;i<j;i++)
	{
		printf("%d ",level[i]);
	}
	printf("\n");
	printf("高度:%d",level[j-1]);
	
}

// 删除节点
BiTNode *delete_x(BiTNode *t,TElemType x)
{
	if(t == NULL)
	{
		return NULL;
	}
	//a.找到要删除的结点 
	BiTNode *px = t;//遍历使用的指针,最终让他指向要删除的结点
	BiTNode *pr = NULL;//指向待删除的结点的父节点
	while(px)
	{
		if(px->data < x) //待删除结点比px大,只有可能出现在px的右子树
		{
			pr = px;
			px = px->rchild;
		}else if(px->data > x)//待删除结点比px小,只有可能出现在px的左子树
		{
			pr = px;
			px = px->lchild;
		}else
		{
			break;//px指向了要删除的结点
		}
	}
	//上面的循环有两个出口(1.break 2.px==NULL)	
	if(px==NULL)
	{	
		//树中不存在元素x
		return t;
	}
	//b.分情况删除操作
	//1.px是一个叶子结点
loop:
	if(px->lchild == NULL && px->rchild == NULL)
	{
		//px有可能是根节点
		if(px == t)
		{
			t = NULL;
		}else //px不是根节点,肯定是属于pr的左子或者右子
		{
			if(px==pr->lchild)
			{
				pr->lchild = NULL;
			}else if(px==pr->rchild)
			{
				pr->rchild = NULL;
			}
		}
		free(px);
		return t;
	}
	//2.px有一个右子结点
	if(px->lchild == NULL) //肯定有一个R
	{
		//px为根节点
		if(px == t)
		{
			t = px->rchild;
			px->rchild = NULL;
		}else //px不是根节点
		{
			if(px == pr->rchild) //px是pr的右子
			{
				pr->rchild = px->rchild;
				px->rchild = NULL;
			}else if(px == pr->lchild)//px是pr的左子
			{
				pr->lchild = px->rchild;
				px->rchild = NULL;
			}
		}
		free(px);
		return t;
	}
	//3.px有一个左子结点
	if(px->rchild == NULL)//肯定有一个L
	{
		if(px==t)//px为根节点
		{
			t = px->lchild;
			px->lchild = NULL;
		}else
		{
			if(px == pr->lchild)
			{
				pr->lchild = px->lchild;
				px->lchild = NULL;
			}else if(px== pr->rchild)
			{
				pr->rchild = px->lchild;
				px->lchild = NULL;
			}
		}

		free(px);
		return t;
	}
	
	//4.px既有L又有R
	if(px->lchild != NULL && px->rchild != NULL)
	{
		//找一个“替罪羊”

		BiTNode *pf = px;//记录原来要删除的结点
		//往左边找一个最大的或者往右边找一个最小的
		pr = px;
		px = px->lchild;//往左边找最大的,左拐后,一直右拐,直到px没有右子结点
		while(px->rchild)
		{
			pr = px;
			px = px->rchild;
		}
		//px就指向“替罪羊”
		TElemType tmp = pf->data;
		pf->data = px->data;
		px->data = tmp;
		goto loop;
	}
}


	









