/*1.Create a structure Student in C with student name, student roll number and 
student address as its data members. Create the variable of type student and print the values.*/
#include<stdio.h>

struct student{
    char name[50];
    int rollno;
    char address[100];
};

int main(){
struct student s;

printf("Enter student name:");
fgets(s.name,sizeof(s.name),stdin);

printf("Enter roll number:");
scanf("%d",&s.rollno);
getchar();

printf("Enter address:");
fgets(s.address,sizeof(s.address),stdin);

printf("**********STUDENT DETAILS**********\n");

printf("Student name:%s\n",s.name);
printf("Sudent roll no :%d\n",s.rollno);
printf("Address:%s\n",s.address);

return 0;

}
