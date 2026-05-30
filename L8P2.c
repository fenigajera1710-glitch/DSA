#include<stdio.h>

void getparent(int tree[],int n, int i){
    if(i == 0){
        printf("No parent (root node)\n");
    }
    else{
        int p = (i-1)/2;
        printf("Parent: %d\n",tree[p]);
    }
}

void getchildren(int tree[],int n, int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n){
        printf("Left child: %d\n",tree[left]);
    }else{
        printf("No left child\n");
    }

    if(right < n){
        printf("Right child: %d\n",tree[right]);
    }
    else{
        printf("No right child\n");
    }
}

void getsibling(int tree[],int n, int i){
    int s;
    if(i == 0){
        printf("No sibling (root node)\n");
        return;
    }
    if(i % 2 == 1){
        s = i + 1;
    }else{
        s = i - 1;
    }
    if(s >= 0 && s < n){
        printf("Sibling = %d\n",tree[s]);
    }else{
        printf("No sibling\n");
    }
}

int main(){

    int n,i,index;

    printf("Enter number of nodes:");
    scanf("%d",&n);

    int tree[n];   

    printf("Enter elements:\n");
    for(i = 0; i < n ; i++){
        scanf("%d",&tree[i]);
    }

    printf("Enter index of node:");
    scanf("%d",&index);

    getparent(tree,n,index);
    getchildren(tree,n,index);
    getsibling(tree,n,index);

    return 0;
}