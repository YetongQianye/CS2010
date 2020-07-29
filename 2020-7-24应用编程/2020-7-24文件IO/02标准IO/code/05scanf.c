#include<stdio.h>

int main()
{
/*
	int a,b;
	scanf("%dabcdefg%d",&a,&b);
	printf("a = %d,b = %d\n",a,b);
*/
/*
	int r,a;
	char c;
	r = scanf("abcd%d %cabcd",&a,&c);
	printf("r = %d,a = %d\n",r,a);
	printf("c = %c\n",c);
*/

	char *buf = "123";
	int a;
	int r;
	r = sscanf(buf,"%d",&a);
	printf("r = %d,a = %d\n",r,a);

	return 0;
}



