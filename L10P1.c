#include<stdio.h>
#define MAX 20

int adj[MAX][MAX];
int n = 0; 

void insertEdge(int src , int dest){
    if(src<0 || src >=n || dest<0 || dest>=n){
        printf("Invalid nodes.\n");
        return;
    }
    adj[src][dest] = 1;
    printf("Edge is created between %d->%d",src,dest);
}

void DeleteEdge(int src, int dest){
    if(src<0 || src>=n || dest<0 || dest>=n){
        printf("Invalid nodes.\n");
        return;
    }
    adj[src][dest] = 0;
    printf("Edge is deleted between %d->%d",src,dest);
}

void creatnode(){
    int i;
    if(n == MAX){
        printf("Max node reached\n");
        return;
    }
    for(i = 0 ; i<=n ; i++){
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    printf("node %d created\n",n);
    n++;
}

void deletenode(int node){
    int i,j;
    if(node <0 || node>=n){
        printf("Invalid node\n");
        return;
    }

    for(i = node ; i<n-1; i++){
        for(j = 0 ; j<n ; j++){
            adj[i][j] = adj[i+1][j];
        }
    }
    
    for( j = node ; j<n-1; j++){
        for(i = 0; i<n-1 ; i++){
            adj[i][j] = adj[i][j+1];
        }
    }

    printf("Node %d deleted\n",node);
    n--;
}

int inDegree(int node){
    int i,count = 0;

    for(i = 0; i<n ; i++){
        if(adj[i][node] == 1){
            count++;
        }
    }
    return count;
}

int outDegree(int node){
    int j,count = 0;
    for(j = 0; j<n ; j++){
        if(adj[node][j] == 1){
            count++;
        }
    }
    return count;
} 

void displayGraph(){
    int i,j;
    if(n == 0){
        printf("Graph is empty\n");
        return;
    }
    printf("\nAdjacency Matrix:\n");
    for(i = 0 ; i<n ; i++){
        for(j = 0 ; j<n ; j++){
            printf("%d " ,adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int choice,node,src,dest;
    do{
        printf("\n---Graph operation---\n");
        printf("1.Insert node\n");
        printf("2.Delete node\n");
        printf("3.Insert Edge\n");
        printf("4.Delete Edge\n");
        printf("5.In-Degree\n");
        printf("6.Out-Degree\n");
        printf("7.Display Graph\n");
        printf("0.exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            creatnode();
            break;

            case 2:
            printf("Enter node :");
            scanf("%d",&node);
            deletenode(node);
            break;

            case 3: 
            printf("Enter src and dest:");
            scanf("%d %d",&src,&dest);
            insertEdge(src,dest);
            break;

            case 4:
            printf("Enter src and dest:");
            scanf("%d %d",&src,&dest);
            DeleteEdge(src,dest);
            break;

            case 5:
            printf("Enter node:");
            scanf("%d",&node);
            printf("In-Degree :%d",inDegree(node));
            break;

            case 6:
            printf("Enter node:");
            scanf("%d",&node);
            printf("Out-Degree:%d",outDegree(node));
            break;

            case 7:
            displayGraph();
            break;
        }

    }while(choice != 0);
    return 0;
}

