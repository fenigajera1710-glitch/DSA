#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* deleteEnd(struct node*start){
    struct node* p = start;
    if(start == NULL){
        printf("UNDERFLOW");
        return NULL;
    }
    if(start->next == NULL){
        printf("Deleted element is: %d\n", start->data);
        free(start);
        return NULL;
    }

    while(p->next->next != NULL){
        p = p->next;
    }

    struct node* q = p->next;
    p->next = NULL;
    printf("Deleted element is:%d\n",q->data);
    free(q);
    return start;

}
 void display(struct node* start){
    struct node* p = start;
    while(p != NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
 }

 int main(){
    struct node* start= (struct node*)malloc(sizeof(struct node));
    struct node* a = (struct node*)malloc(sizeof(struct node));
    struct node* b = (struct node*)malloc(sizeof(struct node));
    struct node* c = (struct node*)malloc(sizeof(struct node));

    start->data = 10;
    start->next = a;

    a->data = 20;
    a->next = b;

    b->data = 50;
    b->next = c;

    c->data = 80;
    c->next = NULL;


    printf("original Linled list:\n");
    display(start);

    start = deleteEnd(start);

     printf("After deletion linked list:\n");
    display(start);

    return 0;


 }