#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct table {
    char var[20];
    int value;
};

struct table tb[20];

int n = 0;

void display(){
    printf("\nVariable\tValue\n");
    printf("---------\t-----\n");  

    for(int i = 0; i < n; i++) {
        printf("%s\t\t%d\n", tb[i].var, tb[i].value);
    }
    printf("\n");
}

void create(){
    printf("Enter the number of variables : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter variable name: ");
        scanf("%s", tb[i].var);
        printf("Enter variable value: ");
        scanf("%d", &tb[i].value);

        while(tb[i].var[0] >= '1' && tb[i].var[0] <= '9') {
            printf("Invalid variable name. Please enter a valid variable name: ");
            scanf("%s", tb[i].var);
        }
        for(int j = 0; j < i; j++) {
            if(strcmp(tb[i].var, tb[j].var) == 0) {
                printf("Variable name already exists. Please enter a different variable name: ");
                scanf("%s", tb[i].var);
                i--;
                break;
            }
        }
    }
    printf("\n");
    printf("Variables created successfully.\n");
    display();

}

void insert(){
    char buff[20];

    if(n >= 20) {
        printf("Table is full. Cannot insert more variables.\n");
        return;
    }
    printf("Enter variable name: ");
    scanf("%s", tb[n].var);
    printf("Enter variable value: ");
    scanf("%d", &tb[n].value);

    while(tb[n].var[0] >= '1' && tb[n].var[0] <= '9') {
        printf("Invalid variable name. Please enter a valid variable name: ");
        scanf("%s", tb[n].var);
    }
    for(int j = 0; j < n; j++) {
        if(strcmp(tb[n].var, tb[j].var) == 0) {
            printf("Variable name already exists. Please enter a different variable name: ");
            return;
        }
    }
    n++;
    printf("Variable inserted successfully.\n");
    display();
}

void modify(){
    char buff[20];
    printf("Enter variable name to modify: ");
    scanf("%s", buff);
    int found = -1;
    for(int i = 0; i < n; i++) {
        if(strcmp(tb[i].var, buff) == 0) {
            found = i;
            break;
        }
    }
    if(found == -1) {
        printf("Variable not found.\n");
        return;
    }
    printf("Enter new value for %s: ", tb[found].var);
    scanf("%d", &tb[found].value);
    printf("Variable modified successfully.\n");
    display();
}

void search(){
    char buff[20];
    printf("Enter variable name to search: ");
    scanf("%s", buff);
    int found = -1;
    for(int i = 0; i < n; i++) {
        if(strcmp(tb[i].var, buff) == 0) {
            found = i;
            break;
        }
    }
    if(found == -1) {
        printf("Variable not found.\n");
        return;
    }
    printf("Variable %s found with value %d.\n", tb[found].var, tb[found].value);
}

int main(){
    int op;

    do {
        printf("\n1. Display\n2. Create\n3. Insert\n4. Modify\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                display();
                break;
            case 2:
                create();
                break;
            case 3:
                insert();
                break;
            case 4:
                modify();
                break;
            case 5:
                search();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(op != 6);
    printf("Exiting the program.\n");
    return 0;
}