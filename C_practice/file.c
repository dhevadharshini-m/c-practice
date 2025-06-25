#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num;
    FILE *file;

    // file= fopen("pracfile.txt","w");
    // if(file == NULL){
    //     printf("Error opening file.\n");
    //     return 1;
    // }
    // char text[100];
    // printf("Enter the text:");
    // fgets(text, sizeof(text), stdin);
    // fprintf(file, "%s", text);
    // fclose(file);

    file= fopen("pracfile.txt","r");
    char ch;
    while((ch=fgetc(file))!=EOF){
        putchar(ch);
    }
    
    fclose(file);
}