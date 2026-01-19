#include<stdio.h>

int main(){
    //array of pointer
    int a=10,b=20,c=30;
    int i;
    int *ptrarr[3];

    ptrarr[0] = &a;
    ptrarr[1] = &b;
    ptrarr[2] = &c;

    for(i=0;i<3;i++){
        printf("VALUES ARE:%d\n",*ptrarr[i]);
    }

  //pointer to array
  int A[3] = {10,20,30};
  int (*ptr)[3];

  ptr = &A;



  printf("values are:");
  printf("%d %d %d\n",(*ptr)[0],(*ptr)[1],(*ptr)[2]);

 return 0;
}