#include <stdio.h>

void randomize_array(int *arr, int size){
    printf("Random Array: \n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()% size;
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int* array_malloc(int size){
    int *ptr = (int*) malloc(size*sizeof(int));

    if (ptr == NULL)
    {
        return 0;
    }
    return ptr;
}

void swap_numbers(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}