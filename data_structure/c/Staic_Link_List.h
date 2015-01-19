#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define OK 1       /*结果状态*/
#define ERROR 0    /*结果状态*/
#define TRUE 1     /*结果状态*/
#define FALSE 0    /*结果状态*/
#define MAXSIZE 1000        /*定义静态链表最大长度*/
typedef int Status;         /*函数类型，值为函数结果状态代码*/
typedef int ElemType;       /*静态链表数据元素类型*/

typedef struct              /*定义静态链表存储结构*/
{
	ElemType data;          /*数据域data存放数据元素*/
	int cur;                /*数据域游标cur存放后继在数组中的下标,0表示无指向*/
}Component,StaticLinkList[MAXSIZE];

/*初始化静态链表*/
Status StaticLinkListInit(StaticLinkList *L)
{
	for(int i = 0; i <(MAXSIZE - 1); i++)
	{
		(*L)[i].cur = i + 1;
	}
	(*L)[MAXSIZE - 1].cur = 0;
	return OK;
}
/*从备用链表申请结点并返回相应结点的下标，若备用链表为空则返回0值*/
int Malloc_SLL(StaticLinkList *L)
{
	int i = (*L)[0].cur;
	if(0 != (*L)[0].cur)
	{
		(*L)[0].cur = (*L)[i].cur;
		return i;
	}
	else
	{
		return 0;
	}
}
/*将下标为k的空闲结点回收到备用链表*/
void Free_SLL(StaticLinkList *L, int k)
{
	(*L)[k].cur = (*L)[0].cur;
	(*L)[0].cur = k;
}
/*返回静态链表L中数据元素的个数*/
int StaticLinkListLength(StaticLinkList *L)
{
	int k = (*L)[MAXSIZE - 1].cur;
	int j = 0;
	while(0 != k)
	{
		k = (*L)[k].cur;
		j++;
	}
	return j;
}
/*在静态链表L的第i个元素之前插入新的元素e*/
Status StaticLinkListInsert(StaticLinkList *L, int i, ElemType *e)
{
	if(i < 1 || i > StaticLinkListLength(L))   /*插入位置不符合要求*/
	{
		printf("Number I failed");
		return ERROR;
	}
	int k = MAXSIZE - 1;
	int j = Malloc_SLL(L);
	if(0 != j)
	{
		(*L)[j].data = *e;
		for(int l = 1; l < i; l++)
		{
			k = (*L)[k].cur;           /*第i-1个元素的下标*/
		}
		(*L)[j].cur = (*L)[k].cur;
		(*L)[k].cur = j;
		printf("StaticLinkListInsert OK");
		return OK;
	}
	else //if(0 == j)
	{
		printf("StaticLinkListInsert ERROR");
		return ERROR;
	}
}
/*删除在静态链表L的第i个元素并返回给e*/
Status StaticLinkListDelete(StaticLinkList *L, int i, ElemType *e)
{
	if(i < 1 || i > StaticLinkListLength(L))
	{
		printf("Number I failed");
		return ERROR;
	}
	int k = MAXSIZE-1; 
	for(int l = 1; l < i; l++)
	{
		k = (*L)[k].cur;           /*第i-1个元素的下标*/
	}
	*e = (*L)[k].data;
	int j = (*L)[k].cur;
	(*L)[k].cur = (*L)[j].cur;
	Free_SLL(L,j);
	printf("StaticLinkListDelete OK");
	return OK;
}