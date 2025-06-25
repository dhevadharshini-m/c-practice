    #include <stdio.h>

    union Person{
        char name[10];
        int age;
        long int phone;
    }p;

    int main(){
        printf("Enter name: ");
        scanf("%s", p.name);
        printf("Enter age: ");
        scanf("%d", &p.age);
        printf("Enter phone number: ");
        scanf("%ld", &p.phone);
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Phone: %ld\n", p.phone);
        printf("Size of struct Person: %zu bytes\n", sizeof(p));
        printf("Size of name: %zu bytes\n", sizeof(p.name));
        printf("Size of age: %zu bytes\n", sizeof(p.age));
        printf("Size of phone: %zu bytes\n", sizeof(p.phone));
        printf("%d",p.age);
        printf("%s",p.name);
        printf("\n");
    }