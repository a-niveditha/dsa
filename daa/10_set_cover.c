#include <stdio.h>
#include <stdbool.h>

#define MAX_UNIVERSE 100
#define MAX_SETS 100

// Check how many uncovered elements a set can cover
int countUncovered(int set[], bool covered[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (set[i] && !covered[i])
            count++;
    }
    return count;
}

int main() {
    int n, m; // n = universe size, m = number of sets
    printf("Enter number of elements in universe: ");
    scanf("%d", &n);

    printf("Enter number of sets: ");
    scanf("%d", &m);

    int sets[MAX_SETS][MAX_UNIVERSE];

    printf("Enter sets (0/1 matrix):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &sets[i][j]);
        }
    }

    bool covered[MAX_UNIVERSE] = {false};
    bool chosen[MAX_SETS] = {false};

    int coveredCount = 0;

    printf("Selected sets: ");

    while (coveredCount < n) {
        int bestSet = -1;
        int maxCover = -1;

        // Find set covering max uncovered elements
        for (int i = 0; i < m; i++) {
            if (!chosen[i]) {
                int cnt = countUncovered(sets[i], covered, n);
                if (cnt > maxCover) {
                    maxCover = cnt;
                    bestSet = i;
                }
            }
        }

        // If no set can cover remaining elements
        if (bestSet == -1) 
            break;

        chosen[bestSet] = true;
        printf("%d ", bestSet);

        // Mark elements as covered
        for (int j = 0; j < n; j++) {
            if (sets[bestSet][j] && !covered[j]) {
                covered[j] = true;
                coveredCount++;
            }
        }
    }

    printf("\n");

    // Check if full cover achieved
    if (coveredCount < n)
        printf("Universe NOT fully covered\n");
    else
        printf("Universe fully covered\n");

    return 0;
}