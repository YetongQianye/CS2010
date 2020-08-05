#include<stdio.h>

int a = 5; //.data
int b; //.bss
static int c = 6;//.data

char *fun()
{
	char *p1 = "ABCDEFG";
	return p1;
}

int main(int argc,char *argv[])
{
	char ch;//局部变量 “栈”
	char *p = "12345";
	//p是一个局部变量“栈”,"12345"是常量字符串“.rodata”
	//sizeof(p) ?  32位是4    64位系统是8
	//*(p+1)='B';//通过指针p去修改只读内存
	//*(p+1) <====> p[1]
	p = "789";//没问题
	p = fun();
	printf("%s\n",p);//ABCDEFG
	char *p2 = malloc(1024);
	//p2是一个局部变量“栈”,但是指向的1024个字节存在于堆中
	*(p2+1) = 'A'; //堆是可读可写的
	p2="abcdefg";//语法没有问题,但是会造成内存泄漏
	char x[] = {"abcde"};//在定义的时候利用“abcde”初始化数组
	//数组存在于栈,"abcde"在.rodata,在栈中也有"abcde"的副本
	x[1] = 'B';
	x = "123"; //有问题,x是数组名是一个指针常量。
	
	return 0;
}
























