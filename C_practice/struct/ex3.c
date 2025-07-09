#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h" // make sure the path is correct

int main() {
    // Create JSON array
    cJSON *studentsArray = cJSON_CreateArray();

    // Create student 1
    cJSON *student1 = cJSON_CreateObject();
    cJSON_AddStringToObject(student1, "name", "Alice");
    cJSON_AddNumberToObject(student1, "rollno", 101);
    cJSON_AddNumberToObject(student1, "marks", 88);
    cJSON_AddItemToArray(studentsArray, student1);

    // Create student 2
    cJSON *student2 = cJSON_CreateObject();
    cJSON_AddStringToObject(student2, "name", "Bob");
    cJSON_AddNumberToObject(student2, "rollno", 102);
    cJSON_AddNumberToObject(student2, "marks", 95);
    cJSON_AddItemToArray(studentsArray, student2);

    // Convert JSON to string
    char *jsonString = cJSON_Print(studentsArray);

    // Write to file
    FILE *fp = fopen("students.json", "w");
    if (fp) {
        fprintf(fp, "%s\n", jsonString);
        fclose(fp);
    }

    // Free memory
    free(jsonString);
    cJSON_Delete(studentsArray);

    return 0;
}
