#include <stdio.h>
#include <string.h>

void naivePatternMatching(char text[], char pattern[]) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Iterate through the text
    for (int i = 0; i <= N - M; i++) {
        int j;

        // Check if the pattern matches the substring of text starting at index i
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If the pattern is found at index i
        if (j == M) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern matches:\n");
    naivePatternMatching(text, pattern);

    return 0;
}
