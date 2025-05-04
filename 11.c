#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int stack[MAX];
int top = -1;

void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void push(){
    if(top == MAX - 1) {
        printf("\nStack overflow! Cannot push more elements.\n");
    } else {
        int value;
        printf("\nEnter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("\n%d pushed onto stack.\n", value);
    }
}

void pop(){
    if(top == -1) {
        printf("\nStack underflow! Cannot pop from an empty stack.\n");
    } else {
        int poppedValue = stack[top];
        top--;
        printf("\n%d popped from stack.\n", poppedValue);
    }
}


int main(){
    int op;
    do {
        printf("\n------- Stack Menu -------\n");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1 : 
                push();
                break;
            case 2 :
                pop();
                break;
            case 3 :
                display();
                break;
            case 4 :
                printf("\nExiting...\n");
                break;
            default :
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(op != 4);
    printf("\nProgram terminated.\n");
    return 0;
}