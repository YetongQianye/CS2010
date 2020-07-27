#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef int ElemType ;

typedef struct student
{

	ElemType num;
	
	struct student *next;
	
}student;

typedef struct LinkedList
{
	struct student *first;
	struct student *last;
	ElemType num;
}LinkedList;


#endif
