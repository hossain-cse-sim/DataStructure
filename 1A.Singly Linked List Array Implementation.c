#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
int main()
{
 struct node *head=NULL,*current,*temp;
 int n;
 printf("Enter size: ");
 scanf("%d",&n);

 int a[n],i;
 printf("Enter data: ");

 for(i=1;i<=n;i++)
 {
 scanf("%d",&a[i]);
 }

 for(i=1;i<=n;i++)
 {
 current=malloc(sizeof(struct node));
 current->data=a[i];
 current->next=NULL;

 if(head==NULL)
 {
 head=current;
 temp=current;
 }
 else
 {
 temp->next=current;
 temp=current;
 }
 }

 temp=head;
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->next;
 }
 
    return 0;
}