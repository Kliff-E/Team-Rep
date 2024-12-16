#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

int boundary(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || ispunct((unsigned char)ch));
}

bool contains_word(const char *line, const char *word) {
    int word_len = strlen(word);

    bool found = 0;
    
    for (int i = 0; line[i] != '\0'; i++) {

        if (strncasecmp(&line[i], word, word_len) == 0) {
    
            if ((i == 0 || boundary(line[i - 1])) && boundary(line[i + word_len])) {
                found = 1;
            }
        }
    }
    
    return (found);  
}

int main() {
    char word[10];
    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    printf("Enter the word to search for: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0; 

    FILE *file = fopen("story.txt", "r");
    if (file == NULL) {
        printf("Failed to open story.txt\n");
        exit(1);
    }

    int found = 0; 
    while (fgets(line, sizeof(line), file)) {
        if (contains_word(line, word)) {
            printf("Line %d: %s", line_number, line);
            found = 1;
        }
        line_number++;
    }

    if (!found) {
        printf("No lines found containing the word '%s'.\n", word);
    }

    fclose(file);

    return 0;
}
