#include<stdio.h>
#include"BiTree.h"

int main()
{
	char buf[128] = {0};
	scanf("%s",buf);
	BiTNode *t = create_tree_by_str(buf);
#if 0
	printf("先序遍历:");
	pre_order(t);
	printf("\n");

	printf("中序遍历:");
	mid_order(t);
	printf("\n");

	printf("后序遍历:");
	last_order(t);
	printf("\n");

	printf("层次遍历:");
	level_order(t);
	printf("\n");

	//printf("高度:%d\n",hight_tree(t));
	getchar();
	char x;
	scanf("%c",&x); 
	t = delete_x(t,x);
	
	printf("先序遍历:");
	pre_order(t);
	printf("\n");

	printf("中序遍历:");
	mid_order(t);
	printf("\n");

	printf("后序遍历:");
	last_order(t);
	printf("\n");

	printf("层次遍历:");
	level_order(t);
	printf("\n");

#endif	
	
	/* if (Binary_Sort_Tree(t))
	{
		printf("是二叉排序树\n");
	}
	else
	{
		printf("不是二叉排序树\n");
	} */
 
 	/* if (IsBalancedTree_1(t) )
	{
		printf("为平衡二叉树\n");
	}
	else
	{
		printf("不为平衡二叉树\n");
	} */

	if (Complete_Binary_Tree(t) )
	{
		printf("为完全二叉树\n");
	}
	else
	{
		printf("不是完全二叉树\n");
	}
	/* if (Full_Binary_Tree(t) )
	{
		printf("为满二叉树\n");
	}
	else
	{
		printf("不是满二叉树\n");
	} */
	return 0;
}

















