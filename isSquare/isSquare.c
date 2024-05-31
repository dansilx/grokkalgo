#include <math.h>
#include <stdbool.h>

bool is_square (int n) {
    if (n < 0) {
        return false;
    } else {
        for (int i = 0; i <= n; i++) {
            if (i * i == n) {
                return true;
            } else if (i * i > n) {
                return false;
            }
        }
    }
    return false;
}