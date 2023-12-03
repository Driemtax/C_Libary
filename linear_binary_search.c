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
        arr[i] = rand()% size; //wir brauchen ja eig kein random array fürs Suchen. (Binary funktioniert auch nicht mit random Array);
        //arr[i] = i;  //zum Testen mit key=5 praktisch muss man nicht so lang debuggen
        printf("%d, ", arr[i]);
    }
    printf("\n");
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
            printf("\n");
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    printf("\n");
    return 0;
    
}

int main(){
    int size = 100;
    int key = 5;
    int *ptr = array_malloc(size);

    //randomize array
    randomize_array(ptr, size);

    //ask for search algorithm
    printf("Which algorithm to preform? (l=linear, b=binary): ");
    char input;
    scanf(" %c", &input);
    printf("\n");
    int result;

    switch (input)
    {
    case 'l':
        result = linear_search(ptr, key, size);
        break;
    case 'b':
        result = binary_search(ptr, key, size);
        break;
    default:
        break;
    }
    if (result)
    {
        printf("The searched Key is at Index: %d\n", result);
    }
    else{
        printf("The key is not in the array.\n");
    }
    
    free(ptr);
}