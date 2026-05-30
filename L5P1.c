#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    else
    return 0; 
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else
       return 0;
}

void pop(){
    int item;
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    item = stack[top];
    printf("deleted element is:%d\n",stack[top]);
    top--;
}

void push(int item){
    if(isFull()){
        printf("stack is full\n");
        return ;
    }
    top++;
    stack[top] = item;
    printf("inserted element is: %d\n",stack[top]);
}

void peek(){
    if(isEmpty()){
        printf("stack is empty\n");
        return;
    }
    printf("top element is: %d\n",stack[top]);
}

int main(){
    push(10);
    push(20);

    pop();

    peek();
    
    pop();
    peek();
    pop();

    return 0;

}
