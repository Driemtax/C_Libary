#ifndef HELPER_H
#define HELPER_H

typedef enum {
    ARRAY_INT,
    ARRAY_CHAR,
} DataType;

typedef struct {
    DataType type;
    size_t size;
    void* data;
} GenericArray ;

void randomize_array(int *arr, int size);
int* array_malloc(int size);
char* initialize_char_array(char *arr, int size);
int* initialize_int_array(int *arr, int size);
void swap_numbers(int *a, int *b);
GenericArray arrayCreate(size_t size, DataType type);
void array_print(GenericArray arr);


#endif