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
	struct node *list = create_list_by_digital(buf);
	print_list(list);

}






