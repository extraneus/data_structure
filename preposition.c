#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

// List of common prepositions
const char *prepositions[] = {
    "at", "in", "on", "by", "with", "about", "against",
    "between", "into", "through", "during", "before",
    "after", "above", "below", "to", "from", "up",
    "down", "over", "under"
};

int is_preposition(const char *word) {
    int num_prepositions = sizeof(prepositions) / sizeof(prepositions[0]);
    for (int i = 0; i < num_prepositions; i++) {
        if (strcmp(word, prepositions[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to convert a word to lowercase
void to_lowercase(char *str) {
    for (; *str; ++str) {
        *str = tolower(*str);
    }
}

int main() {
    char sentence[MAX_LEN];
    char word[100];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LEN, stdin);

    // Remove newline character if exists
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("\nPrepositions found:\n");

    char *token = strtok(sentence, " .,!?;:\n");
    while (token != NULL) {
        strncpy(word, token, sizeof(word));
        word[sizeof(word) - 1] = '\0';
        to_lowercase(word);
        if (is_preposition(word)) {
            printf("%s\n", word);
        }
        token = strtok(NULL, " .,!?;:\n");
    }

    return 0;
}
