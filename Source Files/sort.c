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

void test_selection_sort(){
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

void insertion_sort(int *arr, int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j -= 1;
        }

        arr[j+1] = key;
    }
}

void test_insertion_sort(){
    int *arr = array_malloc(SIZE);
    randomize_array(arr, SIZE);

    insertion_sort(arr, SIZE);

    //print Output
    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int* merge(int* left, int* right, int size){
    int* result = array_malloc(size);
    int left_idx = 0; int right_idx = 0;

    int counter = 0;
    while (left_idx < size && right_idx < size)
    {
        if (left[left_idx] <= right[right_idx])
        {
            result[counter] = left[left_idx];
            counter++;
            left_idx++;
        }
        else
        {
            result[counter] = right[right_idx];
            counter++;
            right_idx++;
        }
    }

    while (left_idx < size)
    {
        result[counter] = left[left_idx];
        counter++;
        left_idx++;        
    }
    while (right_idx < size)
    {
        result[counter] = right[right_idx];
        counter++;
        right_idx++;
    }

    return result;
}

int* merge_sort(int *arr, int size){
    if (size <= 1)
    {
        return arr;
    }

    int mid = size / 2;

    int* left = array_malloc(mid);
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    int* right = array_malloc(mid);
    for (int i = mid; i < size; i++)
    {
        right[i] = arr[i];
    }

    left = merge_sort(left, mid);
    right = merge_sort(right, mid);


    return merge(left, right, mid);
}

void test_merge_sort(){
    int *arr = array_malloc(SIZE);
    randomize_array(arr, SIZE);

    merge_sort(arr, SIZE);

    //print Output
    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int main(){
    test_merge_sort();
}