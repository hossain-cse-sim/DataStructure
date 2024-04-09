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

 struct node *temp;
 temp=head;

 struct node *mid;
 mid=malloc(sizeof(struct node));    //node for insert data at any position
 mid->data=40;
 mid->next=NULL;

 int pos,i=1;
 printf("Enter position:");
 scanf("%d",&pos);

 while(i<pos-1)
 {
 temp=temp->next;
 i++;
 }
 mid->next=temp->next;
 temp->next=mid;
 temp=head;

 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->next;
 }

     return 0;
}