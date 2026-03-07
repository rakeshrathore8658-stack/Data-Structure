#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void queueAtB(int x);
void queueAtE(int x);
int dequeueAtB();
int dequeueAtE();
void showAll();
bool isEmpty();

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;

void queueAtB(int x)
{
    struct Node *temp=malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        printf("No space \n");
        return;
    }
    temp->data = x;
    temp->next = front;
    if(front == NULL)
    {
      front = rear=temp ;
    }
    front = temp;
}

void queueAtE(int x)
{
    if (front == NULL)
    {
        queueAtB(x);
        return;
    }
  
    struct Node *temp=malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    rear=rear ->next = temp;
}

int dequeueAtB()
{
    if(isEmpty())
    {
        printf("Queue is empty \n");
        exit(0);
    }
    struct Node *temp=front;
    front=front->next;
    int x=temp->data;
    free(temp);
    return x;
}

int dequeueAtE()
{
    int x;
    if(front == NULL || front->next ==NULL)
    {
        x = dequeueAtB(x);
        return x;
    }
    struct Node *temp = front;
    struct Node *temp2 = front;
    while(temp ->next != NULL)
    {
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    rear=temp2;
    x= temp->data;
    free(temp);
    return x;
}


void showAll()
{
	if(isEmpty())
    {
        printf("Queue is empty \n");
        return;
    }
    struct Node *temp = front;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	
}

bool isEmpty()
{
	if(front==NULL)
		return true;
	return false;
}
void main()
{
	queueAtB(10);
	queueAtB(10);
	queueAtE(20);
	queueAtE(30);
	queueAtE(40);
	queueAtE(50);
	showAll();
	printf("----------\n");
	showAll();
	printf("----------\n");
	printf("%d\n",dequeueAtB());
	printf("%d\n",dequeueAtE());
	//dequeueAtE();
	printf("----------\n");
	showAll();
}




/*
output:-
  10
  10
  20
  30
  40
  50
  ----------
  10
  10
  20
  30
  40
  50
  ----------
  10
  50
  ----------
  10
  20
  30
  40

*/
