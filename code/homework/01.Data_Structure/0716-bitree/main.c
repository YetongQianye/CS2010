#include<stdio.h>
#include"BiTree.h"

int main()
{
	char buf[128] = {0};
	scanf("%s",buf);
	BiTNode *t = create_tree_by_str(buf);
	printf("先序遍历:");
 
	printf("\n");

#if 0
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
 
	
	return 0;
}


















