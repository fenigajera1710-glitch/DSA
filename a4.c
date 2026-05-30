#include<stdio.h>
#define MAX 5

int pq[MAX];
int n = 0;

void enqueue(int item){
    int i;
    if(n == MAX){
        printf("queue is full\n");
        return ;
    }

    for(i = n-1; i>=0 && pq[i]<item;i--){
        pq[i+1] = pq[i];
    }
    pq[i+1] = item;
    n++;
    printf("Inserted item :%d\n",item);
}

void dequeue(){
    int i;
    if(n == 0){
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted item:%d\n",pq[0]);
    for(i = 0; i<=n-1;i++){
        pq[i] = pq[i+1];
    }
    n--;
}

void display(){
    if(n == 0){
        printf("priority queue is empty\n");
        return ;
    }
int i;
printf("priority queue:");
    for(i=0;i<=n-1;i++){
        printf(" %d",pq[i]);
    }
    printf("\n");
}

int main(){
    enqueue(30);
    enqueue(10);
    enqueue(40);
    enqueue(5);

    display();
    dequeue();
    display();
    return 0;
}