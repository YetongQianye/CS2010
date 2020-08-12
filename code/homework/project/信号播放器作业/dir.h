#ifndef __DIR_H__
#define __DIR_H__

#include "LinkedList.h"


enum filetype
{
	FILE_UNKOWN,
	FILE_BMP,
	FILE_JPG,
	FILE_MP4
};

struct fList  *search_movies(const char *pathname);

enum filetype get_filetype(const char *filename);
#endif