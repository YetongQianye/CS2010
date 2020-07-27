#include<stdio.h>
#include<string.h>
#include"LkStack.h"

int expression(char *s)
{
	//初始化两个栈:操作数栈，　运算符栈
	LkStack *s1 = InitStack(1024); //操作数栈
	LkStack *s2 = InitStack(1024); //运算符栈


	int d = 0;
	while (s)
	{
		//先解析操作数

		while (!is_digital_char(*s))
			s++;

		d = 0;
		while (is_digital_char(*s))
		{
			d = d*10 + (*s - '0');
			s++;
		}


		//操作数直接入栈
		Push(s1, d);




		//解析运算符
		while (*s && !is_op_char(*s))
		{
			s++;
		}

		if (*s == '\0')
		{
			break;
		}

		// *s　代表一个运算符
		while(1)
		{
			int top; //运算符栈顶元素
			GetTop(s2, &top);

		
			if (StackIsEmtpy(s2) || is_high(*s, top))
			{
				Push(s2, (ElemType)*s);
				break;
			}
			else 
			{
				//待入栈的运算符的优先级<栈顶元素的优先级
				//先干掉栈顶元素
				consume_top(s1, s2);
				
				
			}
		}
		s++; 

		
		
	}


	//
	while(!StackIsEmtpy(s2))
	{
		consume_top(s1,s2);
	}
	

	int ret;
	Pop(s1, &ret);


	//
	DestroyStack(s1);
	DestroyStack(s2);

	return ret;
}

int main()
{
	char str[1024];

	scanf("%s", str);

	printf("%s = %d\n",str,  expression(str));


	return 0;
}
