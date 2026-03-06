
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void queue(int x);
int dequeue();
int peek();
bool isEmpty();
void showAll();

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front= NULL;
struct Node *rear= NULL;

bool isEmpty()
{
    if(front == NULL)
		return true;
    return false;
}

void queue(int x)
{
    struct Node *temp=malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        printf("No sapce\n");
        return;
    }
    temp->data = x;
	temp->next =NULL;
	if(front == NULL)
	{
		front=rear=temp;
		return;
	}
	rear=rear->next=temp;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    struct Node *temp =front;
    front=front->next;
    int x= temp->data;
    free(temp);
    
    return x;
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    return front->data;
}

void showAll()
{
	if(isEmpty())
    {
        printf("Queue is Empty\n");
        exit(0);
    }
	struct Node *temp=front;
	while(temp != NULL)
	{
		printf("%d\n",temp -> data);
		temp =temp->next;
	}
}

void main() 
{
	printf("%s\n",isEmpty()? "Queue is Empty":"Queue is not Empty");
	queue(10);
	queue(20);
	queue(30);
	queue(40);
	printf("%s\n",isEmpty()? "Queue is Empty":"Queue is not Empty");
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("-*-*-*-*-*-*-*-*-*-*-\n");
	showAll();
	printf("%d\n",peek());
	printf("%d\n",peek());
	printf("%d\n",peek());
	printf("%s\n",isEmpty()? "Queue is Empty":"Queue is not Empty");
	printf("-*-*-*-*-*-*-*-*-*-*-\n");
	showAll();
}
