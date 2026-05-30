//delete node from end in doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *linkedlist(int k){
    struct node *start = NULL;
    struct node *n,*p;//n is new node and p is contains address of last node 
    for(int i = 1 ; i <= k; i++){
         n = (struct node*)malloc(sizeof(struct node));
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
    return start;
}

void display(struct node *start){
    struct node * p = start;
    for(int i = 0 ; p != NULL ; i++){
        printf("%d <->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node * deletfromend(struct node *start){
    struct node *p = start;
    if(start == NULL){
        printf("underflow\n");
        return NULL;
    }
    if(start ->next == NULL){
        free(start); 
       return NULL;
    }
    while(p->next->next != NULL){
        p = p->next;
    }
    struct node *q = p->next;
    p->next = NULL;
    q->prev = NULL;
    free(q);
    return start;
}

int main(){
    int k;
    printf("Enter the no. of nodes:");
    scanf("%d",&k);

    struct node *start = linkedlist(k);
    printf("Before deletion linked list:\n");
    display(start);

    start = deletfromend(start);

    printf("After deletion linked list:\n");
    display(start);

    return 0;
}