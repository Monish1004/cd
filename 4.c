#include <stdio.h>
#include <ctype.h>
#include <string.h>

void FIRST(char c);
int count, n = 0;
char prodn[10][10], first[10];

int isPresent(char ch) {
    for (int i = 0; i < n; i++) {
        if (first[i] == ch)
            return 1;
    }
    return 0;
}

int main() {
    int i, choice;
    char c, ch;

    printf("How many productions? : ");
    scanf("%d", &count);
    getchar(); // Consume newline

    printf("Enter %d productions (epsilon = $):\n", count);
    for (i = 0; i < count; i++) {
        scanf("%s", prodn[i]);
    }

    do {
        n = 0;
        printf("\nEnter non-terminal to find FIRST: ");
        scanf(" %c", &c); // space before %c to skip any whitespace

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

void FIRST(char c) {
    int j;
    if (!isupper(c)) {
        if (!isPresent(c))
            first[n++] = c;
        return;
    }

    for (j = 0; j < count; j++) {
        if (prodn[j][0] == c) {
            if (prodn[j][2] == '$') {
                if (!isPresent('$'))
                    first[n++] = '$';
            } else if (islower(prodn[j][2])) {
                if (!isPresent(prodn[j][2]))
                    first[n++] = prodn[j][2];
            } else {
                FIRST(prodn[j][2]);
            }
        }
    }
}
