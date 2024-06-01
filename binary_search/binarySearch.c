#include <stdio.h>

int binarySearch (int list[], int size, int item) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (high + low) / 2;
        int kick = list[mid];
        if (kick == item) {
            return mid;
        }
        if (chute > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}