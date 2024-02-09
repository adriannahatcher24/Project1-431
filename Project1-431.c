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

    int inside_comment = 0; // Flag to indicate if inside a comment block

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (!inside_comment && line[i] == '{') {
                printf("%c", line[i]);
            } else if (!inside_comment && line[i] == '}') {
                printf("%c", line[i]);
            } else if (!inside_comment && line[i] == '(') {
                printf("%c", line[i]);
            } else if (!inside_comment && line[i] == ')') {
                printf("%c", line[i]);
            } else if (line[i] == '/' && i + 1 < len && line[i + 1] == '/') {
                break; // Skip the rest of the line if it's a comment
            }
        }
    }

    fclose(file);

    return 0;
}
