#include<stdlib.h>
#include<stdio.h>

int main(){
    char name[20];
// scanf("%s", name);        // Stops at space
fgets(name,20,stdin);   // Accepts spaces
puts(name);
    return 0;
}
