#include <stdio.h>

void twoSum (int* numbers, int numbersSize, int target, int* indices) {
    int i = 0;
    inj j = numbersSize - 1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            indices[0] = i + 1;
            indices[1] = j + 1;
            return;
        }

        if (sum > target) {
            j--;
        } else {
            i++;
        }
    }
    int main() {
        int numbers[] = {2, 7, 11, 15};
        
    }
}