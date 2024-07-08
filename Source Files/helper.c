#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ARRAY_INT,
    ARRAY_CHAR,
} DataType;

typedef struct {
    DataType type;
    size_t size;
    void* data;
} GenericArray ;

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
    arr[size] = '\0';

    return arr;
}

int* initialize_int_array(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    printf("Array initialized.. \n");
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

//Generic Array Create Function
GenericArray arrayCreate(size_t size, DataType type){
    size_t effectiveSize = 0;

    switch (type)
    {
    case ARRAY_CHAR:
        effectiveSize = size * sizeof(char);
        break;
    case ARRAY_INT:
        effectiveSize = size * sizeof(int);
        break;
    default:
        break;
    }

    GenericArray arr = {
        .type = type,
        .size = size,
        .data = malloc(effectiveSize),
    };

    return arr;
}

//Generic print function
void array_print(GenericArray arr){
    switch (arr.type)
    {
    case ARRAY_CHAR:
        for (int i = 0; i < arr.size - 1; i++)
        {
            printf("%c, ", ((char*)arr.data)[i]);
        }
        printf("%c", ((char*)arr.data)[arr.size]);
        printf("\n");
        break;
    case ARRAY_INT:
        for (int i = 0; i < arr.size - 1; i++)
        {
            printf("%d, ", ((int*)arr.data)[i]);
        }
        printf("%d", ((int*)arr.data)[arr.size]);
        printf("\n");
    default:
        break;
    }
}