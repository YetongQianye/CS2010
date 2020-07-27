// 2. �鲢������������Ҫ��鲢�������Ҳ����

#include <stdio.h>
#include <stdlib.h>

#include "zy2.h"

/*
	Insert_a_Node:��hָ�������������У�����һ�����p
				ʹ���Ӻ��������Ȼ����
	@h: ָ�����е�����
	@p:��ָ�������Ľ��
	����ֵ:
		������Ӻ�������ĵ�һ������ָ��
*/
struct node *Insert_a_Node(struct node *h, struct node *p)
{
	if (h == NULL)
	{
		return p;
	}
	
	if (p == NULL)
	{
		return h;
	}
	
	// ��pָ��Ľ�㣬���뵽hָ���������ȥ�� "��������"
	// 1. �Ҳ���λ��
	//  "����"�����ҵ���һ��ֵ��p->data����Ǹ����pk(�Լ�pkǰ����Ǹ����pr)
	//	pkǰ����ǲ���λ��
	struct node *pk = h; // ָ�������е�һ����p->dataֵ��Ľ��
	struct node *pr = NULL; //ָ��pkǰ����Ǹ����

	while (pk)
	{
		if (pk->data > p->data)
		{
			break;
		}

		pr = pk;
		pk = pk->next;
	}
	
	// 2. �������

	if (pk)
	{
		if (pk == h)
		{
			//ͷ�巨
			p->next = h;
			h = p;

		}
		else
		{
			//pkָ��ĺ���Ľ�㣬prָ��pkǰ����Ǹ����
			// p������pk��ǰ�棬pr�ĺ���

			p->next = pk;
			pr->next = p;
		}
	

	}
	else 
	{	
		//û�ҵ�,=>�����������н���ֵ����p->dataҪС��
		//  pk == NULL, prָ����������һ�����
		// "β�巨"
		pr->next = p;
	}
	
	
	return h;
	
}




//�����û��Ӽ����ϵ�����������һ����������
// �û�����0��ʾ����
struct node*
create_LinkedList(void)
{

	struct node *first = NULL; //ָ�򴴽��������ĵ�һ������ָ��
	struct node *last = NULL; //ָ�򴴽������������һ������ָ��
	struct node *p = NULL;  //ָ��ÿ�δ������Ǹ����ĵ�ַ

	int d;

	while (1)
	{
		//1. �Ӽ����Ͻ���һ���û����������
		scanf("%d", &d);
		if (d == 0)
		{
			break;
		}


		//2. ����һ���ṹ���������������
		p = malloc(sizeof(*p));
		p->data = d;
		p->next = NULL;


		//3. �Ѵ���������ṹ����뵽firstָ���������ȥ
		first = Insert_a_Node(first, p);
		
	}
	
	return first;
}



/*
	find_last:��hָ��ĵ������У��������һ�����
			������ָ�뷵��
	@h:
	����ֵ:
		���һ������ָ��
*/		
struct node* find_last(struct node *h)
{
	struct node *p = h; //pָ�����һ�����

	while (p)
	{

		if (p->next == NULL)
		{
			return p;
		}
		else
		{
			//������������
			p = p->next;
		}

	}




	return p;

}




void print_list(struct node *p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

struct node *merge(struct node *ha, struct node *hb)
{
	struct node *pc = NULL;//ָ��ϲ��������ĵ�һ�����
	struct node *pr = NULL;
	if (ha == NULL)
	{
		return hb;
	}
	
	if (hb == NULL)
	{
		return ha;
	}
	
	pc = ha->data < hb->data ? ha : hb;
	
	while (ha && hb)
	{
		if (ha->data < hb->data)
		{
			while (ha && ha->data < hb->data)
			{
				pr = ha;
				ha = ha->next;
			}
			
			pr->next = hb;
		}
		else
		{
			while (hb && hb->data < ha->data)
			{
				pr = hb;
				hb = hb->next;
			}
			
			pr->next = ha;
		}
	
	}
	
	return pc;
	
}


int main()
{
	struct node *ha = create_LinkedList();
	printf("ha: ");
	print_list(ha);
	
	struct node *hb = create_LinkedList();
	printf("hb: ");
	print_list(hb);


	struct node *hc = merge(ha,hb);
	printf("hc: ");
	print_list(hc);
	
	return 0;
}


