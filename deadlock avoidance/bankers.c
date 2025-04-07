#include <stdio.h>

int main() {
    int n, m, i, j;
    int f[10] = {0}, alloc[10][10], max[10][10], need[10][10];
    int avail[10], seq[10], ind = 0, done = 0;

    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix:\n");
    for (i = 0; i < n; i++) 
        for (j = 0; j < m; j++) 
            scanf("%d", &max[i][j]);

    printf("Enter available resources: ");
    for (i = 0; i < m; i++) 
        scanf("%d", &avail[i]);

    printf("Need matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int changed;
    do {
        changed = 0;
        for (i = 0; i < n; i++) {
            if (!f[i]) {
                for (j = 0; j < m && need[i][j] <= avail[j]; j++);
                if (j == m) {
                    for (j = 0; j < m; j++) avail[j] += alloc[i][j];
                    seq[ind++] = i;
                    f[i] = 1;
                    done++;
                    changed = 1;
                }
            }
        }
    } while (changed);

    if (done == n) {
        printf("System is in a SAFE state.\nSafe Sequence: ");
        for (i = 0; i < n; i++) printf("P%d ", seq[i]);
    } else {
        printf("System is in an UNSAFE state. \n");
    }

    return 0;
}
