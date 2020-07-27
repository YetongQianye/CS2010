#include<stdio.h>   //<>""的区别是查找路径不同 
#include<string.h> 

#include"LinkedList.h" //在当前路径下查找 
	

int main()
{

	LinkedList *l = creat_list();
	
	print_LinkedList(l);


	int x;
	scanf("%d", &x);

		delete_all_x(l, x);

	print_LinkedList(l);

	return 0;
}






