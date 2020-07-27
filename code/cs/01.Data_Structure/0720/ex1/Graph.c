#include"Graph.h"



//获取指定字符在顶点数组中的下标
//获取ch在s中的下标
int get_index(char ch,char *s)
{
	int i = 0;
	for(i=0;s[i];i++)
	{
		if(ch == s[i])
		{
			return i;
		}
	}
	return -1;//表示没找到
}


//根据用户的输入创建一个图
//返回创建的图的指针
Graph *create_graph()
{
	//给图分配空间并且初始化
	Graph *g = (Graph *)malloc(sizeof(*g));
	g->vexnum = 0;
	g->arcnum = 0;
	memset(g->V,0,sizeof(g->V));
	//默认初始时,邻接矩阵中没有关系,
	int i,j;//初始化邻接矩阵,没有直接路径时使用VERY_BIG表示
	for(i=0;i<MAXN;i++)
	{
		for(j=0;j<MAXN;j++)
		{
			g->A[i][j] = VERY_BIG;
		}
	}

	//把用户输入的数据(V,R)存储到空间中
	//V所有顶点(使用字符串表示所有顶点)
	//R所有关系
	scanf("%s",g->V);
	getchar(); //去掉输入流中的回车
	g->vexnum = strlen(g->V);
	
	//R所有关系     AB w    A---->B 权为w
	while(1)
	{
		//从键盘获取第一组关系
		char s,p;//start   point
		int w;
		scanf("%c%c%d",&s,&p,&w);  //s--->p w
		getchar(); //去掉输入流中的回车
		if(s=='#')
		{
			break;
		}
		//把关系存储到邻接矩阵中 s--->p w
		//g->A[i][j] = w; i是起点s在顶点数组中的下标,j是终点p在顶点数组中的下标
		i = get_index(s,g->V);
		j = get_index(p,g->V);
		if(i==-1 || j== -1)
		{
			continue;
		}
		g->A[i][j] = w;
		g->arcnum++;
	}
	return g;
}



//打印指定的图
void print_graph(Graph *g)
{
	int i,j;
	//顶点个数
	printf("vexnum = %d\n",g->vexnum);
	//边的条数
	printf("arcnum = %d\n",g->arcnum);
	//顶点数组
	printf("顶点集合:\n");
	for(i=0;i<g->vexnum;i++)
	{
		printf("%c\t",g->V[i]);
	}
	printf("\n");
	printf("关系集合:\n");
	//顶点之间的关系集合(邻接矩阵)
	for(i=0;i<g->vexnum;i++)
	{
		for(j=0;j<g->vexnum;j++)
		{
			if(g->A[i][j] != VERY_BIG)
			{
				printf("%d\t",g->A[i][j]);
			}else 
			{
				printf("%c\t",'#');
			}
		}
		printf("\n");
	}
}


//获取图g中下标为v的那个顶点的第一个邻接点下标
//如果没找到返回-1
int get_first_adj(Graph *g,int v)
{
	//遍历关系数组的下标为v的那一行
	int i=0;
	for(i=0;i<g->vexnum;i++)
	{
		if(g->A[v][i] != VERY_BIG)
		{
			return i;
		}
	}
	return -1;//表示没有邻接点
}
//取图g中v相对于vi下一个邻接点
int get_next_adj(Graph *g,int v,int vi)
{
	//遍历关系数组的下标为v的那一行从vi开始的数
	int i;
	for(i=vi+1;i<g->vexnum;i++)
	{
		if(g->A[v][i] != VERY_BIG)
		{
			return i;
		}
	}
	return -1;//表示没有邻接点

}

int visited[MAXN];

//以深度优先搜索的思想访问v以及v的邻接点,以及邻接点的邻接点...
void DFS(Graph *g,int v)
{
	//访问v本身并且标记v表示的顶点已经被访问
	printf("%c  ",g->V[v]);
	visited[v]=1;
	int vi;
	//以深度优先搜索的思想访问v的每一个邻接点
	for(vi=get_first_adj(g,v);vi>=0;vi=get_next_adj(g,v,vi))
	{
		if(visited[vi]==0)
		{
			DFS(g,vi);
		}
	}
}
//以深度优先搜索的思想遍历图g
void DFStravel(Graph * g)
{
	int i;
	//初始化标记数组
	for(i=0;i<g->vexnum;i++)
	{
		visited[i] = 0;
	}
	printf("DFS:");
	for(i=0;i<g->vexnum;i++) //遍历顶点数组
	{
		if(visited[i] == 0)
		{
			DFS(g,i);
		}
	}
	printf("\n");
}











