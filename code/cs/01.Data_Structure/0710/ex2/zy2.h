#ifndef __ZY2_H__
#define __ZY2_H__


typedef int ElemType ; //����Ԫ�ص�����


//���ݽ��
typedef struct node
{
	ElemType data; //������

	struct node *next; //ָ����
} Node;


//ͷ���
typedef struct LinkedList
{
	struct node *first; //ָ�������еĵ�һ�����
	struct node *last ; //ָ�������е����һ�����

	// ...
	
} LinkedList;



#endif


