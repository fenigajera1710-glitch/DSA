#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* deletefromposition(struct node *start,int position){
    struct node *p = start;
    if(start == NULL){
        printf("underflow");
        return start;
    }
    if(position == 1){
        start = start->next;
        return start;
    }
     int i=1;
    while(i<position-1 && p != NULL){
        p = p->next;
        i++;
    }
    if(p == NULL){
        printf("invalid positon\n");
    }

    struct node *r,*q;
    r = p->next;
    q = p->next->next;
    p->next = q;
    free(r);
    return start;
}

int main(){
    struct node *start = (struct node*)malloc(sizeof(struct node));
    struct node *p = start;
    struct node *q;
    int value;
    printf("Enter value:");
    scanf("%d",&value);
    
    start->data = value;
    start->next = NULL;

    int i=1;
    int n;
    printf("no of nodes:");
    scanf("%d",&n);
    
    printf("Enter %d value:\n",n);
    while(i<=n){
      q = (struct node*)malloc(sizeof(struct node));
      scanf("%d",&q->data);
      p->next = q;
      p = q;
      i++;
    }
    p->next = NULL;
    struct node *y = start;
    printf("original linked list:\n");
    while(y != NULL){
        printf("%d->",y->data);
        y = y->next;}
    printf("NULL\n");
    int j;
    printf("Enter node no that you want to delete:");
    scanf("%d",&j);

    start = deletefromposition(start,j);
    struct node *f = start;
    printf("After the deletion linked list:");
    while(f != NULL){
        printf("%d->",f->data);
        f = f->next;
    }
    printf("NULL\n");
    return 0;

}
