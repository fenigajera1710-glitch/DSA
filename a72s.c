#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    
    n->data = x;
    if(n == NULL){
        printf("Overflow\n");
        return ;
    }
    n->next = top;
    top = n;
    
    
}

void pop(){
    if(top == NULL){
        printf("Underflow\n");
        return;
    }
    struct node *p = top;
    printf(" Deleted element : %d\n",top->data);
    top = top->next;
    free(p);

}

void peek(){
    if(top == NULL){
        printf("Underflow\n");
        return;
    }
    printf("Top element is: %d\n",top->data);
}

void display(){
    struct node *p = top;
    if(top == NULL){
        printf("Stack is empty\n");
        return ;
    }
    while(p != NULL){
        printf("%d->",p->data);
        p = p->next;

    }
    printf("NULL\n");
}

int main(){
   
    push(5);
    push(15);
    push(25);

    display();

    peek();
    pop();
    

    display();

    return 0;
}