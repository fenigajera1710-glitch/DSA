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
    int nam = 0;

    while(expr[i] != '\0'){
        if(isdigit(expr[i])){
            push(expr[i]-'0');
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

    char exp1[] = "231*+9-";
    char exp2[] = "22+2/5*7+";

      top = -1;
    printf("Expression: 2 3 1 * + 9 -\n");
    printf("Output: %d\n\n", evaluate(exp1));

    top = -1;
    printf("Expression: 2 2 + 2 / 5 * 7 +\n");
    printf("Output: %d\n", evaluate(exp2));

    return 0;

}

