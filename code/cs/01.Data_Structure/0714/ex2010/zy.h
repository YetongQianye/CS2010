#ifndef __ZY_H__
#define __ZY_H__


typedef int SElemType; //栈元素类型


typedef struct seqStack
{
	SElemType *elem; // malloc

	int top; //
			/*
			指向栈顶元素的下标.
			top = -1, 表示空栈。
		*/

	int max_len; //栈中元素的最大个数
	
}seqStack;

#endif
