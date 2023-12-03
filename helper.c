#include <helper.h>
#include <stdio.h>

void randomize_array(int *arr, int size){
    printf("Random Array: \n");
    for (int i = 0; i < size; i++)
    {
        //arr[i] = rand()% size; //wir brauchen ja eig kein random array fürs Suchen. (Binary funktioniert auch nicht mit random Array);
        arr[i] = i;  //zum Testen mit key=5 praktisch muss man nicht so lang debuggen
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int* array_malloc(int size){
    int *ptr = (int*) malloc(size*sizeof(int));

    return ptr;
}