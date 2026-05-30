//inserte node at the beginning in doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node * insertatbegining(struct node *start,int value){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->prev = NULL;
    if(start == NULL){
        start = n;
        n->next = NULL;
    }
    else{
        n->next = start;
        start->prev = n;
        start = n;
    }
    return start;
}

void display(struct node * start){
    struct node *p = start;
    for(int i = 1; p != NULL; i++){
        printf("%d <-> ",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *start = NULL;
    struct node *n,*p ;         //n is new node and p contain address of last node
    int i,k;

    printf("Enter the number of nodes:");
    scanf("%d",&k);

    for(i = 1; i <= k; i++){
        n =(struct node*)malloc(sizeof(struct node));
         printf("Enter %d node data:",i);
         scanf("%d",&n->data);

         n->next = NULL;
         n->prev = NULL;

         if(start == NULL){
            start = n;
            p = n;
         }
         else{
            p->next = n;
            n->prev = p;
            p = n;
         }
    }
    printf("Original linked list:\n");
    display(start);

    int value;
    printf("Enter value that you want to insert:");
    scanf("%d",&value);

    start = insertatbegining(start,value);
    
     printf("After insertion linked list:\n");
    display(start);

    return 0;
}