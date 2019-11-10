#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *pNext;
}NODE,*PNODE;
PNODE creat_list();
int traverse_list(PNODE pHead);
int daoxu_list(PNODE pHead);
int len_list(PNODE pHead);
int main()
{
	int val; 
	
	PNODE pHead = (PNODE)malloc(sizeof(PNODE));
	pHead = creat_list();
	traverse_list(pHead);
	len_list(pHead);
	daoxu_list(pHead);
	traverse_list(pHead);
	return 0;
} 
PNODE creat_list()
{
    int len;
	scanf("%d",&len);
	PNODE pHead = (PNODE)malloc(sizeof(PNODE));
	PNODE pTail = pHead;
	int val;
	for(int i=0;i<len;i++)
	{
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = val;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew; 
		//printf("%d",pNew->data);
	}
	return pHead; 

}
int traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(pHead!=NULL)
	{
		printf("%d",pHead->pNext->data);
		pHead = pHead->pNext;
	}
	
}
int daoxu_list(PNODE pHead)
{
	int i,j,t;
	PNODE p,q;
	int len = len_list(pHead);
	for(i=0,p = pHead->pNext;i<len;i++,p=p->pNext)
	{
		
		for(j=0,q = p->pNext;j<len-i-1;j++,q=q->pNext)
		{
			if(p->data<q->data)
			{
				t = q->data;
				q->data = p->data;
				p->data = t;
			} 
		}
		
	}
printf("ksjnmg");
}
int len_list(PNODE pHead)
{
	int i=0;
	PNODE p = pHead->pNext;
	while(p->data!=0)
	{
		i=i+1;
		p = p->pNext; 
	} 
	return i;
	printf("%d",i);
}
