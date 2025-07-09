// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// struct Student {
//     char name[20];
//     char password[20];
//     int marks;
//     int available;
// };

// void encodePasswordToAsciiString(const char *plain, char *asciiString) {
//     asciiString[0] = '\0'; 
//     char buffer[10];
//     for (int i = 0; plain[i] != '\0'; i++) {
//         sprintf(buffer, "%d ", (int)plain[i]); 
//         strcat(asciiString, buffer);           
//     }
// }

// void decodePasswordFromAsciiString(const char *asciiString, char *decoded) {
//     int ascii;
//     int index = 0;
//     const char *ptr = asciiString;

//     while (sscanf(ptr, "%d", &ascii) == 1) {
//         decoded[index++] = (char)ascii;
//         while (*ptr != ' ' && *ptr != '\0') ptr++;
//         while (*ptr == ' ') ptr++;
//     }
//     decoded[index] = '\0';
// }


// void addStudent(struct Student **arr, int *size) {
//     (*size)++;
//     *arr = realloc(*arr, (*size) * sizeof(struct Student));

//     struct Student *s = &((*arr)[*size - 1]);

//     printf("Enter name: ");
//     scanf("%s", s->name);

//     char pass[20];
//     printf("Enter password: ");
//     scanf("%s", pass);
//     encodePasswordToAsciiString(pass, s->password);

//     printf("Enter marks: ");
//     scanf("%d", &s->marks);
//     s->available = 1;
//     printf("Student added successfully.\n");
// }

// void printStudents(struct Student *arr, int size) {
//     for (int i = 0; i < size; i++) {
//         if (arr[i].available) {
//             char decoded[20];
//             decodePasswordFromAsciiString(arr[i].password, decoded);
//             printf("Name: %s, Password: %s, Marks: %d\n", arr[i].name, arr[i].password, arr[i].marks);
//         }
//     }
// }

// void findTopper(struct Student *arr, int size) {
//     char res[20];
//     int val = 0;

//     for (int i = 0; i < size; i++) {
//         if (arr[i].available && arr[i].marks > val) {
//             val = arr[i].marks;
//             strcpy(res, arr[i].name);
//         }
//     }
//     printf("Higher mark is %d and scored by %s\n", val, res);
// }

// void deleteStudent(struct Student *arr, int size) {
//     char delname[20];
//     printf("Enter the name of student to delete:\n");
//     scanf("%s", delname);

//     for (int i = 0; i < size; i++) {
//         if (arr[i].available && strcmp(delname, arr[i].name) == 0) {
//             arr[i].available = 0;
//             printf("Student '%s' deleted.\n", delname);
//             return;
//         }
//     }
//     printf("Student not found.\n");
// }

// int main() {
//     struct Student *students = NULL;
//     int count = 0;
//     int choice;

//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Add Student\n");
//         printf("2. Print All Students\n");
//         printf("3. Find Topper\n");
//         printf("4. Delete Student by Name\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 addStudent(&students, &count);
//                 break;
//             case 2:
//                 printStudents(students, count);
//                 break;
//             case 3:
//                 findTopper(students, count);
//                 break;
//             case 4:
//                 deleteStudent(students, count);
//                 break;
//             case 5:
//                 free(students);
//                 return 0;
//             default:
//                 printf("Invalid choice. Try again.\n");
//         }
//     }
// }

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student {
    char name[20];
    char password[100]; // ASCII string
    int marks;
    int available;
};

void encodePasswordToAsciiString(const char *plain, char *asciiString) {
    asciiString[0] = '\0';
    char buffer[10];
    for (int i = 0; plain[i] != '\0'; i++) {
        sprintf(buffer, "%d ", (int)plain[i]);
        strcat(asciiString, buffer);
    }
}

void decodePasswordFromAsciiString(const char *asciiString, char *decoded) {
    int ascii;
    int index = 0;
    const char *ptr = asciiString;

    while (sscanf(ptr, "%d", &ascii) == 1) {
        decoded[index++] = (char)ascii;
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        while (*ptr == ' ') ptr++;
    }
    decoded[index] = '\0';
}

void addStudent() {
    struct Student s;

    printf("Enter name: ");
    scanf("%s", s.name);

    char pass[20];
    printf("Enter password: ");
    scanf("%s", pass);
    encodePasswordToAsciiString(pass, s.password);

    printf("Enter marks: ");
    scanf("%d", &s.marks);
    s.available = 1;

    FILE *fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("Student added successfully.\n");
}

void printStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.available) {
            char decoded[20];
            decodePasswordFromAsciiString(s.password, decoded);
            printf("Name: %s, Password: %s, Marks: %d\n", s.name, decoded, s.marks);
        }
    }

    fclose(fp);
}

void findTopper() {
    struct Student s;
    char topper[20] = "";
    int topMarks = -1;

    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.available && s.marks > topMarks) {
            topMarks = s.marks;
            strcpy(topper, s.name);
        }
    }

    fclose(fp);

    if (topMarks != -1)
        printf("Higher mark is %d and scored by %s\n", topMarks, topper);
    else
        printf("No available student records found.\n");
}

void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb+");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    char nameToDelete[20];
    printf("Enter the name of student to delete: ");
    scanf("%s", nameToDelete);

    struct Student s;
    long pos;
    int found = 0;

    while ((pos = ftell(fp)) >= 0 && fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.available && strcmp(s.name, nameToDelete) == 0) {
            s.available = 0;
            fseek(fp, pos, SEEK_SET);  // move file pointer back
            fwrite(&s, sizeof(struct Student), 1, fp);
            printf("Student '%s' deleted.\n", nameToDelete);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Print All Students\n");
        printf("3. Find Topper\n");
        printf("4. Delete Student by Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printStudents();
                break;
            case 3:
                findTopper();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
