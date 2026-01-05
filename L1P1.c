#include<stdio.h>

int main(){
int i,n;
char arr[100];

printf("Enter number of characters: ");
scanf("%d",&n);
printf("Enter %d elements:\n ",n);
for(i = 0 ; i<n;i++){
    scanf(" %c",&arr[i]);
}

printf("string in reverse :");
for(i = n-1;i>=0;i--){
    printf("%c",arr[i]);
}

return 0;
}