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
	
	//创建一个链表
	Head * lb = create_list();
	printf("please input the list2 num\n");
	while(1)
	{
		scanf("%d",&x);
		if(0 == x)
		{
			break;
		}
		insert_element(x,lb);
	}
	print_list(la);

	print_list(lb);

	Head *lc = Merge(la,lb);
	print_list(lc);
	
	return 0;
}









