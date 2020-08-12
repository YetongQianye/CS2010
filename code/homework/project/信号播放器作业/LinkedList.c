
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

struct fList *create_linkedlist()
{
	struct fList *f = (struct fList*)malloc(sizeof(struct fList));
	f->first = f->last = NULL;

	return f;

}

void add_a_filenode(struct fList* f , const char * filename, time_t mtime)
{
	if (f == NULL)
	{
		printf("f == NULL\n");
		return ;
	}

	struct fNode *p = (struct fNode *) malloc(sizeof(*p));
	strcpy(p->filename, filename);
	p->next = NULL;
	p->mtime = mtime;

	if (f->first == NULL)
	{
		f->first = p;
		f->last = p;
	}
	else
	{
		struct fNode *px = f->first;
		struct fNode *pr = NULL;

		while (px)
		{
			if (px->mtime > p->mtime)
			{
				break;
			}

			pr = px;
			px = px->next;
		}



		if (px == NULL)
		{
			f->last->next = p;
			f->last = p;
		}
		else
		{
			if (px == f->first)
			{
				p->next = f->first;
				f->first = p;
			}
			else
			{
				p->next = px;
				pr->next = p;
			}
		}
		
	}
	
}