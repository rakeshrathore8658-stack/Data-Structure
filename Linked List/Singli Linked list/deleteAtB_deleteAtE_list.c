// Singli Linked List delet at begining 
// delete at ending 

#include<stdio.h>
#include<stdlib.h>
void deleteAtB();
void deleteAtE();
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


void deleteAtB()
{
    if(start == NULL)
    {
        printf("List is Empty..");
        return;
    }
    struct Node *temp = start;
    start= start-> next;
    free(temp);
}

/*
void deleteAtE()
{
    if(start == NULL || start->next == NULL)
    {
        deleteAtB();
        return;
    }
    
    struct Node *temp1 = start;
    while(temp1->next->next != NULL)
    {
        temp1= temp1->next;
    }
    free(temp1->next);
    temp1->next = NULL;
}
*/

// second approach for deleteAtE()
void deleteAtE()
{
    if(start == NULL || start->next == NULL)
    {
        deleteAtB();
        return;
    }
    
    struct Node *temp1= start;
    struct Node *temp2=start;
    
    while(temp1-> next!= NULL)
    {
        temp2= temp1;
        temp1= temp1->next;
    }
    temp2->next=NULL;
    free(temp1);
}


void main()
{
        insertAtE(10);
        insertAtE(20);
        insertAtE(30);
        insertAtE(40);
        insertAtE(50);
        showAll();
        printf("----------------\n");
        deleteAtB();
        deleteAtE();
        showAll();
}

