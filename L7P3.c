#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

 void traverse(struct node *start){
    struct node *p = start;

    if(start == NULL){
        printf("List is empty");
        return;
    }
    do{
        printf("%d->",p->data);
        p = p->next;
    }while(p != start);
    printf("start\n");
 }

 int main(){
    struct node *start = (struct node*)malloc(sizeof(struct node));
    struct node *a = (struct node*)malloc(sizeof(struct node));
    struct node *b = (struct node*)malloc(sizeof(struct node));
    struct node *c= (struct node*)malloc(sizeof(struct node));

    start->data = 50;
    start->next = a;

    a->data = 68;
    a->next = b;

    b->data = 97;
    b->next = c;

    c->data = 80;
    c->next = start;

    traverse(start);

    return 0;
 }