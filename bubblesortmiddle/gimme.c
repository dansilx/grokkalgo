#include <stdio.h>

//#define SIZE 3;

int gimme(int arr[3]) {
    int sorted[3];
    for (int i = 0; i < 3; i++) {
        sorted[i] = arr[i];
    }

    for(int i = 0; i < 3; ) {
        for (int j = i+1; j < 3; j++) {
            if (sorted[i] > sorted[j]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    int mid = sorted[1];

    for (int i = 0; i < 3; i++) {
        if (arr[i] == mid) {
            return i;
        }
    }

    return -1
}

int main() {
    int arr[3] = {2, 3, 1};
    printf("%d\n", gimme(arr));
    return 0;
}

main();