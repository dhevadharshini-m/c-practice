#include <stdio.h>

void counter() {
    static int count = 0;
    count++;
    printf("Called %d times\n", count);
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
