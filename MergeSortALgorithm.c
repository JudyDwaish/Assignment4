// Goudi Dwaish
// COT4500-23Spring 0001
// March 21, 2023
// Assignment 4
// Professor Juna Parra

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left[], int right[], int nL, int nR) {
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < nL) {
        arr[k++] = left[i++];
    }
    while (j < nR) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((n - mid) * sizeof(int));
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, right, mid, n - mid);
    free(left);
    free(right);
}

int main() {
    int n = 10;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    clock_t start = clock();
    mergeSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Merge Sort algorithm to sort an array of size %d is %lf seconds.\n", n, time_taken);
    return 0;
}

