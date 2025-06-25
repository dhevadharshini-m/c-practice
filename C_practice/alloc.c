#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int* arr;
    int n=3;
    arr= malloc(n*sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("Array elements are: ");
    for(int i=0;i<n;i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
    free(arr); 

    char a[]="Hello, World!";
    char b[20];
    int r=strcmp(a,b);
    if(r == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
        if(r < 0) {
            printf("%d+ String a is less than string b.\n",r);
        } else {
            printf("%d+ String a is greater than string b.\n",r);
        }
    }
    strcpy(b,a);
    printf("Copied string: %s\n", b);
    return 0;
}