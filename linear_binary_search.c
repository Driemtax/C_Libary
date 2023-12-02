#include <stdio.h>
#include <stdlib.h>

int* array_malloc(int size){
    int *ptr = (int*) malloc(size*sizeof(int));

    return ptr;
}

void randomize_array(int *arr, int size){
    printf("Random Array: \n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()% size; //wir brauchen ja eig kein random array
        //arr[i] = i;
        printf("%d, ", arr[i]);
    }
}

int linear_search(int *arr, int key, int size){
    //int size = sizeof(arr) / sizeof(arr[0]); geht nicht weil sizeof(arr) die Größte des Pointers ist. Gibt keine Möglichkeit die Größe hier zu ermitteln oder? Kennst du was?

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("\n");
            return i;
        }
    }
    printf("\n");
    return -1;

}

int binary_search(int *arr, int key, int size){
    
}

int main(){
    int size = 100;
    int key = 5;
    int *ptr = array_malloc(size);

    //randomize array
    randomize_array(ptr, size);

    //linear Search
    int result = linear_search(ptr, key, size);
    if (result)
    {
        printf("The searched Key is at Index: %d\n", result);
    }
    else{
        printf("The key is not in the array.");
    }

    free(ptr);
}