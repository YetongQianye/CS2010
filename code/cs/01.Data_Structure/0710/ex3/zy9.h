#ifndef __ZY9_H__
#define __ZY9_H__

typedef int ElemType ;

typedef struct note
{

	ElemType num;
	
	struct note *next;
	
}note;

typedef struct LinkedList
{
	struct note *first;
	struct note *last;
	ElemType num;
}LinkedList;


#endif
