#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct bnode{
    int data;
    struct bnode *left;
    struct bnode *right;
};

struct bnode *s[MAX];
struct bnode *s1[MAX];
int top = -1, top1 = -1;

struct bnode *q[MAX];
int front = -1, rear = -1;

void push(struct bnode *n){
    s[++top] = n;
}

struct bnode *pop(){
    return s[top--];
}

int isempty(){
    return top == -1;
}

void push1(struct bnode *n){
    s1[++top1] = n;
}

struct bnode *pop1(){
    return s1[top1--];
}

int isempty1(){
    return top1 == -1;
}

void enqueue(struct bnode *n){
    if(front == -1)
        front = 0;
    q[++rear] = n;
}

struct bnode *dequeue(){
    return q[front++];
}

int isemptyque(){
    return (front == -1 || front > rear);
}

struct bnode *getnode(int value){
    struct bnode *n = (struct bnode*)malloc(sizeof(struct bnode));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct bnode *tree(){
    int value;
    printf("Enter value(-1 for NULL): ");
    scanf("%d",&value);

    if(value == -1)
        return NULL;

    struct bnode *root = getnode(value);

    printf("Left child of %d\n", value);
    root->left = tree();

    printf("Right child of %d\n", value);
    root->right = tree();

    return root;
}

void preorder(struct bnode *root){
    if(root == NULL) return;

    top = -1;

    push(root);
    while(!isempty()){
        struct bnode *p = pop();
        printf("%d ", p->data);

        if(p->right) push(p->right);
        if(p->left)  push(p->left);
    }
}

void inorder(struct bnode *root){
    struct bnode *curr = root;
    top = -1;

    while(curr != NULL || !isempty()){
        while(curr != NULL){
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void postorder(struct bnode *root){
    if(root == NULL) return;

    top = -1;
    top1 = -1;

    push(root);

    while(!isempty()){
        struct bnode *curr = pop();
        push1(curr);

        if(curr->left)  push(curr->left);
        if(curr->right) push(curr->right);
    }

    while(!isempty1()){
        printf("%d ", pop1()->data);
    }
}

void levelorder(struct bnode *root){
    if(root == NULL) return;

    front = rear = -1;

    enqueue(root);

    while(!isemptyque()){
        struct bnode *temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left) enqueue(temp->left);
        if(temp->right) enqueue(temp->right);
    }
}

int main(){
    struct bnode *root;

    printf("Create tree:\n");
    root = tree();

    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nLevel Order: ");
    levelorder(root);

    return 0;
}