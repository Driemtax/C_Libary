#include <stdio.h>
#include <stdlib.h>
#include "../Header Files/helper.h"

#define SIZE 100

void selection_sort(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap_numbers(&arr[i], &arr[min_index]);
    }
    
}

int main(){
    int *arr = array_malloc(SIZE);
    randomize_array(arr, SIZE);

    selection_sort(arr, SIZE);

    //print Output
    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ", arr[i]);
    }
}