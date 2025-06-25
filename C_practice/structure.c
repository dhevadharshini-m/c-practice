#include <stdio.h>

struct hello
{
    char a;
    char b;
    int n;
};


int main(int argc, char const *argv[])
{
    struct hello h1;
    printf("Size of struct hello: %zu bytes\n", sizeof(h1));
    struct hello* ptr = &h1;
    ptr->a='a';
    ptr->b='b';


    char* p=&(ptr->a);

    printf("%d\n", *(p+2));

    printf("Size of pointer to struct hello: %zu bytes\n", sizeof(ptr));

    return 0;
}


