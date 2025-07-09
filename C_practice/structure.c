#include <stdio.h>

// struct hello
// {
//     char a;
//     char b;
//     int n;
// };


// int main(int argc, char const *argv[])
// {
//     struct hello h1;
//     printf("Size of struct hello: %zu bytes\n", sizeof(h1));
//     struct hello* ptr = &h1;
//     ptr->a='a';
//     ptr->b='b';


//     char* p=&(ptr->a);

//     printf("%d\n", *(p+2));

//     printf("Size of pointer to struct hello: %zu bytes\n", sizeof(ptr));

//     return 0;
// }

// #pragma pack(1)
// struct Student {
//     char name; 
//     int rollNo;        
//     char fav;     
// }s;

// int main(){
//     printf("%zu",sizeof(s));
//     return 0;
// }

union Data {
    char str[4];  // 4 bytes
    int num;      // 4 bytes
    float f;      // 4 bytes
};

int main(){
    union Data d;
d.num = 0x41424344;     // Writing an int
printf("%s\n", d.str);  // Reading as string (char array)
printf("%s", d.str);  // Output: "DCBA" (if null-terminated)
    return 0;
}