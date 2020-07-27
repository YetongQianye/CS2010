
// 1.����һ�����ʽ��ֵ�����ʽ�����ַ�������ʽ����

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
�ж�sָ���ջ���Ƿ�Ϊ��ջ
				1����ʾ��ջ
				0����ʾ�ǿ�
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
	push: ��Ԫ��e����ջ����sָ���ջ��
	@s
	@e
	����ֵ:
		���� 1��ʾ��ջ�ɹ�
		���� 0��ʾ��ջʧ��
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
	pop: ��ջ����sջ�е�ջ��Ԫ��ֵ��ֵ��*p
	@s:
	@p:
	����ֵ:
		����1 ,��ʾ�ɹ�
		����0, ��ʾʧ��
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
	zfc�����ַ���ת��Ϊʮ������
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
	expression�����м���
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



