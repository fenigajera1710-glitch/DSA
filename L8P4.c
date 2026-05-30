#include<stdio.h>
#include<stdlib.h>
struct bnode{
    int data;
    struct bnode *left;
    struct bnode *right;
};
struct bnode *getnode(int value){
    struct bnode *n = (struct bnode*)malloc(sizeof(struct bnode));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
struct bnode *tree(){
    int value;
    printf("Enter value(-1 for NULL):");
    scanf("%d",&value);
    if(value == -1){
        return NULL;
    }
    struct bnode *root = getnode(value);
    printf("Left child of %d\n",value);
    root->left = tree();
    printf("Right child of %d\n",value);
    root->right = tree();
    return root;
}
int height(struct bnode *t){
    int hl,hr;
    if(t == NULL){
        return -1;
    }
    hl = height(t->left);
    hr = height(t->right);
    if(hl <= hr){
        return hr+1;
    }
    else{
        return hl+1;
    }
}
int main(){
    struct bnode *root = NULL;
    int h;
    printf("Creat Binary Tree\n");
    root = tree();
    h = height(root);
    printf("Height of Binary Tree: %d",h);
    return 0;
}