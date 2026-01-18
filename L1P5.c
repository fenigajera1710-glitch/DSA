#include<stdio.h>
int main(){
int A[10][10],B[10][10],C[10][10];
int i,j,k,n;

printf("Enter the order of matrix:");
scanf("%d",&n);

printf("Enter elements of first matrix:\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&A[i][j]);
    }
}

printf("Enter elements of second matrix:\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&B[i][j]);
    }
}

for(i=0;i<n;i++){
    for(j=0;j<n;j++){

        C[i][j] = 0;

    }
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            C[i][j] += A[i][k]*B[k][j];
        }
    }
}

printf("Result metrix:\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d\t",C[i][j]);

    }
    printf("\n");
}

return 0;
}