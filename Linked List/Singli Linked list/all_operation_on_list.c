// Singli Linked List delet at begining 
// delete at ending 

#include<stdio.h>
#include<stdlib.h>
void deleteAtB();
void deleteAtE();
void deleteAtSP(int p);
void showAll();
void insertAtSP(int p,int x);
int countNode();
void insertAtE(int x);


struct Node
{
        int data;
        struct Node *next;
};
struct Node *start=NULL;

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

void insertAtSP(int p,int x)
{
    if(p<=1)
    {
        insertAtB(x);
        return;
    }
    if(p>countNode())
    {
        insertAtE(x);
        return;
    }
    struct Node *temp=malloc(sizeof(struct Node));
    temp->data=x;
    int i;
    struct Node *temp1=start;
    for(i=1;i<p-1;i++)
    {
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
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

void deleteAtSP(int p)
{
    if(start == NULL)
    {
        printf("List is Empty..\n");
        return;
    }

    if(p <= 1)
    {
        deleteAtB();
        return;
    }

    if(p >= countNode())
    {
        deleteAtE();
        return;
    }
    struct Node *temp1 = start;
    struct Node *temp2;
    int i;
    for(i = 1; i < p - 1; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;          
    temp1->next = temp2->next;    
    free(temp2);                 
}

int countNode()
{
    int c=0;
    struct Node *temp=start;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void Display(struct Node *temp)
{
	if(temp==NULL) return;
	printf("%d \n",temp->data);
	Display(temp->next);
}


void revDisplay(struct Node *temp)
{
	if(temp==NULL) return;
	revDisplay(temp->next);
	printf("%d \n",temp->data);
}

void main()
{
        insertAtE(10);
        insertAtE(20);
        insertAtE(30);
        insertAtE(40);
        insertAtE(50);
        showAll();
        printf("--------1--rev------\n");
		revDisplay(start);
        printf("--------1--------\n");
        insertAtSP(2,55);
        showAll();
        printf("--------2--------\n");
        deleteAtSP(2);
        showAll();
        printf("--------3--------\n");
        deleteAtSP(3);
        showAll();
        printf("--------4------\n");
}
