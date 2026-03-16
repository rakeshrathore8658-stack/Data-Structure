
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 5
int Queue[SIZE];
void enqueue(int);
int dequeue();
void showAll();
bool isFull();
bool isEmpty();
int peek();
int rear=-1;
int front=-1;
void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	showAll();
		
}
void enqueue(int x)
{
	if(isFull())
	{
		printf("Queue is full\n");
		return;
	}
	if(front==-1)front++;
	rear=(rear+1)%SIZE;
    Queue[rear] = x;
}
int dequeue()
{
    if(isEmpty())
    {
        printf("Queue empty\n");
        exit(0);
    }
	int i=Queue[front];
	if(front==rear)front=rear=-1;
	else
	front=(front+1)%SIZE;
	return i;
}
int peek()
{
	return Queue[front];
}
bool isFull()
{
	return (rear+1)%SIZE == front;
}
bool isEmpty()
{
	return front==-1;
}

void showAll()
{
    int i;

    if(isEmpty())
    {
        printf("Queue empty\n");
        return;
    }

    for(i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d ", Queue[i]);
    }

    printf("%d \n", Queue[i]);
}

