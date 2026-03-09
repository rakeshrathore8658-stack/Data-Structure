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

int findMax()
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    struct Node *temp = start;
    int max = temp->data;

    while(temp != NULL)
    {
        if(temp->data > max)
        {
            max = temp->data;
        }

        temp = temp->next;
    }

    return max;
}

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
    insertAtB(25);
    insertAtB(5);
    insertAtB(40);
    insertAtB(105);

    showAll();

    int m = findMax();
    printf("Maximum number = %d\n", m);
}