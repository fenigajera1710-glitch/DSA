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
    n->left = n->right = NULL;
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
    root -> left = tree();

    printf("right child of %d\n",value);
    root -> right = tree();

   return root;
}

int leafnode(struct bnode *root){
    int value = 0;
    if(root){
        if(root ->left == NULL && root ->right == NULL){//there is only root node
            value = 1;
        }
        else{
            value = value + leafnode(root->left) + leafnode(root->right);
        }
    }
    return value;

}

int main(){
    struct bnode *root = NULL;

    printf("creat Binary Tree\n");
    root = tree();


    int noleafnode = leafnode(root);

    printf("Number of leaf node : %d\n",noleafnode);

    return 0;

}

