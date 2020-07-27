#include<stdio.h>   //<>""的区别是查找路径不同 
#include<string.h> 

#include"LinkList.h" //在当前路径下查找 


int main()
{
	
	//创建一个链表
	//struct node *list = create_linklist();
	//print_list(list);

	//printf("please input a insert num\n");
	//int x;
	//scanf("%d",&x);
	//为x开辟一个空间
	//struct node *p = (struct node *)malloc(sizeof(*p));
	//p->data = x;
	//p->next = NULL;
	
	//list = insert_node(p,list);

	//printf("%s:%d\n",__FUNCTION__,__LINE__);
	//list = delete_all_x(x,list);
	//list = delete_x(x,list);
	//print_list(list);

	//print_reverse_list1(list);
	//print_reverse_list2(list);
	//list = reverse_list5(list);
	//print_list(list);

	printf("please input a  num\n");
	//char buf[1024] = {0};
	char *buf = (char *)malloc(1024);
	memset(buf,0,1024);
	scanf("%s",buf);
	struct node *list1 = create_list_by_num(buf);
	
	memset(buf,0,1024);
	scanf("%s",buf);
	struct node *list2 = create_list_by_num(buf);
	print_list(list1);
	print_list(list2);

	struct node *list3 = add_two_numbers(list1,list2);
	print_list(list3);
	delete_list(list3);
	list3 = NULL;
	free(buf);
	return 0;
}






