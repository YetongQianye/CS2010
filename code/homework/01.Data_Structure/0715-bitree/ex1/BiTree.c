#include"BiTree.h"

/*
create_tree_by_str:根据用户输入的字符串,建立一颗二叉树
返回值:
返回建立的二叉树的根节点的指针
*/

BiTNode *create_tree_by_str(const char *str)
{
    BiTNode *root = NULL;   //创建一棵空树
    BiTNode *pi = NULL;     //指向新创建的节点

    while(*str)
    {
        pi = (BiTNode *)malloc(sizeof(BiTNode));
        pi->data = *str++;
        pi->lchild =pi->rchild = NULL;
        
        //把创建的结点插入二叉排序树
        if (root = NULL)
        {
            root = pi;

        }
        else
        {
            //找插入位置(遍历root表示的二叉树,找到一个合适的位置)
			//pi成为查找路径上面最后一个结点的左子或者右子
			//pr记录查找路径上面最后一个结点的指针
            BiTNode *p = root;//遍历使用的指针
            BiTNode *pr = root;//遍历使用的指针

            while(p)
            {
                if(p->data < pi->data)
                {
                    pr = p;
                    p = p->rchild;
                }
                else if(p->data > pi->data)
                {
                    pr = p;
                    p = p->lchild;
                }
                else
                {
                    free(pi);
                    break;
                }
                
            }
            //p肯定为NULL,pr指向路径上面最后一个结点
			//pi放到p的位置
			if(pi->data > pr->data)
			{
				pr->rchild = pi;
			}else if(pi->data < pr->data)
			{
				pr->lchild = pi;
			}

        }
        
    }
    return root;
}

BiTNode *insert_node_to_tree(BiTNode *t,ElemType e)
{
    pi = (BiTNode *)malloc(sizeof(BiTNode));
    pi->data = *str++;
    pi->lchild =pi->rchild = NULL;
    
    //把创建的结点插入二叉排序树
    if (t = NULL)
    {
        t = pi;

    }
    else
    {
        //找插入位置(遍历root表示的二叉树,找到一个合适的位置)
        //pi成为查找路径上面最后一个结点的左子或者右子
        //pr记录查找路径上面最后一个结点的指针
        BiTNode *p = root;//遍历使用的指针
        BiTNode *pr = root;//遍历使用的指针

        while(p)
        {
            if(p->data < pi->data)
            {
                pr = p;
                p = p->rchild;
            }
            else if(p->data > pi->data)
            {
                pr = p;
                p = p->lchild;
            }
            else
            {
                free(pi);
                break;
            }
            
        }
        //p肯定为NULL,pr指向路径上面最后一个结点
        //pi放到p的位置
        if(pi->data > pr->data)
        {
            pr->rchild = pi;
        }else if(pi->data < pr->data)
        {
            pr->lchild = pi;
        }

        }
}