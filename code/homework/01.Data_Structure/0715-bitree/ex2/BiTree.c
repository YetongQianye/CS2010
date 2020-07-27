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
BiTNode *insert_node_to_tree(BiTNode *t,ElemType e)
{
	//创建结点保存e的值

	//把结点插入t表示的二叉树
		//找插入位置
		//插入操作
}

#if 0
//先序遍历二叉树
void pre_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	printf("%c",t->data);
	pre_order(t->lchild);
	pre_order(t->rchild);
}
#endif

//中序遍历二叉树
void mid_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	mid_order(t->lchild);
	printf("%c",t->data);
	mid_order(t->rchild);
}

//后序遍历二叉树
void last_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	
	last_order(t->lchild);
	last_order(t->rchild);
	printf("%c",t->data);
}



