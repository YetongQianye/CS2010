#include<stdio.h>
#include<string.h>
#include"LkStack.h"

int i = 0;

/*
	zfc：将字符串转换为十进制数
*/

void zfc(char e[] ,LkStack *num)
{
	int sum = 0;
	int n,m,i = 0;
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
	Push(num,sum);
}

int expression(char *e,LkStack *num,LkStack *oper)
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
				Push(num,p2);
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
				
				p1 = Pop(num,p1);
				s--;
				l = i;
				i++;
				if(e[i] == '(')
				{
					i++;
					p2 = expression(e,num,oper);
					Push(num,p2);
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
				p2 = Pop(num,p2);
				s--;
				if(e[l] == '*')
				{
					p1 = p1 * p2;
					Push(num, p1);
					s++;
				}
				else
				{
					p1 = p1 / p2;
					Push(num, p1);
					s++;
				}
			}
			else if(e[i] == '+' || e[i] == '-' )
			{
				Push(oper,e[i]);
				while (1)
				{
					i++;
					if(e[i] == '(')
					{
						i++;
						p2 = expression(e,num,oper);
						Push(num,p2);
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
	
	while (num->last > 0 && oper->last > -1 && s>1)
	{
		p1 = Pop(num,p1);
		s--;
		p2 = Pop(num,p2);
		s--;
		p3 = Pop(oper,p3);
		if (p3 == '+')
		{
			p1 = p1 + p2;
			Push(num,p1);
			s++;
		}
		else
		{
			p1 = p2 - p1;
			Push(num,p1);
			s++;
		}
	}
	p1 = Pop(num,p1);
	return p1;
}

int main()
{
	char p[1024];
	scanf("%s",p);
	int z = strlen(p);
	LkStack *num = InitStack(z);
	LkStack *oper = InitStack(z);
	
	int a = expression(p,num,oper);
	printf("%d \n",a);
}