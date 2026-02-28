#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *start = NULL;
struct Node *end = NULL;
void insertAtE(int x);
void insertAtB(int x);
void showAll2();
void showAll3(int x);
void showAll4(int x);

struct Node* cn(int x)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    return temp;
}

void insertAtB(int x)
{
    struct Node *temp = cn(x);

    if(start == NULL)
    {
        start = temp;
        end = temp;

        start->next = start;
        start->prev = start;

        return;
    }

    temp->next = start;
    temp->prev = end;

    start->prev = temp;
    end->next = temp;

    start = temp;
}


void insertAtE(int x)
{
        if(start==NULL)
        {
                insertAtB(x);
                return;
        }
        struct Node *temp =cn(x);

        temp->next=start;
        temp->prev=end;
        end->next=temp;
        start->prev=temp;
        end=temp;

}

void showAll()
{
    if(start == NULL)
    {
        printf("List is Empty..\n");
        return;
    }

    struct Node *temp = start;

    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    while(temp != start); 
}


void showAll2()  // reverse direction me print
{
    if(start == NULL)
    {
        printf("List is Empty..\n");
        return;
    }

    struct Node *temp = end;

    do
    {
        printf("%d\n", temp->data);
        temp = temp->prev;
    }while(temp != end); 
}

void showAll3(int x)
{
        struct Node *temp =start;
        while(temp->data!=x)
        {
                temp=temp->next;
                if(temp==start)
                {
                        printf("No Element found..\n");
                        return;
                }
        }
        struct Node *temp2=temp;

        do
        {
                printf("%d \n", temp->data);
                temp=temp->next;
        }
        while(temp!=temp2);
}


void showAll4(int x)
{
        struct Node *temp =start;
        while(temp->data!=x)
        {
                temp=temp->next;
                if(temp==start)
                {
                        printf("No Element found..\n");
                        return;
                }
        }

        struct Node *temp2=temp;

        do
        {
                printf("%d \n", temp->data);
                temp=temp->prev;
        }
        while(temp!=temp2);
}



void main()
{
    insertAtE(10);
    insertAtE(20);
    insertAtE(30);
    insertAtE(40);
    insertAtE(50);
    showAll();
        printf("-----\n");
    showAll4(30);
    showAll4(30);

}