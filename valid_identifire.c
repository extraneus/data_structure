#include <stdio.h>
#include <ctype.h>
#include <string.h>


const char *keywords[] = {
    "int", "float", "return", "if", "else", "for", "while",
    "do", "break", "continue", "void", "char", "double",
    "struct", "union", "long", "short", "unsigned", "signed",
    "switch", "case", "default", "const", "static", "enum",
    "typedef", "goto", "sizeof", "volatile", "register", "extern", "auto"
};

int isKeyword(const char *str) {
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isValidIdentifier(const char *str) {
    if (str[0] == '\0') return 0;
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }

    if (isKeyword(str))
        return 0;

    return 1;
}

int main() {
    char identifier[100];

    printf("Enter a string to check if it's a valid identifier: ");
    fgets(identifier, sizeof(identifier), stdin);
    identifier[strcspn(identifier, "\n")] = '\0'; 

    if (isValidIdentifier(identifier)) {
        printf("\"%s\" is a valid identifier.\n", identifier);
    } else {
        printf(" \"%s\" is NOT a valid identifier.\n", identifier);
    }

    return 0;
}
