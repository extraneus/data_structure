#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    char pattern[100];
    char input[100];
    regex_t regex;
    int reti;

    printf("Enter Regular Expression: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';  
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  

    reti = regexec(&regex, input, 0, NULL, 0);
    if (!reti) {
        printf("Accepted ✅ (Input matches the regular expression)\n");
    } else if (reti == REG_NOMATCH) {
        printf("Rejected ❌ (Input does not match the regular expression)\n");
    } else {
        char errbuf[100];
        regerror(reti, &regex, errbuf, sizeof(errbuf));
        fprintf(stderr, "Regex match failed: %s\n", errbuf);
        return 1;
    }

    regfree(&regex);
    return 0;
}
