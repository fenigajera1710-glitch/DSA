//delete node from beginningin doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *linkedlist(int k){
    struct node *start = NULL;
    struct node *n,*p;//n is new node and p contain address of last node
    for(int i = 1; i <= k ;i++){
        struct node *n = (struct node*)malloc(sizeof(struct node));
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

void display(struct node * start){
    struct node *p = start;
    for(int i = 1; p != NULL; i++){
        printf("%d<->",p->data);
        p = p->next;
    }
    printf("NULL");
}

struct node *deletfrombeginning(struct node *start){
    struct node *p = start;
    if(start == NULL){
        printf("Underflow");
        return NULL;
    }
    if(start ->next == NULL){
        free (p);
        start = NULL;
        return start;
    }
   
    start = start -> next;
    start ->prev = NULL;
    free(p);
    return start;
}

int main(){
    int k;
    printf("Enter the no. of nodes:");
    scanf("%d",&k);

    struct node *start = linkedlist(k);

    printf("Before deletion linked list:\n");
    display(start);

    start = deletfrombeginning(start);

    printf("\nAfter deletion linked list:\n");
    display(start);

    return 0;
}