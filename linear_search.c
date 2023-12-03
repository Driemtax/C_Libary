#include <stdio.h>
#include <stdlib.h>

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
    return 0;

}