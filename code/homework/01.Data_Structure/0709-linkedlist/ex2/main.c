#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkedList.h" //在当前路径下查找 


int main()
{
	//创建一个链表
	Head * la = create_list();
	int x;
	printf("please input the list1 num\n");
	while(1)
	{
		scanf("%d",&x);
		if(0 == x)
		{
			break;
		}
		insert_element(x,la);
	}
	printf("la: ");
	//struct node *la = create_LinkedList();
	//print_list(la);

	printf("lb: ");
	flap(la);
	
	print_list(la);
	

	return 0;
}









