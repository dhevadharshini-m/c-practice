#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct student {
    int stud_id;        
    int name_len;       
    int struct_size;    
    char stud_name[];   // Flexible Array Member (FAM) - have 0 bytes allocated
};

struct student*  createStudent(int id,char arr[]){
    struct student *s= malloc(sizeof(*s)+sizeof(char)*(strlen(arr)+1));

    s->stud_id=id;
    s->name_len=strlen(arr);
    strcpy(s->stud_name,arr);

    s->struct_size=sizeof(*s)+sizeof(char)*(strlen(arr)+1);
    return s;
}

void printStudent(struct student* s) {
    printf("Student_id : %d\n"
           "Stud_Name : %s\n"
           "Name_Length: %d\n"
           "Allocated_Struct_size: %d\n\n",
           s->stud_id, s->stud_name, s->name_len,
           s->struct_size);

    // Value of Allocated_Struct_size is in bytes here
}


int main(){
    struct student* s1 = createStudent(523, "Cherry");
    struct student* s2 = createStudent(535, "Sanjayulsha");

    printStudent(s1);
    printStudent(s2);

    free(s1);
    free(s2);

    return 0;
}