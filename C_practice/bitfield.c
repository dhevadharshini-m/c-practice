#include <stdio.h>

#pragma pack(1)
struct test {
   unsigned int x;
    long int y:24;
    unsigned int z;
};

int main()
{
    struct test a;
    printf("%zu\n", sizeof(struct test));
    printf("%zu\n", sizeof(a.x));
//    printf("%zu\n", sizeof(a.y));
    printf("%zu\n", sizeof(a.z));


    return 0;
}