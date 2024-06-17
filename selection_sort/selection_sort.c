#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp * temp;
}

int findSmallestIndex(int arr[], int n, int start) {
    int smallestIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

void selectionSort(int arr[], int n) {
    int smallestIndex;
    for (int i = 0; i < n - 1; i++) {
        smallest = findSamllestIndex(arr, n, i);
        swap(&arr[i], &arr[smallestIndex]);
    }
}

int main() {
    int arr[] = {5,3,6,2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}