#include <stdio.h>

int linear_search(int *arr, int key, int size){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("\n");
            return i;
        }
    }
    printf("\n");
    return 0;
}

int binary_search(int *arr, int key, int size){
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return 0;
    
}