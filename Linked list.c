// Singli Linked List 
// Singli Linklist 

#include<stdio.h>
#include<stdlib.h>
struct Node *start=NULL;
void showAll();
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


void main()
{
	insertAtB(10);  
	insertAtB(20);
	insertAtB(30);
	insertAtB(40);
	insertAtB(50);
	showAll();
	printf("\nFor Ending : -> \n");
	
	insertAtE(10);
	insertAtE(20);
	insertAtE(30);
	insertAtE(40);
	insertAtE(50);
	showAll();
	
}

