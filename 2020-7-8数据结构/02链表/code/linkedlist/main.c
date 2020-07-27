#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkedList.h" //在当前路径下查找 


int main()
{
	//创建一个链表
	Head * h = create_list();
	int x;
	printf("please input the list num\n");
	while(1)
	{
		scanf("%d",&x);
		if(0 == x)
		{
			break;
		}
		insert_elemt(x,h);
	}

	print_list(h);
/*
	Node * p = find_x(100,h);
	if(p != NULL)
	{
		printf("find it:%d \n",p->data);
	}
*/
	//printf("please input the delete num\n");
	//scanf("%d",&x);
	//删除元素值为x的结点
	//delete_x(x,h);
	//print_list(h);
	//删除所有元素值为x的结点
	//delete_all_x(x,h);
	//print_list(h);

	//clear_list(h);
	//print_list(h);
	return 0;
}









