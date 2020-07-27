#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkedList.h" //在当前路径下查找 


int main()
{

	printf("please input linklist:");

	struct node *l=create_LinkedList();
	print_list(l);
	printf("please enter the reciprocal number \n");
	int x;
	
	scanf("%d", &x);
	printf("the number is \n");
	struct node *first=reciprocal(l,x);
	printf("%d\n",first->data);

	return 0;
}









