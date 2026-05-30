#include<stdio.h>
#define MAX 5

int q[MAX];
int front = -1,rear = -1;

int isFull(){
    if(front == (rear+1)%MAX){
        return 1;
    }
    else
    return 0;
}

int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    else
    return 0;
}

void Enqueue(int item){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    if(front == -1)
        front ++;
        rear = (rear+1)%MAX;
    
        q[rear] = item;
        printf("inserted item :%d",q[rear]);

}

void Dequeue(){
    int item;
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    item = q[front];
    printf("deleted item :%d",q[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
    front = (front+1)%MAX;}

    
}

void Front(){
    if(isEmpty()){
        printf("QUEUQ IS EMPTY\n");
    }
    else{
        printf("front element is:%d",q[front]);
    }
}

void Rear(){
    if(isFull()){
        printf("QUEUE IS FULL\n");

    }
    else{
        printf("rear element is :%d",q[rear]);
    }
}

int main(){
    Enqueue(10);
    printf("\n");
    Enqueue(20);
    printf("\n");
    Enqueue(30);
    printf("\n");

    Front();
    printf("\n");
    Rear();
    printf("\n");

    Dequeue();
    printf("\n");
    Front();

    return 0;
}