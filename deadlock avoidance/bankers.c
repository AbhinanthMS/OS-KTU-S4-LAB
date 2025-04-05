#include <stdio.h>

int main() {
    int n, m, i, j, f[10] = {0}, alloc[10][10], max[10][10], need[10][10], avail[10], seq[10], ind = 0;

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

    for (i = 0; i < n; i++) 
    for (j = 0; j < m; j++)
     need[i][j] = max[i][j] - alloc[i][j];

    for (int done = 0; done < n;)  
        for (i = 0; i < n; i++) 
            if (!f[i]) {
                for (j = 0; j < m && need[i][j] <= avail[j]; j++);
                if (j == m) {
                    for (j = 0; j < m; j++) avail[j] += alloc[i][j];
                    seq[ind++] = i, f[i] = 1, done++;
                }
            }

    printf("Safe Sequence: ");
    for (i = 0; i < n; i++) printf("P%d ", seq[i]);

    return 0;
}