// 2.写出二叉树的中序遍历和后序遍历代码(可以使用递归)

#include<stdio.h>
#include"BiTree.h"

int main()
{
	char buf[128] = {0};
	printf("Please Input:");
	scanf("%s",buf);
	BiTNode *t = create_tree_by_str(buf);
	

	printf("中序遍历:");
	mid_order(t);
	printf("\n");
	
	printf("后序遍历:");
	last_order(t);

	printf("\n");
	return 0;
}


















