
#include <stdio.h>
#include <stdlib.h>

#include "biTree.h"
#include "SqQueue.h"



/*
	Insert:把p指向的结点，插入root指向的二叉
		排序树，并保证它的排序性

	@root:指向一个已经存在的“二叉排序树”
	@p: 指向一个待插入结点
	返回值:
		返回插入后的“二叉排序树”的根结点
*/
biNode* Insert(biNode *root, biNode *p)
{
	if (root == NULL)
	{
		return p;
	}

	if (p == NULL)
	{
		return root;
	}


	//1. 找插入位置
	biNode *px = root;
	biNode *pf = NULL; //指向px的父结点

	while (px)
	{
		if (p->data > px->data)
		{
			pf = px;
			px = px->rchild;
		}
		else if (p->data < px->data)
		{
			pf = px;
			px = px->lchild;
		}
		else
		{
			// p->data == px->data
			free(p);
			return root;
		}
	}

	//2.插入操作
	// pf一定是指向查找路径上的最后一个结点
	if (p->data > pf->data)
	{
		pf->rchild = p;
	}
	else
	{
		pf->lchild = p;
	}
	
	return root;
}



//根据用户输入的整数，按照其数值来建立一棵
//二叉排序树

biNode* create_tree()
{
	char d;
	biNode *root = NULL;
	biNode *p = NULL;

	while (1)
	{
		scanf("%c", &d);
		if (d == '#')
		{
			break;
		}


		//创建一个结点，用来保存d
		p = malloc(sizeof(*p));
		p->data = d;
		p->lchild = p->rchild = NULL;


		//把p指向的结点，插入到root指向的二叉排序树中去
		root = Insert(root, p);
	}


	return root;
}


//先序遍历一棵二叉树t
void pre_order(biNode *r)
{
	if (r == NULL)
	{
		return ;
	}

	//(1) 先访问根结点
	printf("%c ", r->data);

	//(2) 按照同样的规则(先序)访问r的左子树
	pre_order(r->lchild);


	//(3) 按照同样的规则(先序)访问r的右子树
	pre_order(r->rchild);
	
}

//中序遍历一棵二叉树t
void mid_order(biNode *t)
{
	if (t == NULL)
	{
		return ;
	}

	//(1)
	mid_order(t->lchild);

	//(2)
	printf("%c ", t->data);

	//(3)
	mid_order(t->rchild);

}

//后序遍历一棵二叉树t
void post_order(biNode *t)
{
	if (t == NULL)
	{
		return ;
	}

	//(1)
	post_order(t->lchild);

	//(2)
	post_order(t->rchild);

	//(3)
	printf("%c ", t->data);

}



//按层次遍历t指向的那棵二叉树
void level_order(biNode *t)
{
	SqQueue *sq = alloc_SqQueue(1024);
	if (t == NULL )
	{
		return ;
	}


	//让根结点入队
	EnQueue(sq, (QElemType )t);


	//
	while (!SqQueue_is_empty(sq))
	{

		//出队
		QElemType e; //用来保存出队的元素

		
		DeQueue(sq,  &e);

		//e这个变量中，就保存了出队元素。

		// 队列元素　是结点的指针　biNode*
		// e这个变量的值就是一个二叉树结点的地址
		biNode *p = (biNode*)e;


		printf("%c ", p->data);


		if (p->lchild)
		{
			EnQueue(sq,  (QElemType)p->lchild);
		}
	
	
		if (p->rchild)
		{
			EnQueue(sq,  (QElemType)p->rchild);
		}
		

	}

	
}

/*
	delete_x:删除root指向的二叉排序树中，值为x的结点
	@root:
	@x:
	返回值:
		返回删除后的二叉排序树的根结点

*/
biNode* delete_x(biNode *root, TElemType x)
{
	if (root == NULL)
	{
		return NULL;
	}


	biNode *px = root;//px指向要删除的结点
	biNode *pf = NULL;//pf指向px的父结点
	

	//1. 先找到要删除的结点px
	while (px)
	{
		if (x > px->data)
		{	
			pf = px;
			px = px->rchild;
		}
		else if (x < px->data)
		{
			pf = px;
			px = px->lchild;
		}
		else
		{
			break;
		}
	}

	if (px == NULL)
	{
		return root;
	}

delete_px:
	//2. 删除操作，分三种情况
	if (px->lchild == NULL &&  px->rchild == NULL) //要删除的结点是叶子结点
	{
		if (px == root)
		{
			//要删除的根结点，并且整棵只有一个结点
			free(px);
			return NULL;
		}

		if (pf->lchild == px)
		{
			pf->lchild = NULL;
		}
		else
		{
			pf->rchild = NULL;
		}
		free(px);

		return root;
	}

	else if (px->lchild == NULL) // R不为空
	{
		//让px的右子结点顶上去

		if (px == root)
		{
			root = px->rchild;
			px->rchild = NULL;

			free(px);

			return root;
		}

		if (px == pf->lchild)
		{
			pf->lchild = px->rchild;
			px->rchild = NULL;

			free(px);

			return root;
		}
		else
		{
			pf->rchild = px->rchild;
			px->rchild = NULL;

			free(px);
			return root;
		}
		
	}
	else if (px->rchild == NULL) //L不为空
	{
		//同上，do it yourself ...
	}
	else
	{
		//L,R均不为空。
		biNode *ps = px;


		pf = px;
		px = px->lchild;

		while (px->rchild)
		{
			pf = px;
			px = px->rchild;
		}

		ps->data = px->data;
		
		goto delete_px;
	}
	

}



int main()
{	
	char buf[128] = {0};
	printf("Please Input:");
	scanf("%s",buf);
	biNode *r = create_tree();
	
	printf("level_order: ");
	level_order(r);

	

	printf("\n");

	return 0;
}

