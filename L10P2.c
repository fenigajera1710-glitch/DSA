#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node{
int data;
struct node *next;
};

int node[MAX];
struct node* adj[MAX];
int n = 0;

int findindex(int value){
    for(int i = 0; i<n;i++){
        if(node[i] == value){
            return i;
        }
    }
    return -1;
}

void createnode(int value){
    if(n == MAX){
        printf("Max nodes reached\n");
        return;
    }
    node[n] = value;
    adj[n] = NULL;
    n++;
    printf("Node %d added\n",value);
}
struct node* creatadjnode(int data){
    struct node *new = (struct node*)malloc (sizeof(struct node));
    new -> data = data;
    new->next = NULL;
    return new;
}

void insertedge(int src,int dest){
    int i = findindex(src);
    int j = findindex(dest);
    if(i == -1 ||j == -1){
        printf("Invalid nodes\n");
        return;
    }
    struct node *newnode = creatadjnode(dest);
    newnode->next = adj[i];
    adj[i] = newnode;

    printf("Edge inserted:%d->%d\n",src,dest);
}

void deleteedge(int src, int dest){
    int i = findindex(src);

    if(i == -1){
        printf("Invalid source\n");
        return;
    }

    struct node *curr = adj[i],*prev = NULL;
     
    while(curr != NULL){
        if(curr->data == dest){
            if(prev == NULL)
            adj[i] = curr->next;
            else
            prev->next = curr->next;

            free(curr);
            printf("Edge deleted\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Edge not found\n");
}

void deletenode(int value){
    int idx = findindex(value);

    if(idx == -1){
        printf("Node not found\n");
        return;
    }

    struct node *temp = adj[idx];
    while(temp != NULL){
        struct node *t = temp;
        temp = temp->next;
        free(t);
    }
    for(int i = idx;i<n-1;i++){
        node[i] = node[i+1];
        adj[i] = adj[i+1];
    }
    n--;

    for(int i = 0;i<n;i++){
        struct node *curr = adj[i],*prev = NULL;

        while(curr != NULL){
            if(curr->data == value){
                if(prev == NULL)
                adj[i] = curr->next;
                else
                prev->next = curr->next;

                free(curr);

                if(prev == NULL)
                curr = adj[i];
                else
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    printf("Node deleted\n");
}

int indegree(int value){
    int count = 0;
    for(int i = 0; i<n ; i++){
        struct  node *temp = adj[i];
        while(temp != NULL){
            if(temp->data == value)
            count++;
            temp = temp->next;
        }
    }
    return count;
}

int outdegree(int value){
    int count = 0;
    int idx = findindex(value);

    if(idx == -1)
    return -1;
    struct node *temp = adj[idx];

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void displaygraph(){
    for(int i = 0; i<n ; i++){
        printf("%d->",node[i]);

        struct node *temp = adj[i];
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int choice,val,src,dest;

    for(int i = 0 ;i<MAX ; i++)
     adj[i] = NULL;

     do{
        printf("\n1.Create Node 2.Delete Node 3.Insert Edge 4.Delete Edge\n");
        printf("5.In-degree 6.Out-degree 7.Display 0.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter node value:");
            scanf("%d",&val);
            createnode(val);
            break;

            case 2:
            printf("Enter node value: ");
            scanf("%d", &val);
            deletenode(val);
            break;
            case 3:
                printf("Enter src and dest: ");
                scanf("%d %d", &src, &dest);
                insertedge(src, dest);
                break;

            case 4:
                printf("Enter src and dest: ");
                scanf("%d %d", &src, &dest);
                deleteedge(src, dest);
                break;

            case 5:
                printf("Enter node: ");
                scanf("%d", &val);
                printf("In-degree = %d\n", indegree(val));
                break;

             case 6:
                printf("Enter node: ");
                scanf("%d", &val);
                printf("Out-degree = %d\n", outdegree(val));
                break;

            case 7:
                displaygraph();
                break;
        }

     }while(choice != 0);
     return 0;
}






