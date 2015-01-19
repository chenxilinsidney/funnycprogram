#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define OK 1       /*结果状态*/
#define ERROR 0    /*结果状态*/
#define TRUE 1     /*结果状态*/
#define FALSE 0    /*结果状态*/
typedef int Status;/*函数类型，值为函数结果状态代码*/
typedef int ElemType;/*单链表数据元素类型*/

typedef struct Node  /*定义结点*/
{
	ElemType data;   /*单链表存储结构数据域*/
	struct Node *next; /*单链表存储结构指针域*/
}Node;
typedef Node *LinkList;/*定义单链表*/


/*随机产生n个元素的值，建立带头结点的单链表L,头插法*/
Status CreateLinkListHead(LinkList *L,int n)
{
	LinkList p;
	srand((unsigned int)time(0));                       /*初始化随机数种子*/
	*L = (LinkList)malloc(sizeof(Node));  /*建立一个带头结点的单链表，申请内存空间*/
	(*L)->data = n;                       /*建立一个带头结点的单链表，头结点数据域存储单链表长度附加信息*/
	(*L)->next = NULL;                    /*建立一个带头结点的单链表，头结点指针域初始化为NULL*/
	for(int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*建立一个新结点，申请内存空间*/
		p->data = rand()%100 + 1;           /*随机生成1～100的数字*/
		p->next = (*L)->next;               /*把新的结点插入头结点与前一新结点之间，即新结点始终在头结点之后*/
		(*L)->next = p;                     /*把新结点的地址复制到头结点的指针域*/
	}
	return OK;
}
/*随机产生n个元素的值，建立带头结点的单链表L,尾插法*/
Status CreateLinkListTail(LinkList *L, int n)
{
	LinkList p,r;
	srand((unsigned int)time(0));                       /*初始化随机数种子*/
	*L = (LinkList)malloc(sizeof(Node));  /*建立一个带头结点的单链表，申请内存空间*/
	r = *L;                               /*r为指向尾部的结点*/
	for(int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*建立一个新结点，申请内存空间*/
		p->data = rand()%100 + 1;           /*随机生成1～100的数字*/
		r->next = p;                        /*将表尾终端结点的指针指向新结点*/
		r = p;                              /*将当前的新结点定义为表尾终端结点*/
	}
	r->next = NULL;                         /*表示单链表结束*/
	return OK;
}
/*将L置为空表*/
Status ClearLinkList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;     /*p指向第一个结点*/
	while(NULL != p)
	{
		q = p->next;    /*保存下一结点地址*/
		free(p);        /*释放结点*/
		p = q;          /*更新需要释放的结点地址*/
	}
	(*L)->next = NULL;     /*置头结点指针域为空*/
	return OK;
}
/*用e返回单链表L的第i个数据元素的值,i不含头结点*/
Status GetElem(LinkList *L, int i, ElemType *e)
{
	int j = 1;  
	LinkList p;   
	p = (*L)->next;            /*让P指向单链表的第一个结点*/
	while(j < i && p != NULL)  /*p指向单链表第i个结点*/
	{
		p = p->next;    /*让P指向下一个结点*/
		j++;
	}
	if(p == NULL || j > i)
	{
		printf("GetElem ERROR!\n");
		return ERROR;
	}
	else
	{
		*e = p->data;     /*第i个结点的数据域*/
		return OK;
	}
}

/*在L中的第i个位置之前插入新的数据元素e*/
Status LinkListInsert(LinkList *L, int i, ElemType *e)
{
	int j = 1;
	LinkList p,s;
	p = (*L);                      /*p始终指向第(i-1)个结点或头结点*/
	while(NULL != p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if( NULL == p->next || j > i)
	{
		printf("LinkListInsert ERROR!\n");
		return ERROR;
	}
	else
	{
		s = (LinkList)malloc(sizeof(Node));
		s->data = *e;
		s->next = p->next;
		p->next = s;
		printf("LinkListInsert OK!:%d\n",s->data);
		return OK;
	}
}
/*删除L的第i个数据元素，并用e返回其值*/
Status LinkListDelete(LinkList *L, int i, ElemType *e)
{
	int j = 1;
	LinkList p,q;
	p = *L ;                /*p始终指向第(i-1)个结点或头结点*/
	while(NULL != p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if(NULL == p->next || j > i)
	{
		printf("LinkListDelete ERROR!\n");
		return ERROR;
	}
	else
	{
		q = p->next;
		p->next = q->next;
		*e = q->data;
		free(q);
		printf("LinkListDelete OK!:%d\n",*e);
		return OK;
	}
}
