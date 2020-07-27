
// 1.　求一个表达式的值，表达式是以字符串的形式给出

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zy.h"



int i =0;

seqStack* alloc_SqQueue(int max_len)
{
	seqStack* s = malloc(sizeof(*s));
	
	s->elem = malloc ( sizeof (SElemType) * max_len);
	
	s->top = -1;
	
	s->max_len = max_len;
}

/*
判断s指向的栈，是否为空栈
				1　表示空栈
				0　表示非空
 */
 
int stack_is_empty(seqStack *s)
{
	if (s == NULL || s->top == -1)
	{
		return 1;
	}

	return 0;
}

/*
	push: 把元素e　入栈　到s指向的栈中
	@s
	@e
	返回值:
		返回 1表示入栈成功
		返回 0表示入栈失败
*/

int push(seqStack *s, SElemType e)
{
	if (s == NULL || s->elem == NULL || (s->top == s->max_len - 1))
	{
		printf("push ERROR\n");
		return 0;
	}

	s->top ++;
	s->elem[s->top] = e;
	
	//	s->elem[++s->top] = e;

	return 1;
}

/*
	pop: 出栈。把s栈中的栈顶元素值赋值给*p
	@s:
	@p:
	返回值:
		返回1 ,表示成功
		返回0, 表示失败
*/
int pop(seqStack *s , SElemType p )
{
	if (stack_is_empty(s))
	{
		return 0;
	}


	p = s->elem[s->top];
	s->top--;
	
	return p;
	
}

/*
	zfc：将字符串转换为十进制数
*/

void zfc(char e[] ,seqStack *num)
{
	int sum = 0;
	int n,m;
	n = i;
	while (e[i] >= '0' && e[i] <= '9')
	{
		i++;
	}
	i--;
	for(m=n;m<=i;m++)
	{
		sum = sum * 10 + (int) (e[m]-'0');
	}
	push(num,sum);
}

/*
	expression：进行计算
*/

int expression(char *e,seqStack *num,seqStack *oper)
{
	int p1;
	int p2;
	char p3;
	int z = strlen(e);
	int l;
	int s = 0;
	for ( ;i<=z-1;i++)
	{
		if(e[i] >= '0' && e[i] <= '9')
		{
			zfc(e,num);
			s++;
		}
		else 
		{
			if(e[i] == '(')
			{
				i++;
				p2 = expression(e,num,oper);
				push(num,p2);
				s++;
				while(e[i] != ')')
				{
					i++;
				}
				continue;
			}
			if(e[i] == ')')
			{
				break;
			}
			if(e[i] == '*' || e[i] == '/' )
			{
				
				p1 = pop(num,p1);
				s--;
				l = i;
				i++;
				if(e[i] == '(')
				{
					i++;
					p2 = expression(e,num,oper);
					push(num,p2);
					s++;
					while(e[i] != ')')
					{
						i++;
					}
				}
				else
				{
					while (i<=z)
					{
						if(e[i] >= '0' && e[i] <= '9')
						{
							zfc(e,num);
							s++;
							break;
						}
						i++;
					}
				}
				p2 = pop(num,p2);
				s--;
				if(e[l] == '*')
				{
					p1 = p1 * p2;
					push(num, p1);
					s++;
				}
				else
				{
					p1 = p1 / p2;
					push(num, p1);
					s++;
				}
			}
			else if(e[i] == '+' || e[i] == '-' )
			{
				push(oper,e[i]);
				while (1)
				{
					i++;
					if(e[i] == '(')
					{
						i++;
						p2 = expression(e,num,oper);
						push(num,p2);
						s++;
						while(e[i] != ')')
						{
							i++;
						}
						break;
					}
					if(e[i] >= '0' && e[i] <= '9')
					{
						i--;
						break;
					}
				}
			}
		}
	}
	
	while (num->top > 0 && oper->top > -1 && s>1)
	{
		p1 = pop(num,p1);
		s--;
		p2 = pop(num,p2);
		s--;
		p3 = pop(oper,p3);
		if (p3 == '+')
		{
			p1 = p1 + p2;
			push(num,p1);
			s++;
		}
		else
		{
			p1 = p2 - p1;
			push(num,p1);
			s++;
		}
	}
	p1 = pop(num,p1);
	return p1;
}

int main()
{
	char p[1024];
	scanf("%s",p);
	int z = strlen(p);
	seqStack *num = alloc_SqQueue(z);
	seqStack *oper = alloc_SqQueue(z);
	
	int a = expression(p,num,oper);
	printf("%d \n",a);
}



