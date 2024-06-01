#include <stdio.h>

void array_diff(const int* a, int a_size, const int* b, int b_size, int* res, int* res_size) {
    int found;
    *res_size = 0;

    for (int i = 0; i < a_size; i ++) {
        found = 0;
        for (int j = 0; j < b_size; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            res[(*res_size)++] = a[i];
        }
    }
}
