#include<stdio.h>
#include"BiTree.h"

int main()
{
	char buf[128] = {0};
	scanf("%s",buf);
	BiTNode *t = create_tree_by_str(buf);
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
	
	
	return 0;
}


















