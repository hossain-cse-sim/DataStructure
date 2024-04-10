#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *prev;
 int data;
 struct node *next;
};

int main()
{
 struct node *head;
 head=malloc(sizeof(struct node));
 head->prev=NULL;
 head->data=5;
 head->next=NULL;

 struct node *second;
 second=malloc(sizeof(struct node));
 second->prev=head;
 second->data=10;
 second->next=NULL;
 head->next=second;

 struct node *third;
 third=malloc(sizeof(struct node));
 third->prev=second;
 third->data=15;
 third->next=NULL;
 second->next=third;

 struct node *begin;
 begin=malloc(sizeof(struct node));
 begin->prev=NULL;
 begin->data=2;
 begin->next=head;
 head->prev=begin;
 
 head=begin;
 struct node *temp;
 temp=head;
 while(temp!=NULL)
 {

 printf("%d ",temp->data);
 temp=temp->next;
 }
  return 0;
}