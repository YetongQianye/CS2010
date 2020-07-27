#include"mysort.h"


/*
sort:排序
@a:数组的首地址
@num:数组的元素个数
*/
void mysort(int *a,int num)
{
	int i,j;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1-i;j++)
		{
			if(a[j] > a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}

		}
	}
}




