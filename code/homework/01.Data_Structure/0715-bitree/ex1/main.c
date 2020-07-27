#include<stdio.h>
#include"BiTree.h"

int main()
{
    char buf[128] = {0};
	scanf("%s",buf);
	BiTNode *t = create_tree_by_str(buf);
	printf("BiTree:");
    printf("%c",t->data);

}