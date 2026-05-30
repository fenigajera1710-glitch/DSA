#include<stdio.h>
#include<stdlib.h>

struct bnode{
    int data;
    struct bnode *left, *right;
};

struct bnode *getnode(int value){
    struct bnode *n = (struct bnode *)malloc(sizeof(struct bnode));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

struct bnode *insert(struct bnode *root,int x){
    if(root == NULL){
        return getnode(x);
    }
    if(x < root->data){
        root->left = insert(root->left,x);
    }else{
        root->right = insert(root->right,x);
    }
    return root;
}

struct bnode *search(struct bnode *root,int x){
    if(root == NULL)
      return NULL;
    if(root->data == x)
      return root;
    if(x < root->data){
        search(root->left,x);
    }else{
        search(root->right,x);
    }
}

struct bnode *findMin(struct bnode *root){
    if(root == NULL){
        return NULL;
    }
    struct bnode *t = root;
    while(t != NULL && t->left != NULL){
        t = t->left;
    }
    return t;
}

struct bnode* deleteNode(struct bnode* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            struct bnode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct bnode* temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct bnode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct bnode *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct bnode *root = NULL;
    int n,x,i,y;

    printf("Entrer no of nodes: ");
    scanf("%d",&n);

    printf("Enter %d value:",n);
    
    for(i = 0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }

    inorder(root);

    printf("\nEnter value for insert:");
    scanf("%d",&x);

    root = insert(root,x);

    inorder(root);

    printf("\nEnter value for search :");
    scanf("%d",&y);

    if(search(root,y) != NULL){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }

     printf("\nEnter value for delete :");
    scanf("%d",&y);

    root = deleteNode(root,y);

    inorder(root);
    return 0;

}