#include<stdio.h>
#define MAX 5

int deque[MAX];
int front = -1,rear = -1;

int isFull(){
    if((front == 0 && rear == MAX-1)||(front == rear + 1))
    return 1;
    else
    return 0;
}

int isEmpty(){
    if(front == -1 && rear == -1)
    return 1;
    else
    return 0;
}

void enqueueFront(int x){
    if(isFull()){
        printf("Deque overflow \n");
        return ;
    }
    if(isEmpty()){
        front == rear == 0; 
    }
    else if(front == 0)
        front = MAX - 1;
    else
        front--;
    deque[front] = x;
    printf("Inserted at front = %d\n",x);
}

void enqueueRear(int x){
    if(isFull()){
        printf("Deque overflow\n");
        return ;
    }
    if(isEmpty()){
        front = rear = 0; 
    }
    else if(rear == MAX-1)
        rear = 0;
    else
        rear++;
    deque[rear] = x;
    printf("Inserted at rear = %d\n",x);
}

void dequeueFront(){
    if(isEmpty()){
        printf("Deque underflow\n");
        return;
    }
    printf("Deleted from front = %d\n",deque[front]);
    if(front == rear)
        front = rear = -1;
    else if(front = MAX -1)
        front = 0;
    else
        front ++;
}

void dequeueRear(){
    if(isEmpty()){
        printf("Deque underflow\n");
        return;
    }
    printf("Deleted from front = %d\n",deque[rear]);
    if(front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = MAX -1;
    else
        rear--;
}

void getFront(){
    if(isEmpty()){
        printf("Deque is empty\n");
    }
    else{
        printf("Front element = %d\n",deque[front]);
    }
}

void getRear(){
    if(isEmpty()){
        printf("Deque is empty\n");
    }
    else{
        printf("Rear element = %d\n",deque[rear]);
    }
}

int main(){
    enqueueRear(10);
    enqueueRear(20);
    enqueueFront(5);

    getFront();
    getRear();

    dequeueFront();
    dequeueRear();
    getFront();
    getRear();

    return 0;
}
