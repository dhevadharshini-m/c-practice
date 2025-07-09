    #include <stdio.h>
    #include <string.h>

    union Person{
        char name[10];
        int age;
        long int phone;
    }p;

    union Data {
    int i;
    float f;
    char str[20];
};




    int main(){
        // printf("Enter name: ");
        // scanf("%s", p.name);
        // printf("Enter age: ");
        // scanf("%d", &p.age);
        // printf("Enter phone number: ");
        // scanf("%ld", &p.phone);
        // printf("Name: %s\n", p.name);
        // printf("Age: %d\n", p.age);
        // printf("Phone: %ld\n", p.phone);
        // printf("Size of struct Person: %zu bytes\n", sizeof(p));
        // printf("Size of name: %zu bytes\n", sizeof(p.name));
        // printf("Size of age: %zu bytes\n", sizeof(p.age));
        // printf("Size of phone: %zu bytes\n", sizeof(p.phone));
        // printf("%d",p.age);
        // printf("%s",p.name);
        // printf("\n");
        union Data values[3];
        values[0].f=67.23;
        values[0].i=22;
       // strcpy(values[0].str, "Hello");
        values[1].f=1.11;
        printf("%d\n",values[0].i);
       // printf("%f\n",values[0].f);
        //printf("%s\n",values[0].str);

        printf("%.2f\n",values[1].f);
        //printf("%f\n",values[0].f);
        //can able to access only 1 data at a time, for example in arr[0], we can access only 1 data, as it overwrites the previously written data for each union

    }