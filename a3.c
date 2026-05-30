#include <stdio.h>

struct Student {
    char name[50];
};

int main() {
    struct Student s[5];          // Array of structures
    struct Student *ptr[5];       // Array of pointers to structures
    int i;

    
    for (i = 0; i < 5; i++) {
        ptr[i] = &s[i];
    }

    
    for (i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", ptr[i]->name); 
    }

    
    printf("\nStudent Names:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, ptr[i]->name); 
    }

    return 0;
}
