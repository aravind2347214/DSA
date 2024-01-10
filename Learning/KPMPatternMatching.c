#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the longest proper prefix which is also a suffix
void computeLPSArray(char pattern[], int M, int lps[]) {
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    lps[0] = 0; // lps[0] is always 0

    // Calculate lps[i] for i = 1 to M-1
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP pattern matching
void kmpPatternMatching(char text[], char pattern[]) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Create lps[] that will hold the longest prefix suffix values for the pattern
    int *lps = (int *)malloc(sizeof(int) * M);
    if (lps == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Preprocess the pattern to calculate the lps array
    computeLPSArray(pattern, M, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            // Pattern found at index i-j
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    free(lps);
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern matches:\n");
    kmpPatternMatching(text, pattern);

    return 0;
}
