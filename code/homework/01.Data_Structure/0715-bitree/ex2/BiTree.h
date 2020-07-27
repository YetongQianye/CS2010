#ifndef __BI_TREE_H__
#define __BI_TREE_H__

#include<stdio.h>
#include<stdlib.h>


//类型的定义和函数的声明


typedef int ElemType; //二叉树中用户数据类型为int
//二叉树的结点类型
typedef struct BiTNode
{
	ElemType data;//用户数据类型
	struct BiTNode *lchild; //指向它的左子结点
	struct BiTNode *rchild;//指向它的右子结点
}BiTNode;

/*
create_tree_by_str:根据用户输入的字符串,建立一颗二叉树
返回值:
返回建立的二叉树的根节点的指针
*/
BiTNode *create_tree_by_str(const char *str);

//把元素e插入到t表示的二叉树中
BiTNode *insert_node_to_tree(BiTNode *t,ElemType e);


//先序遍历二叉树
void pre_order(BiTNode *t);
void mid_order(BiTNode *t);
void last_order(BiTNode *t);

#endif




