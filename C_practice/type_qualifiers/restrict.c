#include <stdio.h>

void addArrays(int * restrict a, int * restrict b, int * restrict c, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i] + c[i];
    }
}

int main() {
    int x[3] = {1, 2, 3}, y[3] = {4, 5, 6}, z[3];

    addArrays(x, x, y, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d ", z[i]);  
    }
    return 0;
}
