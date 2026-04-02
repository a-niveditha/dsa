#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void rabin_karp(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    int pattern_hash = 0;
    int text_hash = 0;
    int h = 1;
    int found = 0;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        pattern_hash = (d * pattern_hash + P[i]) % q;
        text_hash    = (d * text_hash    + T[i]) % q;
    }

    printf("Pattern Hash = %d\n", pattern_hash);

    for (int i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            if (strncmp(T + i, P, m) == 0) {
                printf("Pattern found at index: %d\n", i);
                found = 1;
            }
        }

        if (i < n - m) {
            text_hash = (d * (text_hash - T[i] * h) + T[i + m]) % q;
            if (text_hash < 0)
                text_hash += q;
        }
    }

    if (!found)
        printf("Pattern not found\n");
}

int main() {
    char T[1000], P[1000];
    scanf("%s", T);
    scanf("%s", P);
    rabin_karp(T, P);
    return 0;
}
