#include <stdio.h>

int main() {
    int i=23;
    char ch='a';
    char str[]="Hello";
    float fv=2.3456766666;
    double dv=2.3456788787878687;
    int* ptr=&i;
    unsigned int val=-1;
    __uint64_t value=30;

    //1. Storing the Value (Decimal → Binary) : compiler (gcc,clang)
    //2. Printing the Value (Binary → Decimal) : C standard library (like glibc)
    printf("%d\n",i);
    printf("%x\n",i);
    printf("%o\n",i);

    printf("%c\n",ch);
    printf("%s\n",str);

    printf("%f\n",dv);
    printf("%f\n",fv);
    printf("%u\n",val);
    printf("%ld\n",value);

    printf("Size of int i: %zu bytes\n", sizeof(i));
    printf("Size of char ch: %zu byte\n", sizeof(ch));
    printf("Size of unsigned int val: %zu bytes\n", sizeof(val));
    printf("Size of __uint64_t value: %zu bytes\n", sizeof(value)); // long int uses %ld
    printf("Size of char array str[]: %zu bytes\n", sizeof(str)); // Includes '\0'
    printf("Size of float fv: %zu bytes\n", sizeof(fv));
    printf("Size of double dv: %zu bytes\n", sizeof(dv));
    printf("Size of int* ptr: %zu bytes\n", sizeof(ptr));
}

//So on a 64-bit system, sizeof(...) returns a **long unsigned int**, but you're using %d which is meant for **int**.
//Use %zu for sizeof()