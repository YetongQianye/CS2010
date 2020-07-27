#ifndef __BITREE_H__
#define __BITREE_H__


typedef int TElemType; //树中结点元素的数据类型
		
typedef struct biNode
{
	TElemType data; //
	
	struct biNode *lchild; // 保存左子结点的指针 "left"
	struct biNode *rchild; //保存右子结点的指针  "right"
	

}biNode;



#endif
