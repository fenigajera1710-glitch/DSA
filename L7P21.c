#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};

 struct node *deleteBegging(struct node *start){
    if(start == NULL){
        printf("Underflow\n");
        return NULL;
    }
    struct node* p = start;
     printf("Deleted element: %d\n", start->data);
    start = start->next;
    free(p);

    return start;

}

 void display(struct node* start){
    struct node* p = start;
    while(p!=NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL");

 }

int main(){
    struct node* start = (struct node*)malloc(sizeof(struct node));
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
    printf("\n");

     start = deleteBegging(start);

    printf("After deletion linked list:\n");
    display(start);

    return 0;



}