#ifndef __ZY_H__
#define __ZY_H__


typedef int SElemType; //ջԪ������


typedef struct seqStack
{
	SElemType *elem; // malloc

	int top; //
			/*
			ָ��ջ��Ԫ�ص��±�.
			top = -1, ��ʾ��ջ��
		*/

	int max_len; //ջ��Ԫ�ص�������
	
}seqStack;

#endif
