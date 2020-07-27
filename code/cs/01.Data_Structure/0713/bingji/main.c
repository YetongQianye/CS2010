#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkedList.h" //在当前路径下查找 


int main()
{
	//创建一个链表
	Head * h1 = create_list();
	int x;
	printf("please input the list num\n");
	while(1)
	{
		scanf("%d",&x);
		if(0 == x)
		{
			break;
		}
		insert_element(x,h1);
	}

	Head * h2 = create_list();
	printf("please input the list num\n");
	while(1)
	{
		scanf("%d",&x);
		if(0 == x)
		{
			break;
		}
		insert_element(x,h2);
	}
	print_list(h1);
	print_list(h2);

	Head *lc = Searchbin(h1,h2);
	print_list(lc);


	return 0;
}









