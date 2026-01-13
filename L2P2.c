/*Modify the above program to implement arrays of structure.
 Create an array of 5 students and print their values*/

 #include<stdio.h>

 struct student{
    char name[50];
    int rollno;
    char address[100];
 };

 int main(){

struct student s[5];
int i;

for(i=0;i<5;i++){
printf("******ENTER STUDENT %d DETAILS******\n",i+1);

printf("student name:");
fgets(s[i].name,sizeof(s[i].name),stdin);

printf("student roll no:");
scanf("%d",&s[i].rollno);
getchar();

printf("Address:");
fgets(s[i].address,sizeof(s[i].address),stdin);

}

printf("******STUDENT DETAILS******\n");

for(i=0;i<5;i++){


    printf("student name:%s",s[i].name);
    printf("student roll no:%d\n",s[i].rollno);
    printf("Address:%s",s[i].address);
}

return 0;

 }