#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id, profit, deadline;
} Job;

typedef struct {
    int level;
    int profit;
    int slots[MAX];        // slots[t] = job id scheduled at time t (0 if empty)
    int selected[MAX];
    int selCount;
} Node;

Node stack[100000];
int top = -1;

void push(Node n) { stack[++top] = n; }
Node pop()        { return stack[top--]; }
int  isEmpty()    { return top == -1; }

int cmpProfit(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int findSlot(int slots[], int deadline) {
    for (int t = deadline; t >= 1; t--)
        if (!slots[t]) return t;
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    Job jobs[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
        jobs[i].id = i + 1;
    }

    qsort(jobs, n, sizeof(Job), cmpProfit);

    int bestProfit = 0;
    int bestSlots[MAX];
    memset(bestSlots, 0, sizeof(bestSlots));

    Node root;
    root.level    = -1;
    root.profit   = 0;
    root.selCount = 0;
    memset(root.slots,    0, sizeof(root.slots));
    memset(root.selected, 0, sizeof(root.selected));
    push(root);

    while (!isEmpty()) {
        Node curr = pop();
        int lvl = curr.level + 1;

        if (lvl == n) continue;

        // Include job[lvl]
        int slot = findSlot(curr.slots, jobs[lvl].deadline);
        if (slot != -1) {
            Node child = curr;
            child.level                      = lvl;
            child.profit                    += jobs[lvl].profit;
            child.slots[slot]                = jobs[lvl].id;  // store job id in slot
            child.selected[child.selCount++] = jobs[lvl].id;

            if (child.profit > bestProfit) {
                bestProfit = child.profit;
                memcpy(bestSlots, child.slots, sizeof(child.slots));
            }
            push(child);
        }

        // Exclude job[lvl]
        Node skip = curr;
        skip.level = lvl;
        push(skip);
    }

    // Collect jobs in time slot order
    printf("Selected Jobs:\n");
    int first = 1;
    for (int t = 1; t < MAX; t++) {
        if (bestSlots[t] != 0) {
            if (!first) printf(" ");
            printf("J%d", bestSlots[t]);
            first = 0;
        }
    }
    printf("\n");
    printf("Total Profit = %d\n", bestProfit);

    return 0;
}