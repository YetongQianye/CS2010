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
		insert_element(x,h);
	}
	print_list(h);
    
#if 0 
	struct node *l=create_LinkedList();
	print_list(l);
	printf("---------\n");
	struct node *first=middle(l);
	printf("%d\n",first->data);
#endif
	return 0;

}









