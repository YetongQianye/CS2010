//
// Created by Joe on 2020/8/21.
//

#include "Linklist.h"

/*
create_list:创建一个带头节点的双向链表
返回值:返回头结点的指针
*/
Head *create_list()
{
    Head *l = (Head *)malloc(sizeof(*l));
    l->first = l->last = NULL;
    l->num = 0;
    return l;
}



//往带头节点双向链表中插入元素(头插法,尾插法,有序)
void add_Elem_to_list(Head *l,ElemType x)
{
    //创建一个数据结点,保存x
    Node *p = (Node *)malloc(sizeof(*p));
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    //把结点加入链表
    if(l->first == NULL)
    {
        l->first = p;
        l->last = p;
    }else
    {
        //头插法
        //p->next=l->first;
        //l->first->prev = p;
        //l->first = p;

        //尾插法
        l->last->next = p;
        p->prev = l->last;
        l->last = p;
        /*
        //建立有序(升序)链表
        //找插入位置,找到第一个比待插入元素大的那个结点px
        Node *px = l->first;
        while(px)
        {
            if(px->data > p->data)
            {
                break;
            }
            px = px->next;
        }
        //分情况加入链表
        if(px == l->first) //待插入结点p比所有结点都小 头插法
        {
            p->next=l->first;
            l->first->prev = p;
            l->first = p;
        }else if(px == NULL) //待插入结点p比所有结点都大 尾插法
        {
            l->last->next = p;
            p->prev = l->last;
            l->last = p;
        }else //中间
        {
            p->next = px;
            p->prev = px->prev;
            px->prev->next = p;
            px->prev = p;
        }
        */
    }
    l->num++;
}

//打印一个带头节点的双向链表
void print_list(Head *l)
{
    if(l == NULL)
    {
        return ;
    }
    printf("list_num = %d\n",l->num);
    printf("list:");
    Node *p = l->first;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");

    printf("list_reverse:");
    p = l->last;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->prev;
    }
    printf("\n");
}


//清空链表(释放所有数据结点)
void clear_list(Head *l)
{
    if(l == NULL)
    {
        return;
    }
    Node *p = l->first;
    while(p)
    {
        //把p从原链表取下来
        l->first = p->next;
        p->next = NULL;
        if(l->first)
        {
            l->first->prev = NULL;
        }
        free(p);
        //取下一个
        p = l->first;
    }
    l->last = NULL;
    l->num = 0;
}

//删除链表(先释放所有数据结点,再释放头结点)
void delete_list(Head *l)
{
    //先清空链表
    clear_list(l);
    free(l);
}


//查找x
//返回找到的结点的指针,如果不存在,返回NULL
Node *find_x(Head *l,ElemType x)
{
    if(l == NULL)
    {
        return NULL;
    }
    Node *p = l->first;
    while(p)
    {
        if(p->data == x)
        {
            break;
        }
        p = p->next;
    }
    return p;
}


//删除指定的x
void delete_x(Head *l,ElemType x)
{
    if(l == NULL)
    {
        return;
    }
    //找到要删除的结点px
    Node *px = l->first;
    while(px)
    {
        if(px->data == x)
        {
            break;
        }
        px = px->next;
    }
    //链表中没有要删除的x
    if(px == NULL)
    {
        return;
    }
    //分情况删除,分三种情况,
    //px == l->first;
    //px == l->last;
    //删除中间结点
    if(px == l->first) //要删除的结点是第一个结点
    {
        l->first = px->next; //NULL
        px->next = NULL;
        if(l->first)
        {
            l->first->prev = NULL;
        }else //仅仅只有一个结点
        {
            l->last = NULL;
        }
        free(px);
    }else if(px == l->last)//要删除的结点是最后一个结点
    {
        l->last = px->prev;
        l->last->next = NULL;
        px->prev = NULL;
        free(px);
    }else //要删除的是中间结点
    {
        px->prev->next = px->next;
        px->next->prev = px->prev;
        px->next = NULL;
        px->prev = NULL;
        free(px);
    }
    l->num--;
}



//删除所有的x
void delete_all_x(Head *l,ElemType x)
{
    if(l == NULL)
    {
        return;
    }
    Node *flag = l->first;
    while(1)
    {
        //找到要删除的结点px
        Node *px = flag;
        while(px)
        {
            if(px->data == x)
            {
                flag = px->next;
                break;
            }
            px = px->next;
        }
        //链表中没有要删除的x
        if(px == NULL)
        {
            return;
        }
        //分情况删除,分三种情况,
        //px == l->first;
        //px == l->last;
        //删除中间结点
        if(px == l->first) //要删除的结点是第一个结点
        {
            l->first = px->next; //NULL
            px->next = NULL;
            if(l->first)
            {
                l->first->prev = NULL;
            }else //仅仅只有一个结点
            {
                l->last = NULL;
            }
            free(px);
        }else if(px == l->last)//要删除的结点是最后一个结点
        {
            l->last = px->prev;
            l->last->next = NULL;
            px->prev = NULL;
            free(px);
        }else //要删除的是中间结点
        {
            px->prev->next = px->next;
            px->next->prev = px->prev;
            px->next = NULL;
            px->prev = NULL;
            free(px);
        }
        l->num--;
    }
}














