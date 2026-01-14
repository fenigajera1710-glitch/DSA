#include<stdio.h>
struct employee{
char ename[50];
float esalary;
int eid;
};
struct organization{
char oname[50];
int oid;
struct employee e[2];
};

int main(){
struct organization o[2];
int i,j;

for(i=0;i<2;i++){
    printf("enter organization %d name:",i+1);
    fgets(o[i].oname,sizeof(o[i].oname),stdin);

    printf("enter organization id:");
    scanf("%d",&o[i].oid);
    getchar();

    for(j=0;j<2;j++){
        printf("enter employee %d name:",j+1);
        fgets(o[i].e[j].ename,sizeof(o[i].e[j].ename),stdin);

        printf("enter employee id:");
        scanf("%d",&o[i].e[j].eid);

        getchar();

        printf("enter employee salary:");
        scanf("%f",&o[i].e[j].esalary);
        getchar();

    }
}

printf("**********ALL DETAILS************\n");

for(i=0;i<2;i++){
    printf("organization %d name:%s\n",i+1,o[i].oname);
    printf("organization id:%d\n",o[i].oid);
    for(j=0;j<2;j++){
        printf("********employee %d details***********\n",j+1);
        printf("employee name:%s\n",o[i].e[j].ename);
        printf("employee id:%d\n",o[i].e[j].eid);
        printf("employee salary:%f\n",o[i].e[j].esalary);
    }
}


return 0;
}