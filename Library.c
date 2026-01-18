#include<stdio.h>

struct Book{
    int bookID;
    char title[50];
    char author[50];
    float price;
};

struct Library{
    char libraryName[50];
    int libraryID;
    struct Book b[3];
};

int main(){

    struct Library l[2];
    int i,j;
    int _bookid;
    int found = 0;



    printf("********ENTER DETAILS OF LIBRARY AND BOOKS********\n");

    for(i=0;i<2;i++){
     
        printf("Enter library %d name:",i+1);
        fgets(l[i].libraryName,sizeof(l[i].libraryName),stdin);

        printf("Enter library ID:");
        scanf("%d",&l[i].libraryID);
        getchar();

        printf("BOOK DETAILS\n");

        for(j=0;j<3;j++){

            printf("Enter book %d ID:",j+1);
            scanf("%d",&l[i].b[j].bookID);
            getchar();

            printf("Enter title:");
            fgets(l[i].b[j].title,sizeof(l[i].b[j].title),stdin);

            printf("Enter author name:");
            fgets(l[i].b[j].author,sizeof(l[i].b[j].author),stdin);

            printf("Enter prince:");
            scanf("%f",&l[i].b[j].price);
            getchar();




        }
    }

    printf("--------------ALL DETAIS--------------\n");
    for(i=0;i<2;i++){
        printf("Library %d name : %s\n",i+1,l[i].libraryName);
        printf("Library ID : %d\n\n",l[i].libraryID);
         
       for(j=0;j<3;j++){

        printf("BOOK %d ID: %d\n",j+1,l[i].b[j].bookID);
        printf("BOOK title : %s\n",l[i].b[j].title);
        printf("BOOK author : %s\n",l[i].b[j].author);
        printf("BOOK price : %f\n",l[i].b[j].price);
       }
    }

    printf("Enter book ID:");
    scanf("%d",&_bookid);
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            if(l[i].b[j].bookID == _bookid){
                printf("\nbook found :)");
                printf("BOOK ID: %d\n",l[i].b[j].bookID);
                printf("BOOK title : %s\n",l[i].b[j].title);
                printf("BOOK author : %s\n",l[i].b[j].author);
                printf("BOOK price : %f\n",l[i].b[j].price);
                found = 1;
                break;

            }
        }
    }

    if(!found){
        printf("\nbook not found :(\n");
    }

    for(i = 0; i<2;i++){
        float total = 0;
        int max = 0;
        for(j=0;j<3;j++){
            total += l[i].b[j].price;
            if(l[i].b[j].price>l[i].b[max].price){
                max = j;
            }
        }

        printf("\n Library Name: %s",l[i].libraryName);
        printf("\n Total value of books:%f",total);
        printf("\n Most expensive book:%s\t%f",l[i].b[max].title,l[i].b[max].price);
    }


    return 0;
}