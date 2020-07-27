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

#if 0
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

#endif

#if 0

/*****先序遍历*****/ 
void PreOrderTraversal(BiTNode *BT)
{ 
	BiTNode *t = BT;
	LkStack *s = InitStack();/*创建并初始化堆栈S*/ 
	while( t || !StackIsEmtpy(s) )
	{
		while(t)	/*一直向左并将沿途结点压入堆栈,直到左儿子不存在*/ 
		{  
			printf("%5d ",t->data);  /*访问（打印）结点*/
			Push(s,t);
			t = t->lchild; 
		}
		
		if( !StackIsEmtpy(s) )
		{
			t = Pop(s,t->data);   /*结点弹出堆栈*/ 
			t = t->rchild;  /*转向右子树*/ 
		}
	}
 } 
#endif

 
 
 









