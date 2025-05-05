#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char input[100];  // Buffer to store input expression
int i = 0, errorFlag = 0;  // Index for input and error flag (renamed error to errorFlag)

// Function prototypes
void E();  // Rule for E
void Eprime();  // Rule for E'
void T();  // Rule for T
void Tprime();  // Rule for T'
void F();  // Rule for F

// Function to display an error and terminate
void error() {
    printf("Syntax error at position %d\n", i);
    exit(1);  // Exit on error
}

// Skip whitespace characters in the input
void skipWhitespace() {
    while (input[i] == ' ' || input[i] == '\t') {
        i++;
    }
}

int main() {
    // Read the input expression
    printf("Enter an arithmetic expression (e.g., a+a*a): ");
    fgets(input, sizeof(input), stdin);  // Use fgets to avoid buffer overflow

    // Remove the trailing newline character added by fgets
    input[strcspn(input, "\n")] = '\0';

    // Start parsing with the starting non-terminal
    E();

    // If input is fully consumed and no errors, the expression is valid
    if (input[i] == '\0' && errorFlag == 0) {
        printf("\nAccepted..!!!\n");
    } else {
        printf("\nRejected..!!!\n");
    }

    return 0;
}

void E() {  
    T();  
    Eprime(); 
}

void Eprime() {  
    skipWhitespace();  // Skip any whitespaces
    if (input[i] == '+') {  
        i++;  
        T();  
        Eprime();  
    }  
}

void T() {  
    F();  
    Tprime(); 
}

void Tprime() {  
    skipWhitespace();  // Skip any whitespaces
    if (input[i] == '*') {  
        i++;  
        F();  
        Tprime();  
    }  
}

void F() {  
    skipWhitespace();  // Skip any whitespaces
    if (isalnum(input[i])) {
        i++;  // If it's a valid operand, move to the next character
    } 
    else if (input[i] == '(') {  
        i++;  
        E();  
        skipWhitespace();  // Skip any whitespaces after ')'
        if (input[i] == ')') {
            i++;  // Match closing parenthesis
        } else {
            error();  // Error if no closing ')'
        }  
    } 
    else {
        error();  // Invalid character
    }  
}

