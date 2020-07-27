#include<stdio.h>
#include"DoubleLinkedList.h"
int main()
{
	Head *l = create_list();//创建一个空链表
	int x;
	while(1)
	{
		scanf("%d",&x);
		if(x == 0)
		{
			break;
		}
		add_Elem_to_list(l,x);
	}
	print_list(l);
	//clear_list(l);
	//delete_list(l);
	//print_list(l);
	scanf("%d",&x);
	//delete_x(l,x);
	delete_all_x(l,x);
	print_list(l);
	//delete_list(l);
	return 0;
}