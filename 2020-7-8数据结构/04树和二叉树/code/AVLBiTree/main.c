#include<stdio.h>
#include"BiTree.h"

int main()
{
	char buf[128] = {0};
	scanf("%s",buf);
	BiTNode *t = NULL;
	int i = 0;
	while(buf[i])
	{
		t = insert_node_to_AVLtree(t,buf[i]);
		i++;
	}
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

	printf("高度:%d\n",hight_tree(t));
	return 0;
}


















