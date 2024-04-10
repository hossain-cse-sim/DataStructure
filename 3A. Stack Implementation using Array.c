#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//Globally Declaration
int stack_arr[MAX];
int top=-1;

void push(int data)
{
 if(top==MAX-1)
 {
 printf("Stack Overflow.\n");
 return;
 }
 top++;
 stack_arr[top]=data;
}

int pop()
{
 if(top==-1)
 {
 printf("Stack Underflow.\n");
 return -1;
 }
 int val;
 val=stack_arr[top];
 top--;
 return val;
}

void print()
{
 if (top==-1) {
 printf("Stack is empty.\n");
 return;
 }
 printf("Stack elements: ");
 for (int i=0;i<=top;i++) {
 printf("%d ",stack_arr[i]);
 }
 printf("\n");
}

int main()
{
 int choice , data;

 while(1)
 {
 printf("1.Push\n");
 printf("2.Pop\n");
 printf("3.Print\n");
 printf("4.Exit\n");
 printf("Enter your choice:");
 scanf("%d",&choice);

 switch(choice)
 {
 case 1:
 printf("Enter data to be pushed:");
 scanf("%d",&data);
 push(data);
 print();
 break;

 case 2:
 pop();
 print();
 break;

 case 3:
 print();
 break;

 case 4:
 exit(0);
 return 0;
 break;

 default:
 printf("Wrong Choice.\n");
 break;
 }
 }
 return 0;
}