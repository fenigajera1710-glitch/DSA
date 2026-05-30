#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int x){
    struct node *n = (struct node *)malloc(sizeof(struct node));  
    if(n == NULL){
        printf("overflow\n");
        return;
    }
     n->data = x;
     n->next = NULL;
    if(front == NULL){
        front = n;
        rear = n;
    }else{
        rear->next = n;
        rear = n;
    }
}
void dequeue(){
    if(front == NULL){
        printf("Underflow\n");
        return;
    }
    struct node *p = front;
    printf("Deleted element:%d\n",p->data);
    front = front->next;
    if(front == NULL){
        rear = NULL;
    }
    free(p);

}
void display(){
    struct node *p = front;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    while(p != NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}
int main(){
    enqueue(10);
    enqueue(50);
    enqueue(40);
    display();
    dequeue();
    display();
    return 0;  
}

