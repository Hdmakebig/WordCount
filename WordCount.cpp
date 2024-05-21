#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int countWords(FILE *file) {
    int count = 0;
    char c;
    int is_word = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == ',' || c == '\n' || c == '\t') {
            is_word = 0;
        } else if (!is_word) {
            is_word = 1;
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <-c or -w> <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        int charCount = countCharacters(file);
        printf("字符数: %d\n", charCount);
    } else if (strcmp(argv[1], "-w") == 0) {
        int wordCount = countWords(file);
        printf("单词数: %d\n", wordCount);
    } else {
        printf("Invalid option. Please use -c for character count or -w for word count.\n");
    }

    fclose(file);
    return 0;
}