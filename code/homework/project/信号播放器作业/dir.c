#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "dir.h"
#include "LinkedList.h"


enum filetype get_filetype(const char *filename)
{
	//.bmp
	//.jpg

	if (strcmp(filename + strlen(filename) - 4, ".bmp") == 0)
	{
		return FILE_BMP;
	}
	else if (strcmp(filename + strlen(filename) - 4, ".jpg") == 0)
	{
		return FILE_JPG;
	}else if (strcmp(filename + strlen(filename) - 4, ".mp4") == 0)
	{
		return FILE_MP4;
	}
}



static void  search_dir(struct fList *f, const char *pathname)
{
	DIR *dir = opendir(pathname);
	if (dir == NULL)
	{
		perror("opendir error");
		return ;
	}


	struct dirent *dirp = NULL;

	while (dirp = readdir(dir))
	{
		char filename[256];
		
		if ( strcmp(dirp->d_name, ".") == 0  || 
			strcmp(dirp->d_name, "..") == 0 )
		{
			continue;
		}

		sprintf(filename, "%s/%s", pathname, dirp->d_name);
		struct stat st;

		stat(filename, &st);

		if (S_ISREG(st.st_mode))
		{
			if (get_filetype(filename) == FILE_MP4)
			{
				add_a_filenode(f, filename, st.st_mtime);
			}
			
		}
		else if (S_ISDIR(st.st_mode))
		{
			search_dir(f, filename);
		}

		
	}

	closedir(dir);

}

//
struct fList  *search_movies(const char *pathname)
{
	//要完成目录的搜索，以及链表的创建和加入。
	struct fList *f = create_linkedlist();

	search_dir(f, pathname);

	return f;
}





