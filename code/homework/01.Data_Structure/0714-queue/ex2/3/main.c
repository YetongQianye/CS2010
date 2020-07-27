#include<stdio.h>
#include"LkStack.h"

int is_operator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '%')
	{
		return 1;
	}
	return 0;
}
int compare(char ch1,char ch2)
{
	if((ch1=='*' ||ch1=='/' || ch1 =='%')&&(ch2=='+' || ch2 =='-'))
	{
		return 1;
	}
	return 0;
}

int calculate(int a,int ch,int b)
{
	switch(ch)
	{
		case '+':
		{
			return a+b;
		}
		case '-':
		{
			return a-b;
		}
		case '*':
		{
			return a*b;
		}
		case '/':
		{
			return a/b;
		}
		case '%':
		{
			return a%b;
		}
	}
}

int expression_value(char *str)
{
	//初始化两个栈,一个存操作数,还有一个存储操作符
	LkStack *moperand = InitStack(); //操作数
	LkStack *moperator = InitStack();//操作符
	while(*str)
	{
		//解析出操作数,直接入栈
		//解析出运算符,分情况操作
		while(*str <'0' || *str > '9')//不是数字字符
		{
			str++;			
		}
		//str一定指向数字字符
		int d=0;
		while(*str>='0' && *str <='9')
		{
			d = d*10+(*str-'0');
			str++;
		}
		//操作数直接出栈
		Push(moperand,d);

		while(*str && !is_operator(*str))
		{
			str++;
		}
		if(*str == '\0')
		{
			break;			
		}
		//str肯定指向操作符
		/*
		如果操作符栈为空或者当前待入栈操作符优先级比栈顶操作符优先级高,则直接入栈,
		如果当前待入栈操作符优先级比栈顶操作符优先级低,则取出两个操作数和一个
		操作符,运算(消耗栈顶操作符)的结果入栈.....直到当前待入栈操作符能够入栈
		*/
		while(1)
		{
			int ch;
			GetTop(moperator,&ch);
			if(StackIsEmpty(moperator)||compare(*str,ch))
			{
				Push(moperator,*str);
				break;			
			}
			int a,b;//操作数
			
			Pop(moperand,&b);
			Pop(moperand,&a);
			Pop(moperator,&ch);

			Push(moperand,calculate(a,ch,b));	
		}
		str++;
		
	}
	

	while(!StackIsEmpty(moperator))
	{

		//取出两个操作数和一个操作符,运算(消耗栈顶操作符)的结果入栈
		int a,b;	//操作数
		int ch;	//运算符
		Pop(moperand,&b);
		Pop(moperand,&a);
		Pop(moperator,&ch);

		Push(moperand,calculate(a,ch,b));	
	}
	int r;
	Pop(moperand,&r);
	DestroyStack(&moperand);
	DestroyStack(&moperator);
	return r;
}
int main()
{
	char buf[128] = {0};
	scanf("%s",buf);
	int r = expression_value(buf);
	printf("%s=%d\n",buf,r);
	return 0;
}

