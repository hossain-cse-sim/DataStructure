#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//Globally Declaration
int queue_arr[MAX];
int F=-1,R=-1;

void enqueue(int data)
{
 if(R==MAX-1)
 {
 printf("Queue Overflow\n");
 return;
 }
 if(F==-1 && R==-1)
 {
 F=0;
 R=0;
 queue_arr[R]=data;
 }
 else
 {
 R++;
 queue_arr[R]=data;
 }
}

int dequeue()
{
 if(F==R)
 {
 printf("Queue Underflow\n");
 return -1;
 }
 else
 {
 F++;
 }
}

void print()
{
 if(F==-1)
 printf("Queue is empty\n");
 else
 for(int i=F;i<=R;i++)
 {
 printf("%d ",queue_arr[i]);
 }
}

int main() {
 printf("After Enqueue:");
 enqueue(2);
 enqueue(3);
 enqueue(4);
 print();
 printf("\n");
 printf("After Dequeue:");
 dequeue();
 dequeue();
 print();
 printf("\n");
 return 0;
}