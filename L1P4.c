#include <stdio.h>

int main()
{
    int a[50], n, i, pos, value, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Insert an element");
    printf("\n2. Delete an element");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter position to insert: ");
        scanf("%d", &pos);

        printf("Enter value to insert: ");
        scanf("%d", &value);

        /* Shift elements to right */
        for(i = n - 1; i >= pos - 1; i--)
            a[i + 1] = a[i];

        a[pos - 1] = value;
        n++;

        printf("Array after insertion:\n");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else if(choice == 2)
    {
        printf("Enter position to delete: ");
        scanf("%d", &pos);

        /* Shift elements to left */
        for(i = pos - 1; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;

        printf("Array after deletion:\n");
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else
    {
        printf("Invalid choice");
    }

    return 0;
}
