#include<stdio.h>
#include"BiTree.h"



int main()
{
	char buf[128] = {0};
	scanf("%s",buf);
	BiTNode *t = create_tree_by_str(buf);
	

	printf("层次遍历:");
	level_order(t);
	printf("\n");
	
	return 0;
}


















