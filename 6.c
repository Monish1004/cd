#include <stdio.h>
#include <stdlib.h>

const char *input;
int pos = 0;

char lookahead() {
    return input[pos];
}

void error() {
    printf("Error at position %d\n", pos);
    exit(1);
}

void match(char expected) {
    if (lookahead() == expected) {
        pos++;
    } else {
        error();
    }
}

// Forward declarations
void S();
void L();

void S() {
    if (lookahead() == 'a') {
        match('a');
    } else if (lookahead() == '(') {
        match('(');
        L();
        match(')');
    } else {
        error();
    }
}

void L() {
    S();
    while (lookahead() == ',') {
        match(',');
        S();
    }
}

int main() {
    char buffer[100];
    printf("Enter an input string : ");
    scanf("%s", buffer);

    input = buffer;
    pos = 0;

    S();

    if (lookahead() == '\0') {
        printf("String is successfully parsed.\n");
    } else {
        error();
    }

    return 0;
}

