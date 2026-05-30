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

int pop(){
    if(top==-1){
        printf("stack is underflow\n");
        return 0;
    }
    int value = s[top];
    top--;
    return value;
}

int evaluate(char expr[]){
    int i=0;
    

    while(expr[i] != '\0'){
        if(expr[i] == ' '){
            i ++;
            continue;
        }
        if(isdigit(expr[i])){
            int num = 0;
            while(isdigit(expr[i])){
            num = num * 10 + (expr[i]-'0');
            i++;
        }
            push(num);
        }

        else if(expr[i]=='+'||expr[i]=='-'|| expr[i]=='*'||expr[i]=='/'){
            int b = pop();
            int a = pop();
            int result;

            if(expr[i] == '+')
            result = a + b;
           else if(expr[i] == '-')
            result = a - b;
            else if(expr[i] == '*')
            result = a * b;
            else if(expr[i] == '/')
            result = a / b;

            push(result);
        }
        i++;
    }
    return pop();
}

int main(){

    char exp[] = "10 5 + 30 6 / 5 5 * 3 * * + 8 -";
 

    top = -1;
    printf("Expression:10 5 + 30 6 / 5 5 * 3 * * + 8 - \n");
    printf("Output: %d\n\n", evaluate(exp));

    return 0;

}

