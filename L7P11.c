#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node* next;
};

struct node* insertBeginning(struct node* start,int value){
    struct node* n =(struct node*)malloc(sizeof(struct node));
    n ->data = value;
    n ->next = start;
    start = n;
    return start;
}

void display(struct node* start){
    struct node* p = start;
    while ( p != NULL) {
        printf("%d -> ", p->data);
         p = p->next;
    }
    printf("NULL\n");
    
    
}

int main(){
    struct node* start = (struct node*)malloc(sizeof(struct node));
    struct node* a =(struct node*)malloc(sizeof(struct node));
    struct node* b= (struct node*)malloc(sizeof(struct node));

    start ->data=10;
    start ->next = a;

    a ->data=20;
    a ->next = b;

    b ->data=30;
    b->next = NULL;


    printf("original list:\n");
    display(start);
    int value;
    printf("enter value to insert at first position:");
    scanf("%d",&value);
    start = insertBeginning(start,value);

    printf(" updeted Linked List:\n");
    display(start);

    return 0;
}

