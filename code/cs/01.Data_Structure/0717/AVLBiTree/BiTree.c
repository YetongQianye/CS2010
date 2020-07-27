#include"BiTree.h"


//对k进行单向左旋平衡处理
//返回值:返回左旋后的树的根节点
BiTNode *SingleRotateWithLeft(BiTNode *k)
{
	BiTNode *k1 = k->rchild; //新的根节点
	k->rchild = k1->lchild;
	k1->lchild = k;

	return k1;
}


//对k进行单向右旋平衡处理
//返回值:返回右旋后的树的根节点
BiTNode *SingleRotateWithRight(BiTNode *k)
{
	BiTNode *k1 = k->lchild;
	k->lchild=k1->rchild;
	k1->rchild=k;

	return k1;
}

//对k进行双向旋转(先左后右)平衡处理
//返回值:返回旋转后的树的根节点
BiTNode *DoubleRotateWithLeftRight(BiTNode *k)
{
	k->lchild = SingleRotateWithLeft(k->lchild);
	return SingleRotateWithRight(k);
}


//对k进行双向旋转(先右后左)平衡处理
//返回值:返回旋转后的树的根节点
BiTNode *DoubleRotateWithRightLeft(BiTNode *k)
{
	k->rchild = SingleRotateWithRight(k->rchild);
	return SingleRotateWithLeft(k);
}

//把元素x插入到t表示的平衡二叉树中,使二叉树任然具有平衡性
BiTNode *insert_node_to_AVLtree(BiTNode *t,TElemType x)
{
	if(t==NULL) //把x加入一颗空树
	{
		t = malloc(sizeof(*t));
		t->data = x;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if(x>t->data) //x的值比根节点大,把x加入到t的右子树上
	{
		t->rchild = insert_node_to_AVLtree(t->rchild,x);
		//在这里考虑平衡性,是否造成了不平衡,如果造成了不平衡,怎么办?
		if(hight_tree(t->rchild)-hight_tree(t->lchild)>1) //判断是否造成了不平衡
		{
			//在t的右子树上面增加一个新结点,导致t不平衡啦
			//判断x是加入到了右子结点的右边还是右子结点的左边
			if(x>t->rchild->data) //加入到了右子结点的右边
			{
				//单向左旋
				return SingleRotateWithLeft(t);
			}else if(x<t->rchild->data)//加入到了右子结点的左边
			{
				//双向旋转(先右后左)
				return DoubleRotateWithRightLeft(t);
			}
		}
	}else if(x<t->data)//x的值比根节点小,把x加入到t的左子树上
	{
		t->lchild = insert_node_to_AVLtree(t->lchild,x);
		//在这里考虑平衡性,是否造成了不平衡,如果造成了不平衡,怎么办?
		if(hight_tree(t->lchild)-hight_tree(t->rchild)>1)	
		{
			//在t的左子树上面增加一个新结点,导致t不平衡啦
			if(x < t->lchild->data) //x就是加入了t的左子结点的左边
			{
				//单向右旋
				return SingleRotateWithRight(t);
			}else if(x > t->lchild->data)//x就是加入了t的左子结点的右边
			{
				//双向旋转(先左后右)
				return DoubleRotateWithLeftRight(t);
			}
		}
	}else
	{
		//处理相等.
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





