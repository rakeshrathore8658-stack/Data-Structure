
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void push(int x);
int pop();
int peek();
bool isEmpty();
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top= NULL;

bool isEmpty()
{
    if(top == NULL)
    return true;
    return false;
}

void push(int x)
{
    struct Node *temp=malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        printf("No sapce\n");
        return;
    }
    temp->data = x;
    temp->next=top;
    top=temp;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    struct Node *temp =top;
    top=top->next;
    int x= temp->data;
    free(temp);
    
    return x;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        exit(0);
    }
    return top->data;
}



void main() 
{
push(10);
push(20);
push(70);
printf("%d \n", pop());
printf("%d \n", pop());
printf("%d \n", peek());
printf("%d \n", peek());
}

