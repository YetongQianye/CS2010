#ifndef __BI_TREE_H__
#define __BI_TREE_H__

#include<stdio.h>
#include<stdlib.h>
#include"SqQueue.h"


//类型的定义和函数的声明
typedef int TElemType; //二叉树中用户数据类型为int
//二叉树的结点类型
typedef struct BiTNode
{
	TElemType data;//用户数据类型
	struct BiTNode *lchild; //指向它的左子结点
	struct BiTNode *rchild;//指向它的右子结点
	int h;//记录本身结点在二叉树中的高度
}BiTNode;

//有bug,不能处理MAX(i++,j++);
#define MAX(a,b) ((a)>(b)?(a):(b))

//把元素e插入到t表示的平衡二叉树中,使二叉树任然具有平衡性
BiTNode *insert_node_to_AVLtree(BiTNode *t,TElemType x);


//先序遍历二叉树
void pre_order(BiTNode *t);

//中序遍历二叉树
void mid_order(BiTNode *t);

//后序遍历二叉树
void last_order(BiTNode *t);

//层次遍历t表示的二叉树
void level_order(BiTNode *t);

//求二叉树的高度
int hight_tree(BiTNode *t);


//对k进行单向左旋平衡处理
//返回值:返回左旋后的树的根节点
BiTNode *SingleRotateWithLeft(BiTNode *k);


//对k进行单向右旋平衡处理
//返回值:返回右旋后的树的根节点
BiTNode *SingleRotateWithRight(BiTNode *k);


//对k进行双向旋转(先左后右)平衡处理
//返回值:返回旋转后的树的根节点
BiTNode *DoubleRotateWithLeftRight(BiTNode *k);


//对k进行双向旋转(先右后左)平衡处理
//返回值:返回旋转后的树的根节点
BiTNode *DoubleRotateWithRightLeft(BiTNode *k);


#endif




