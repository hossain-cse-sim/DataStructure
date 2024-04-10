#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *F = NULL;
struct node *R = NULL;

void enqueue(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    if (F == NULL && R == NULL) {
        F = R = temp;
        return;
    }
    
    R->link = temp;
    R = temp;
}

int dequeue() {
    if (F == NULL)
        return -1;
    
    struct node *temp = F;
    int deq = temp->data;
    
    if (F == R) {
        F = R = NULL;
    } else {
        F = F->link;
    }
    
    free(temp);
    return deq;
}

void print() {
    struct node *ptr = F;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("\n");
    print();
    printf("\n");
    dequeue();
    dequeue();
    print();
    return 0;
}
