#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef char VType;//假设顶点的数据类型为int
typedef int AdjType;//边的类型(权)
					  //没有路径的时候,权为一个最大值,表示不可达

#define MAXN 1024
#define VERY_BIG 65535
typedef struct graph
{
	
	VType V[MAXN];//一个一维数组表示图中顶点的集合
	AdjType A[MAXN][MAXN];//二维数组表示图中顶点关系的集合 "邻接矩阵"
						//A[i][j] = w;//在二维数组中有一个关系,权值为w
						//V[i]--->V[j]有关系,且权为w
						//i,和j都是下标,i是起点在V数组的下标,j是终点在V数组的下标
						//A[i]行记录的是i这个顶点所有出去的关系
						
	int vexnum;//图中顶点的个数
	int arcnum;//图中边的条数
}Graph;


//根据用户的输入创建一个图
//返回创建的图的指针
Graph *create_graph();


//获取指定字符在顶点数组中的下标
//获取ch在s中的下标
int get_index(char ch,char *s);

//打印指定的图
void print_graph(Graph *g);

//销毁一个图
//释放空间

//把一个顶点加入到图
//把指定的顶点放到顶点数组的后面

//把一个关系加入到图
//操作邻接矩阵

//获取图g中下标为v的那个顶点的第一个邻接点下标
//如果没找到返回-1
int get_first_adj(Graph *g,int v);
//取图g中v相对于vi下一个邻接点
int get_next_adj(Graph *g,int v,int vi);

//以深度优先搜索的思想访问v以及v的邻接点,以及邻接点的邻接点...
void DFS(Graph *g,int v);
//以深度优先搜索的思想遍历图g
void DFStravel(Graph * g);



#endif


