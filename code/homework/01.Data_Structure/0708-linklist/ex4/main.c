#include<stdio.h>   //<>""的区别是查找路径不同 
#include<string.h> 

#include"LinkList.h" //在当前路径下查找 


int main()
{
	
	

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






