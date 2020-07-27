#include<stdio.h>
#include"Graph.h"

int main()
{
	Graph *g = create_graph();
	print_graph(g);

	DFStravel(g);
	BFStravel(g);
	return 0;
}





