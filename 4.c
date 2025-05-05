#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

char prodn[MAX][10];
char first[MAX];
int count, n;

int isPresent(char ch) {
    for (int i = 0; i < n; i++) {
        if (first[i] == ch)
            return 1;
    }
    return 0;
}

void FIRST(char c) {
    // If it's a terminal, add it and return
    if (!isupper(c)) {
        if (!isPresent(c))
            first[n++] = c;
        return;
    }

    // Loop through all productions
    for (int i = 0; i < count; i++) {
        if (prodn[i][0] == c) { // Find rules with LHS == c
            // If production is A -> ε
            if (prodn[i][2] == '$') {
                if (!isPresent('$'))
                    first[n++] = '$';
            } else {
                int j = 2;
                while (prodn[i][j] != '\0') {
                    char sym = prodn[i][j];
                    int prev_n = n;
                    FIRST(sym);

                    // If the symbol doesn't derive ε, stop
                    if (!isPresent('$')) {
                        break;
                    }

                    // Else, check the next symbol
                    // Remove ε to avoid duplicate
                    if (n > prev_n && first[n - 1] == '$') {
                        n--; // Remove epsilon temporarily
                        j++;
                        if (prodn[i][j] == '\0') {
                            if (!isPresent('$')) {
                                first[n++] = '$'; // Add it back if end reached
                            }
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int i, choice;
    char c;

    printf("How many productions? : ");
    scanf("%d", &count);
    getchar(); // flush newline

    printf("Enter %d productions (e.g. E=E+T, use $ for epsilon):\n", count);
    for (i = 0; i < count; i++) {
        scanf("%s", prodn[i]);
    }

    do {
        n = 0;
        memset(first, 0, sizeof(first)); // Clear previous results
        printf("\nEnter non-terminal to find FIRST: ");
        scanf(" %c", &c);

        FIRST(c);

        printf("FIRST(%c) = { ", c);
        for (i = 0; i < n; i++)
            printf("%c ", first[i]);
        printf("}\n");

        printf("Press 1 to continue, any other key to exit: ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}
