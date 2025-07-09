#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    int len = 0;

    printf("Enter a line: ");
    int read = getline(&line, &len, stdin);

    if (read != -1) {
        printf("You entered: %s", line);
    }

    free(line); 
    return 0;
}
