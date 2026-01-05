#include<stdio.h>
int main(){

    int n,i,min,max,a[100];

    printf("Enter the number of elements:");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    min = a[0];
    for(i = 1; i<n;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    printf("min value is %d\n",min);

    max = a[0];
    for(i = 1; i<n;i++){
        if(max<a[i]){
            max = a[i];
        }
    }
    printf("max value is %d\n",max);

    return 0;

}