//InsertAtB()  
#include<stdio.h>
#include<stdlib.h>
struct Node *start = NULL;
void insertAtB(int x);
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
void main()
{
  insertAtB(10);
  insertAtB(20);
  insertAtB(30);
  insertAtB(40);
  insertAtB(50);
  showALL();
}
