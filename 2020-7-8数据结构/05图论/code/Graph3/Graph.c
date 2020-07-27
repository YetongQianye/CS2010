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



//以广度优先搜索的策略遍历图g
void BFStravel(Graph * g)
{
	//初始化标记数组
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		visited[i] = 0;
	}
	
	//初始化一个队列
	SqQueue *q = InitQueue(MAXN);
	//开始以广度优先搜索遍历图g(从下标为0的顶点开始)
	printf("BFS:");
	int v0;
	for(v0=0;v0<g->vexnum;v0++)
	{
		if(visited[v0] == 0)
		{
			//访问v0并且标记v0已经被访问
			printf("%c  ",g->V[v0]);
			visited[v0] = 1;
			//v0入队列
			EnQueue(q,v0);
			while(!QueueIsEmpty(q)) //队列不为空
			{
				//出队
				int w;//保存出队元素
				DeQueue(q,&w);
				//访问出队元素的所有邻接点,且在访问的时候入队列
				int u;
				for(u=get_first_adj(g, w);u>0;u=get_next_adj(g, w, u))
				{
					if(visited[u] == 0) //w的邻接点未被访问
					{
						//访问并且入队列
						printf("%c  ",g->V[u]);
						visited[u] = 1;

						//u入队
						EnQueue(q,u);
					}
				}
			
			}
			//可以把所有从v0开始可以访问到的顶点全部访问完毕
		}
	}
	DestoryQueue(q);
	printf("\n");
}



//求图g中,顶点v0到其他各顶点的最短路径
void dijkstra(Graph *g,int v0)
{
	//定义并且初始化三个辅助向量
	//向量S[n] <----标记向量
	int s[MAXN] = {0};
	//向量dist[n] <-----保存起点到其他顶点的最短路径值
	//初始时为g->A[v]那一行
	AdjType dist[MAXN] = {0};
	int i;
	//向量path[n][n]  <-----path[i]这一行保存v0到vi最短路径上所有顶点
	//路径第一个顶点肯定是源点 path[i][0] = g->V[v0]
	//如果<v0,vi>有直接路径
	//已知路径为v0-->vi,第二个点应该是终点,path[i][1] = g->V[vi]
	VType path[MAXN][MAXN] = {0};
	for(i=0;i<g->vexnum;i++)
	{
		dist[i] = g->A[v0][i];
		s[i] = (i==v0?1:0);//默认到本身的最短路径已经确定

		path[i][0] = g->V[v0];//每一个路径的第一个点肯定是起点
		if(g->A[v0][i] != VERY_BIG) //v0-->i存在之间路径
		{
			path[i][1] = g->V[i]; //第二个点应该是终点
		}
	}

	//一条一条的确定最短路径
	//有n个元素,总共有n-1条最短路径(假设到本身的最短路径已经确定)
	//每一次循环都会确定一条最短路径
	int n = 0;//已经确定的最短路径条数
	for(n=0;n<g->vexnum-1;n++)
	{
		//step1:从没有确定的最短路径数组中找出最短的一个,作为当前确定的最短路径
		//s[u] == 0 && dist[u] 是dist数组中最小的
		//找出dist数组中的最小值以及下标,作为当前确定的最短路径
		int min = VERY_BIG; 
		int u = -1;
		for(i=0;i<g->vexnum;i++)
		{
			if(s[i]) //此最短已经确定
			{
				continue;
			}

			if(dist[i] <= min)
			{
				min = dist[i];
				u = i;
			}
		}

		//dist[u]是当前确定的最短路径
		s[u] = 1;
		
		//step2:根据当前确定的最短路径u,更新其他没有确定的最短路径
		//if(dist[w] > dist[u] + dist[u,w] && s[w] == 0)
		//	dist[w] = dist[u] + dist[u,w]
		
		for(i=0;i<g->vexnum;i++) //遍历没有确定的最短路径
		{
			if((s[i]==0)&&(dist[u]+g->A[u][i] < dist[i])) //根据条件更新最短路径已经path
			{
				dist[i] = dist[u]+g->A[u][i];//更新间接路径比原来路径短的

				//v0-->vi  ===> v0-->u + u--->i
				//path[i] = path[u] + i
				strcpy(path[i],path[u]);
				int l = strlen(path[i]);
				path[i][l]=g->V[i];
			}
		}
	}
	//v0到所有顶点的最短路径都确定了
	//dist数组保存的是最终的最短路径
	//path数组保存的是最短路径经过的顶点序列
	int j;
	for(i=0;i<g->vexnum;i++) 
	{
		printf("%c--->%c:[%d],path:",g->V[v0],g->V[i],dist[i]);
		for(j=0;path[i][j];j++)
		{
			printf("%c ",path[i][j]);
		}
		printf("\n");
	}
	
	
}












