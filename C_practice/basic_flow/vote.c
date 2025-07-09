#include<stdio.h>

int main(){
    int age;
    char name[20];
    printf("Enter the name: ");
    scanf("%s",&name); // %s expects a char* but we have &name denoting the entire array char[20], as char * denotes to the first element and char[20] denotes the entire array, the error rises
    printf("Enter the age: ");
    scanf("%d",&age);
    if(age>18){
        printf("Can Vote: %d\n",age);
    }
    else{
        printf("Cant Vote : %d\n",age);
    }
    return 0;
}

//to execute as preprocessor,assembly,object ,link and executable, follow the steps below
// gcc -E -o vote.i vote.c
// gcc -S -o vote.s vote.i
// as vote.s -o vote.o
// gcc -o vote vote.o
// ./vote