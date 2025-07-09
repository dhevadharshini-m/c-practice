#include <stdio.h>
#include<string.h>

int main(){
    char str[20];
    //scanf("%s\n",str);

    char inp[20];
    fgets(inp,20,stdin);

    for(int i=0;i<20;i++){
        printf("%c ",inp[i]);
    }

   // printf("%s\n",str);
    puts(inp);

}
// \0 (null terminator) is always added by fgets.
// \n (newline) is added only if it fits in the buffer before hitting size - 1.