#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Function to check if a word is a keyword
void checkKeywordOrIdentifier(char str[MAX]) {
    const char *keywords[] = {"for", "while", "do", "int", "float", "char", "double", "static", "switch", "case"};
    int isKeyword = 0;

    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            isKeyword = 1;
            break;
        }
    }

    if (isKeyword) {
        printf("%s is a keyword\n", str);
    } else {
        printf("%s is an identifier\n", str);
    }
}

int main() {
    FILE *f1, *f2, *f3;
    char c, str[MAX];
    int i = 0, tokenValue = 0, k = 0, lineno = 0, num[MAX];

    // Open the input file
    printf("Enter a C program (Ctrl+D to end input):\n");

    f1 = fopen("test.txt", "w");
    if (f1 == NULL) {
        printf("Error opening the file\n");
        return 1;
    }
    while ((c = getchar()) != EOF) {
        putc(c, f1);  // Write input to the file
    }
    fclose(f1);

    // Open the input file for reading
    f1 = fopen("test.txt", "r");
    if (f1 == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    // Open the output files
    f2 = fopen("identifiers.txt", "w");
    f3 = fopen("specialcharacters.txt", "w");
    if (f2 == NULL || f3 == NULL) {
        printf("Error opening the files\n");
        return 1;
    }

    // Process the input file
    while ((c = getc(f1)) != EOF) {
        // Handle digits (constants)
        if (isdigit(c)) {
            tokenValue = c - '0';
            while (isdigit(c = getc(f1))) {
                tokenValue = tokenValue * 10 + (c - '0');
            }
            num[i++] = tokenValue;
            ungetc(c, f1);  // Push the last non-digit character back into the input
        }
        // Handle identifiers and keywords
        else if (isalpha(c) || c == '_') {
            str[k++] = c;
            while (isalnum(c = getc(f1)) || c == '_') {
                str[k++] = c;
            }
            str[k] = '\0';
            checkKeywordOrIdentifier(str);  // Check if it's a keyword or identifier
            k = 0;  // Reset for the next word
            ungetc(c, f1);  // Push the last non-alphanumeric character back into the input
        }
        // Handle special characters
        else if (!isspace(c)) {
            putc(c, f3);  // Write special characters to the file
        }
        // Handle spaces and newlines (for line counting)
        if (c == '\n') {
            lineno++;
        }
    }

    // Output the numbers
    printf("The numbers in the program are: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", num[j]);
    }
    printf("\n");

    // Close the files
    printf("The program has %d lines\n", lineno);
    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}
 