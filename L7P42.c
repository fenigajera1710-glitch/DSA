//inserte node at the last in doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node * linkedlist(int k){
    struct node *start = NULL;
    struct node *n,*p;  // n is the new node and p containe address of last node

    for(int i = 1; i<=k ; i++){
        n = (struct node*)malloc(sizeof(struct node));
        printf("Enter node %d data:",i);
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

void inseratend(struct node *start,int value){
    struct node *p = start;
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    if(start == NULL){
        start = n;
        n->prev = NULL;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = n;
        n->prev = p;
    }
}




void display(struct node *start){
    struct node * p= start;
    for(int i = 1; p != NULL; i++){
        printf("%d <->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(){
    int k,value;

    printf("Enter the number of nodes:");
    scanf("%d",&k);

    struct node * start =  linkedlist(k);
    printf("Original linked list:\n");
    display(start);

    printf("Enter value that you wante to insert:");
    scanf("%d",&value);

     inseratend(start,value);

    printf("After insertion linked lise:\n");
    display(start);

    return 0;

}