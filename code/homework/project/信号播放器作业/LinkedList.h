#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <time.h>

struct fNode
{
	unsigned char filename[256];

	time_t  mtime;//文件最后修改的时间

	struct fNode *next;
};


struct fList
{
	struct fNode *first;
	struct fNode *last;
	
};


struct fList *create_linkedlist();

void add_a_filenode(struct fList* , const char *, time_t);

#endif
