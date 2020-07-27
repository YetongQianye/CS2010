#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkList.h" //在当前路径下查找 


int main()
{
	
	//创建一个链表
	struct node *list = create_linklist();
	print_list(list);

	printf("please input a insert num\n");
	int x;
	scanf("%d",&x);
	//为x开辟一个空间
	//struct node *p = (struct node *)malloc(sizeof(*p));
	//p->data = x;
	//p->next = NULL;
	
	//list = insert_node(p,list);

	//printf("%s:%d\n",__FUNCTION__,__LINE__);
	list = delete_all_x(x,list);
	//list = delete_x(x,list);
	print_list(list);
	
	return 0;
}






