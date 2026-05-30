#include<stdio.h>

void printarray(int arr[],int n){
    int i;
    for(i = 0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
}

void linearsearch(int arr[],int n, int item){
     int found = 0;
    for(int i = 0; i<n ; i++){
        if(arr[i] == item){
            printf("Element is found at index:%d\n",i);
            found = 1;
        }
    }
    if(!found){
        printf("Element is not found");
    }
}
void binarysearch(int arr[],int n, int item){
    int l = 0 , r = n-1 ,mid;
    while( l <= r ){
        mid = (l+r)/2;
        if(arr[mid] == item){
            printf("Element found at index %d",mid);
            return;
        }
        else if(item <arr[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    printf("Element is not found");
}

void bubblesort(int arr[],int n){
    int temp;
    for(int i = 0;i< n-1;i++){
        for(int j = 0 ; j< n-1-i;j++){
            if(arr[j] > arr[j+1]){
              temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp; 
            }
        }
    }
}

void selectionsort(int arr[],int n){
    int i,j;
    for(i = 0 ; i<n-1 ; i++){
        int min = i;
            for (j = i+1 ; j<n ; j++){
                if(arr[j]<arr[min]){
                    min = j;
                }
            }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = arr[i];
        }
    }
}

void insertionsort(int arr[],int n){
    int i,j,temp;
    for(i = 1 ; i < n ; i++){
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int partition(int arr[],int low ,int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j<high ; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quicksort(int arr[], int low,int high){
    if(low < high){
        int p = partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while(i <= mid && j <= high) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}


void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[100],n,item;

    printf("Enter the no of elements:");
    scanf("%d",&n);

    printf("Enter elements:");
    for(int i = 0; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    printf("\nOriginal array:");
    printarray(arr,n);

    printf("\nEnter element for linear search:");
    scanf("%d",&item);
    linearsearch(arr,n,item);

    bubblesort(arr,n);
    printf("\nSorted array for binary search:");
    printarray(arr,n);

    printf("\nEnter element for binary search:");
    scanf("%d",&item);
    binarysearch(arr,n,item);

    bubblesort(arr,n);
    printf("\nBubble sort:");
    printarray(arr,n);

    selectionsort(arr,n);
    printf("\nSelection sort:");
    printarray(arr,n);

    insertionsort(arr,n);
    printf("\nInsertion sort:");
    printarray(arr,n);

    quicksort(arr,0,n-1);
    printf("\nQuick sort:");
    printarray(arr,n);

    mergeSort(arr,0,n-1);
    printf("\nMerge sort:");
    printarray(arr,n);

    return 0;

}