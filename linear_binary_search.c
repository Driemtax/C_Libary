#include <stdio.h>
#include <stdlib.h>
#include <helper.h>
#include <search.h>


int main(){
    int size = 100;
    int key = 5;
    int *ptr = array_malloc(size);

    //randomize array
    randomize_array(ptr, size);

    //ask for search algorithm
    printf("Which algorithm to perform? (l=linear, b=binary): ");
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