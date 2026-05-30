#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100
int s[MAX];
int top = -1;

void push(int value){
    if(top == MAX -1){
        printf("stack overflow\n");
        return;
    }
    top++;
    s[top] = value;
}

char pop(){
    if(top==-1){
        printf("stack is underflow\n");
        return '\0';
    }
    int value = s[top];
    top--;
    return value;
}

int prcd(char op){
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '^')
        return 3;
    else 
        return 0;
}

void InfixToPostfix(char infix[]){
    char postfix[MAX];
    int i=0,j=0;
    while(infix[i] != '\0' ){
        if(isalnum(infix[i])){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while (top != -1 && s[top] != '(')
            {
               postfix[j++] = pop();
            }
            pop();
            
        }
        else{
            while(top != -1 && prcd(s[top])>=prcd(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while(top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("postfix expression:%s\n",postfix);
}

int main(){
     char infix[] = "a+b*(c^d-e)^(f+g*h)-i";

     top = -1;
     printf(" infix expression:%s\n ",infix);
     
     InfixToPostfix(infix);
     printf("\n");

     return 0;
}
