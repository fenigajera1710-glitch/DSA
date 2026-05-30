//delete node from any position in doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *deletfromposition(struct node *start,int pos){
    struct node *p = start;
    if(start == NULL){
        printf("Underflow");
        return NULL;
    }
    if(start ->next == NULL){
        free(start);
        return NULL;
    } 
    if(pos == 1){
        start = start ->next;
        if(start != NULL){
        start ->prev = NULL; 
        }
        free(p);
        return start;
    }
    for(int i = 1 ; i < pos && p!=NULL;i++){
        p = p->next;
    }//p contain address of pos  node
    if(p == NULL){
        printf("Invalid position");
        return start;
    }
    if(p ->next != NULL){
        p->next->prev = p->prev;
    }
    p->prev->next = p->next;
    free(p);
    return start;
}
void display(struct node *start){
    struct node *p = start;
    for(int i = 1; p != NULL; i++){
        printf("%d <->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node *linkedlist(int k){
    struct node *start = NULL;
    struct node *n,*p;
    for(int i = 1 ;i<= k; i++){
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

int main(){
    int k,pos;
    printf("Enter the no. of nodes:");
    scanf("%d",&k);

    struct node *start = linkedlist(k);

    printf("linked lise before deletion:\n");
    display(start);

    printf("Enter position:");
    scanf("%d",&pos);

    start = deletfromposition(start,pos);

    printf("linked list after deletion:\n");
    display(start);
    return 0;
 

}