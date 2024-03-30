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

char* initialize_char_array(char *arr, int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = '0';
    }

    return arr;
    
}

int* initialize_int_array(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    return arr;
    
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