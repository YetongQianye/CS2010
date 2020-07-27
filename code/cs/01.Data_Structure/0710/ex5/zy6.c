 #include <stdio.h>
#include <stdlib.h>
#include "zy6.h"

/*
	���һ���㷨���ж�һ�����������Ƿ���ڻ�?
		����һ�����飬��ÿһ�����ĵ�ַ����������
		ÿ����һ���ͽ��б��������Ƿ�����ͬ�ģ�
		������ͬ������ڻ�����û�У��򲻴���
*/

/*
	lbpx������������ų�����
	����ֵ��
			����ĵ�һ�����ĵ�ַ
*/

struct student *lbpx()
{
	int a,s=0;
	student *p;
	student *first=NULL;
	student *last=NULL;
	printf("����һ������\n");
	while (1)
	{
		scanf("%d",&a);
		if(a == 0)
		{
			break;
		}
		p = malloc(sizeof(*p));
		if(s == 0)
		{
			first = p;
			last = p;
			s++;
		}
		p->num = a;
		last->next = p;
		p->next = NULL;
		last = p;
	}
	return first;
}

/*
	lbpx������������ų�����
	����ֵ��
			����ĵ�һ�����ĵ�ַ
*/

struct student *lbpx1()
{
	int a,s=0;
	student *p;
	student *first=NULL;
	student *last=NULL;
	printf("����һ������\n");
	while (1)
	{
		scanf("%d",&a);
		if(a == 0)
		{
			break;
		}
		p = malloc(sizeof(*p));
		if(s == 0)
		{
			first = p;
			last = p;
			s++;
		}
		p->num = a;
		last->next = p;
		p->next = NULL;
		last = p;
	}
	last->next = first;
	return first;
}

/*
	is_circle���ж��Ƿ���ڻ�
	@h��ָ�������׵�ַ
	����ֵ
		1������
		0��������
*/

int is_circle(struct student *h)
{
	if(h == NULL)
	{
		return -1;
	}
	int a[100];
	int i=0;
	int n;
	while(h)
	{
		a[i]=(int)h;
		h = h->next;
		for(n=0;n<i;n++)
		{
			if(a[i] == a[n])
			{
				return 1;
			}
		}
		i++;
	}
	return 0;
}

/*
	shuchu��ѭ�����
	@p��ָ������ĵ�һ���ĵ�ַ
*/

void shuchu(student *p)
{
	if (p != NULL)
	{
		while (p)//ѭ�����
		{
			printf("%d ", p->num);
			p = p->next;
		}
	}
}

/*
	shifan��ѭ���ͷ�����Ŀռ�
	@p��������ǰ�ݽ�
	@n������p������ͷ�
*/

int shifan(student *p,student *n)
{
	
	while (n)
	{
		p = p->next;
		n->next=NULL;
		free(n);
		n=p;
	}
}

int main()
{
	int h;
	printf("�Ƿ�ɻ����ɻ�����1������Ϊ0\n");
	scanf("%d",&h);
	student *n;
	if(h == 0)
	{
		n = lbpx();//����n��������ĵ�һ����ַ
	}
	else if(h == 1)
	{
		n = lbpx1();
	}
	else 
	{
		n = NULL;
	}
	int a = is_circle(n);
	
	printf("%d\n",a);
	
	student *p;
	p=n;
	shifan(n,p);
	
	printf("\n");
	return 0;
}
//printf("1\n");
