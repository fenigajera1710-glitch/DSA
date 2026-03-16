#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void inserPosition(struct node* start,int value,int position){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n -> data = value;
    if(position == 1){
        n->next = start;
        start = n;
        return;
    }

    struct node *p = start;
    for(int i = 1;i<position-1 && p!=NULL;i++ ){
        p = p->next;
    }

    if(p==NULL){
        printf("INVALID POSITION\n");
        return;
    }

    n->next = p->next;
    p->next = n;
    
}

void diaplay(struct node *start){
    struct node *p = start;
    while(p!=NULL){
        printf("%d->",p->data);
        p = p->next;
    }

    printf("NULL");
}

int main(){

    int value,position;
    struct node *start = (struct node*)malloc(sizeof(struct node));
    struct node *a = (struct node*)malloc(sizeof(struct node));
    struct node *b = (struct node*)malloc(sizeof(struct node));

    start->data = 50;
    start->next = a;

    a->data = 68;
    a->next = b;

    b->data = 97;
    b->next = NULL;

    printf("Linked list:\n");
    diaplay(start);
    printf("\n");

    printf("Enter value :");
    scanf("%d",&value);

    printf("Enter position :");
    scanf("%d",&position);

    inserPosition(start,value,position);

    printf(" Updated Linked list:\n");
    diaplay(start);

    return 0;
   
}
