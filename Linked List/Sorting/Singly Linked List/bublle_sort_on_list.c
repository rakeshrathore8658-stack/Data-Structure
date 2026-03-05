
#include<stdio.h>
#include<stdlib.h>
struct Node *start=NULL;
void showAll();
void sort();
void insertAtE(int x);
struct Node
{
	int data;
	struct Node *next;
};

void insertAtB(int x)
{
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp == NULL) 
	{
		printf("No Space\n");
		return;
	}
	temp -> data=x;
	temp -> next = start;
	start = temp;
}

void showAll()
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct Node *temp1=start;
	
	while(temp1!=NULL)
	{
		printf("%d \n",temp1 -> data);
		temp1=temp1 ->next;
	}
}

void insertAtE(int x)
{
	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node *temp=malloc(sizeof(struct Node));
	
	temp -> data=x;
	temp -> next=NULL;
	struct Node *temp1 =start;
	while(temp1 -> next!=NULL)
	{
		temp1 =temp1 ->next;
	}
		temp1 ->next = temp;
	
	
}

void sort()
{
	struct Node *p=start;
	struct Node *q;
	struct Node *temp=NULL;
	int t;
	while(temp != start->next)
	{
		for( p=start ; p->next != temp ; p= p->next )
		{
			q=p->next;
			if( p-> data > q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
		temp = q;
	}	
}

void main()
{
	insertAtB(10);  
	insertAtB(20);
	insertAtB(30);
	insertAtB(40);
	insertAtB(50);
	showAll();
	printf(" After Sorting => \n");
	sort();
	showAll();
	
}
