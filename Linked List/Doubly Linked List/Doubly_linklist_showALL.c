//InsertAtE()  
#include<stdio.h>
#include<stdlib.h>
struct Node *start = NULL;
void insertAtB(int x);
void insertAtE(int x);
void showALL();
struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};


void insertAtB(int x)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if(temp==NULL)
    {
        printf("No Space");
        return;
    }
  temp -> data =x;
  temp -> prev =NULL;
  temp -> next =start;
   
  if(start != NULL)
   {
     start -> prev = temp;
   }
  start = temp;
}

// showALL All (Node data print )
void showALL()
{
  if(start == NULL)
  {
    printf("List is Empty..");
    return;
  }
  struct Node *temp=start; // treversing Node
  while(temp != NULL)
    {
        printf("%d\n",temp-> data);
      temp = temp -> next;
    }
}

void insertAtE(int x)
{
    if(start == NULL)
    {
        insertAtB(x);
        return;
    }
     struct Node *temp = malloc(sizeof(struct Node));
     temp -> data = x ;
     temp -> next =NULL ;
     
     struct Node *temp1 = start; // traversing Node
     
     while(temp1->next != NULL)
     {
         temp1 = temp1 -> next;
     }
     temp1 -> next = temp;
     temp -> prev  = temp1;
}
void main()
{
  insertAtB(10);
  insertAtB(20);
  insertAtE(30);
  insertAtE(40);
  insertAtE(50);
  showALL();
}
