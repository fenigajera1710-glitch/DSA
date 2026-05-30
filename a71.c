#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *linkedlist(int k){
    struct node *start = NULL;
    struct node *n,*p;//n is new node and p contains address of last node
    for(int i = 1; i<=k ; i++){
        n = (struct node*)malloc(sizeof(struct node));
        printf("Enter %d node data:",i);
        scanf("%d",&n->data);
         
        n->next = NULL;

        if(start == NULL){
            start = n;
            p = n;
        }
        else{
            p->next = n;
            p = n;

        }
    }
    return start;
}

void display(struct node *start){
    struct node *p = start;
    for(int i = 1; p != NULL;i++){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node *merge(struct node *a , struct node *b){
    struct node *result = NULL;
    struct node *start = NULL;
    struct node *p ;
     
    //if any one list is empty
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    //value of start
    if(a->data <= b->data){
        result = a;
        a = a->next;
    }
    else{
        result = b;
        b = b->next;
    }
    start = result;
    p = start;
    //for another nodes
    while(a != NULL && b != NULL){
        if(a->data <= b->data){
            p->next = a;
            a = a->next;
        }
        else{
            p->next = b;
            b = b->next;
        }
        p = p->next;
    }
        
        //if two list did not have same length
        if(a != NULL){
            p->next = a;
        }
        else{
            p->next = b;
        }

        return result;

    
}

int main(){
    int a,b;
    struct node *s1,*s2;
    printf("Enter no of node for list A:");
    scanf("%d",&a);

    printf("Enter list A data in sorted order:\n");
    s1 = linkedlist(a);

    printf("Enter no of node for list B:");
    scanf("%d",&b);

    printf("Enter list B data in sorted order:\n");
    s2 = linkedlist(b);

    printf("List A:\n");
    display(s1);

    printf("List B:\n");
    display(s2);

    struct node *start = merge(s1,s2);

    printf("Merged linked list:\n");
    display(start);



    return 0;
}