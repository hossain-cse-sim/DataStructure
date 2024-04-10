#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};

int main()
{
 struct node *head;
 head=malloc(sizeof(struct node));
 head->data=10;
 head->next=NULL;

 struct node *second;
 second=malloc(sizeof(struct node));
 second->data=15;
 second->next=NULL;
 head->next=second;

 struct node *third;
 third=malloc(sizeof(struct node));
 third->data=20;
 third->next=NULL;
 second->next=third;

 struct node *temp,*prev;
 temp=head;
 while(temp->next!=NULL)
 {
 prev=temp;           //delete node at last 
 temp=temp->next;
 }
 prev->next=NULL;
 free(temp);

 temp=head;
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->next;
 }

 return 0;
}