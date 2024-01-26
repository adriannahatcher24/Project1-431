#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char filename[100];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    printf("Enter the filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (line[i] == '{' || line[i] == '}' || line[i] == '(' || line[i] == ')') {
                printf("%c", line[i]);
            }
        }
    }

    fclose(file);

    return 0;
}