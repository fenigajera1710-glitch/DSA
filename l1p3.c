#include<stdio.h>
int main(){
int n,i,j,count = 0;
int a[100],f[100];

printf("Enter the number of elements:");
scanf("%d",&n);
printf("Enter %d elements:",n);
for(i = 0; i<n;i++)
{
    scanf("%d",&a[i]);
    f[i] = -1;
}

for(i = 0;i<n;i++){
    if(f[i] != 0){
        count = 1;
        for(j = i + 1;j<n;j++){
            if(a[i] == a[j]){
                count++;
                f[j] = 0;

            }
        }
       f[i]=count;
    }
}

printf("\nElement frequency\n");
for(i=0;i<n;i++){
    if(f[i]!=0){
        printf("%d\t%d\n",a[i],f[i]);
    }
}

printf("unic elements in the array :\n");
for(i = 0; i<n;i++){
    if(f[i] == 1){
        printf("%d",a[i]);
    }
}

return 0;
}