#include <stdio.h>
#include <limits.h>

void printBinary(unsigned int val){
    for(int i=31;i>=0;i--){
        int b= (val>>i)&1; //roght shift to view values
        printf("%d",b);
        if(i%4==0) printf(" ");
    }
    printf("\n");
}

int main() {
    int value = -10;

    printf("Decimal: %d\n", value);
    printf("Binary : ");
    printBinary((unsigned int)value);  // Cast to unsigned to see full binary
    printf("%d\n",INT_MAX);
    printf("%d\n",INT_MIN);
    printf("%ld\n",LONG_MAX);
    printf("%ld\n",LONG_MIN);

    return 0;
}
