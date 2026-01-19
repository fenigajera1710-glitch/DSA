#include<stdio.h>

struct student{
    int rollno;
    char name[50];
    char address[100];
};
int main(){
struct student s1;
struct student *ptr;
ptr = &s1;

printf("*******ENTER STUDENT DETAILS*******\n");

printf("Enter name:");
scanf("%s",s1.name);
printf("enter roll no:");
scanf("%d",&s1.rollno);
printf("enter address:");
scanf("%s",s1.address);

printf("*******STUDENT DETAILS*******\n");
printf("Enter name:%s\n",ptr->name);
printf("enter roll no:%d\n",ptr->rollno);
printf("enter address:%s\n",ptr->address);

return 0;
}
