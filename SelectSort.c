// Goudi Dwaish
// COT4500-23Spring 0001
// March 21, 2023
// Assignment 4
// Professor Juna Parra


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function implements the selection sort algorithm to sort the given array of integers in ascending order.
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        // Find the minimum element in the unsorted part of the array and swap it with the first element of the unsorted part.
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n = 10; // array size
    int *arr = (int*) malloc(n * sizeof(int)); // dynamically allocate memory for the array
    srand(time(NULL)); // seed the random number generator with current time

    // Fill the array with random numbers between 0 and 99.
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Measure the execution time of selection sort algorithm.
    clock_t t;
    t = clock();
    selectionSort(arr, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    // Print the sorted array.
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the execution time.
    printf("Selection sort execution time: %f seconds\n", time_taken);

    // Release the memory allocated for the array.
    free(arr);

    return 0;
}
