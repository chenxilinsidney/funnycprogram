#include "LinkList.h"

int main()
{
	LinkList p;
	LinkList Example;
	/*test create*/
	CreateLinkListHead(&Example,5);
	p = Example->next;
	for(int i = 0; i < 5; i++)
	{
		//printf("now addr: %d \n",(int)p);
		printf("create value: %d \n",(int)p->data);
		//printf("next addr: %d \n",(int)p->next);
		p = p->next;
	}
	/*test insert*/
	ElemType temp = 7;
	LinkListInsert(&Example,2,&temp);
	p = Example->next;
	for(int i = 0; i < 6; i++)
	{
		printf("insert 2 value: %d \n",(int)p->data);
		p = p->next;
	}
	/*test delete*/
	LinkListDelete(&Example,4,&temp);
	p = Example->next;
	printf("delete 4 value: %d \n",(int)temp);
	for(int i = 0; i < 5; i++)
	{
		printf("create value: %d \n",(int)p->data);
		p = p->next;
	}
	/*test get*/
	GetElem(&Example,3,&temp);
	printf("get 3 value: %d \n",(int)temp);
	/*test clear*/
	ClearLinkList(&Example);
	p = Example->next;
	for(int i = 0; i < 5; i++)
	{
		if(NULL != p)
		{
			printf("clear value error");
		}
	}
	return 1;
}