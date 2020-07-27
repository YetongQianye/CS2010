#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkList.h" //在当前路径下查找 


int main()
{
	
	//创建一个链表
	struct node *list = create_linklist();
	print_reverse_list(list);
	
	return 0;
}






