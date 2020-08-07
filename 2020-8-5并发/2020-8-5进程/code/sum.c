#include<stdio.h>
//把指定的字符串转换为整数
int my_atoi(char *str)
{
	int d = 0;
	while(*str >='0' && *str <='9')
	{
		d = d*10 + (*str-'0');
		str++;
	}
	return d;
}


//计算两个命令行参数的和
int main(int argc,char *argv[])
{
	int sum; 
	int a,b;
	printf("wo shi liang zai\n");
	a = my_atoi(argv[1]);
	b = my_atoi(argv[2]);
	sum = a+b;
	printf("sum = %d\n",sum);
	sleep(10);
}