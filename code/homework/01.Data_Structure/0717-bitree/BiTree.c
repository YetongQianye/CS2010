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
		pi->data = *str; //===>*str;str++
		printf("str = %c\n",*str);
		str++;
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
					//free(pi);
					break;
				}
			}
			//p肯定为NULL,pr指向路径上面最后一个结点
			//pi放到p的位置
			if(p)
			{
				free(pi);
			}else if(pi->data > pr->data)
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
				//free(pi);
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
		}else
		{
			free(pi);
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


//求二叉树的高度
int hight_tree(BiTNode *t)
{
	if(t == NULL)
	{
		return 0;
	}
	int l = hight_tree(t->lchild);
	int r = hight_tree(t->rchild);
	return (l>r?l:r)+1;
}


/*
delete_x:在t指向的二叉树中删除一个元素x
返回值:返回删除后的二叉树的根节点指针
*/
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


/*
(1) 设计算法，判断一棵二叉树是否为二叉排序树
	max_lchild：用来返回左孩子一边最大的数
	min_rchild：用来返回右孩子一边最小的数
	@n：根或叶
*/



int Binary_Sort_Tree(BiTNode *n)
{
	int max,min;
	if(n == NULL)
	{
		return 0;
	}
	Binary_Sort_Tree(n->lchild);
	Binary_Sort_Tree(n->rchild);
	max = max_lchild(n->lchild);
	min = min_rchild(n->rchild);
	if(n->data < max || n->data >min)
	{
		return 0;
	}
	return 1;
}

int max_lchild(BiTNode *n)
{
	if(n == NULL)
	{
		return 0;
	}
	while(n->rchild)
	{
		n = n->rchild;
	}
	return n->data;
}

int min_rchild(BiTNode *n)
{
	if(n == NULL)
	{
		return 0;
	}
	while(n->lchild)
	{
		n = n->lchild;
	}
	return n->data;
}




/* (2) 设计算法，判断一棵二叉树是否为平衡二叉树 	success! */
//二叉树的高度(比较左右子树那个高，高的加1既为二叉树的高度)
int BinaryTreeHigh(BiTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ret1 = BinaryTreeHigh(root->lchild);
    int ret2 = BinaryTreeHigh(root->rchild);
    //二叉树的高度为左子树和右子树中高的那个高度加1
    return ret1 > ret2 ? ret1 + 1 : ret2 + 1;
}
 
int IsBalancedTree_1(BiTNode* root)
{
    //空树是平衡二叉树
    //平衡二叉树是指以当前结点为根的左右子树高度不得超过1
    if (root == NULL)
	{
        return 1;
	}
    int right = BinaryTreeHigh(root->lchild);	 //右子树深度
    int left = BinaryTreeHigh(root->rchild);	 //左子树深度
    int gap = right - left;
    //深度超过1不是
    if (gap > 1 || gap < -1)	
    {
		  return 0;
	}
    //递归判断子树
    return IsBalancedTree_1(root->lchild) && IsBalancedTree_1(root->rchild);
}

#if 0
//判断树是否为平衡二叉树(1:是 0:不是)
//优化版本(不用遍历重复的结点)
int IsBalancedTree_2(BiTNode* root, int *depth)
{
    if (root == NULL)
    {
        *depth = 0;
        return 1;
    }
    //按照后序遍历去判断,先判断左右子树，然后记录以当前结点为根树的深度
    int left, right;
    if (IsBalancedTree_2(root->lchild, &left) && IsBalancedTree_2(root->rchild, &right))
    {
        int gap = right - left;
        if (gap <= 1 && gap >= -1)
        {
            *depth = left>right ? left + 1 : right + 1;
            return 1;
        }
    }
    return 0;
}

#endif

#if 0
int Balance_Binary_Tree(BiTNode *n)
{
	if(n == NULL)
	{
		return 0;
	}
	int a = Balance_Binary_Tree(n->lchild);
	int b = Balance_Binary_Tree(n->rchild);
	if(abs(a-b) >= 2)
	{
		return 0;
	}
	return (a > b ? a : b)+1;
	
}
#endif

/*
(3) 判断一棵二叉树是否为完全二叉树	 fault!!!

	利用队列对二叉树进行层次遍历，结点有左孩子时，
	再判断右孩子，若出现NULL，则计数i加一，若后面还有根或叶，
	则不为满二叉树	
*/

int Complete_Binary_Tree(BiTNode *t)
{
	if(t == NULL)
	{
		return 0;
	}
	int i=0;
	ElemType e;//
	BiTNode *o;//用来遍历查找的指针
	SqQueue *s = InitQueue(1024);
	EnQueue(s,t->data);
	while(s->avail_len)
	{
		DeQueue(s,&e);
		o = t;
		while(o)
		{
			if(o->data < e)
			{
				o = o->rchild;
			}
			else if(o->data > e)
			{
				o = o->lchild;
			}
			else
			{
				break;
			}
		}
		if(o->lchild && i == 0)
		{
			EnQueue(s,o->lchild->data);
			
			if(o->rchild)
			{	
				EnQueue(s,o->rchild->data);
			}
			else
			{
				i++;
			}
		}
		else if(i == 0)
		{
			if(o->rchild)
			{
				return 0;
			}
		}
		else
		{
			if(o->lchild || o->rchild)
			{
				return 0;
			}
		}
	}
	return 1;
}


/* (4) 设计算法，判断一棵二叉树是否为满二叉树	success! */

int Full_Binary_Tree(BiTNode *n)
{
	if(n == NULL)
	{
		return 0;
	}
	int a = Full_Binary_Tree(n->lchild);
	int b = Full_Binary_Tree(n->rchild);
	if(a-b != 0)
	{
		return 0;
	}
	return 1;
}

