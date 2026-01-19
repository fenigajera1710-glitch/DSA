#include<stdio.h>
void swap(int *ptr1,int *ptr2);
int main(){
    int a,b;
    printf("enter a and b:");
    scanf("%d %d",&a,&b);

    printf("BEFORE SWAPPING\n");
    printf("a =%d\n",a);
    printf("b = %d\n",b);

    swap(&a,&b);
    printf("AFTER SWAPPING\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    return 0;



}

void swap(int *ptr1,int *ptr2){
    int temp;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

}