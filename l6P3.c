#include<stdio.h>
#include<string.h>


#define MAX 100
int s[MAX];
int top = -1;

void push(char ch){
    if(top == MAX -1){
        printf("stack overflow\n");
        return;
    }
    top++;
    s[top] = ch;
}

char pop(){
    if(top==-1){
        printf("stack is underflow\n");
        return '\0';
    }
     char ch = s[top];
    top--;
    return ch;
}

int match(char open,char close){
    if(open == '(' && close == ')')
       return 1;
    if(open == '[' && close == ']')
       return 1;
    if(open == '{' && close == '}')
       return 1;

       return 0;
}

int main(){
    char exp[MAX];
    int i,l;

    printf("Enter expression: ");
    scanf("%s",exp);

    l = strlen(exp);

    for(i=0;i<l;i++){
        if(exp[i] == '(' ||exp[i] == '[' ||exp[i] == '{' ){
            push(exp[i]);
        }

        else if(exp[i] == ')' ||exp[i] == ']' ||exp[i] == '}' ){
            if(top == -1 || !match(pop(),exp[i])){
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if(top == -1){
        printf("Balanced\n");
    }
    else{
        printf("Not Balance\n");
    }

    return 0;

}