#include<stdio.h>
#include"LkStack.h"


//判断ch表示的字符是否为操作符(+-*%/ . ())
//返回值:是操作符返回1,否则返回0
int is_operator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
	{
		return 1;
	}
	return 0;
}

//比较ch1和ch2的优先级,如果ch1的优先级高于ch2则返回1,否则返回0
int compare(char ch1,char ch2)
{
	if((ch1=='*' ||ch1=='/' || ch1 == '%' )&&(ch2=='+' || ch2 == '-'))
	{
		return 1;
	}
	return 0;
}

//把a ch b的计算结果返回
int  jisuan(int a,int ch,int b)
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
		//把数字前面的无用字符去掉
		while(*str <'0' || *str > '9')//不是数字字符
		{
			str++;
		}
		//str一定指向数字字符,把当前操作数取出来
		int d=0;
		while(*str>='0' && *str <='9')
		{
			d = d*10+(*str-'0');
			str++;
		}
		//*str == '.' ????
		
		//操作数直接入栈
		Push(moperand,d);
		//str一定不指向数字,如果不指向操作符,则过滤掉
		while(*str && !is_operator(*str))
		{
			str++;
		}

		if(*str == '\0')
		{
			break;
		}

		//str肯定指向的是操作符
		/*
		解析出运算符,分情况操作
		如果操作符栈为空或者当前待入栈操作符优先级比栈顶操作符优先级高,
		则直接入栈.
		如果当前待入栈操作符优先级比栈顶操作符优先级低,则取出两个操作数
		和一个操作符,运算(消耗栈顶操作符)的结果入栈.....直到当前待入栈操
		作符能够入栈.		
		*/
		while(1)
		{
			int ch;
			GetTop(moperator,&ch);
			if(StackIsEmtpy(moperator)||compare(*str,ch)) 
			{
				Push(moperator,*str);
				break;
			}
			//取出两个操作数和一个运算符计算,把结果入栈
			int a,b;//操作数
			Pop(moperand,&b);
			Pop(moperand,&a);
			Pop(moperator,&ch);
			//a ch b
			Push(moperand,jisuan(a,ch,b));
		}
		str++;
	}
	//运算符栈可能不为NULL,则依次计算直到运算符栈为NULL
	while(!StackIsEmtpy(moperator))
	{
		//取出两个操作数和一个操作符,运算(消耗栈顶操作符)的结果入栈
		int a,b;//操作数
		int ch;//运算符
		Pop(moperand,&b);
		Pop(moperand,&a);
		Pop(moperator,&ch);
		//a ch b
		Push(moperand,jisuan(a,ch,b));
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
	scanf("%s",buf); //scanf不能接收空白字符

	int r = expression_value(buf);
	printf("%s=%d\n",buf,r);

	return 0;
}






















