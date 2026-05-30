//insert node at any position in doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *linkedlist(int k){
    struct node *start = NULL;
    struct node *n,*p;   // n is new node and p contain address of last node
    for(int i = 1; i <= k; i++){
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
    for(int i = 1; p != NULL ; i++){
        printf("%d <-> ",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node * inseratposition(struct node *start , int value,int position){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    struct node *p = start;
    if (position == 1){
        n->next = start;
        start->prev = n;
        n->prev = NULL;
        start = n;
        return start;
    }
    for(int i = 1; i < position - 1 && p != NULL ;i++){
        p = p->next;
    }
    if(p == NULL){
        printf("Invalid position\n");
        return start;
    }
       n->next = p->next;
       n->prev = p;
       if(p->next != NULL){
       p->next->prev = n;}
       p->next = n;
       
        return start;
}

int main(){
    int k,value,position;
    printf("Enter the no. of nodes:");
    scanf("%d",&k);

    struct node * start = linkedlist(k);

    printf("Original linked list:\n");
    display(start);

    printf("Enter value:");
    scanf("%d",&value);

    printf("Enter position:");
    scanf("%d",&position);

    start = inseratposition(start,value,position);

    printf("After insertion linked list:\n");
    display(start);

    return 0;
}