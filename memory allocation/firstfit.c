#include <stdio.h>

int main() {
    int b[10], p[10], a[10], frag[10], m, n;

    printf("Enter number of blocks: ");
    scanf("%d", &m);
    printf("Enter block sizes:\n");
    for (int i = 0; i < m; i++) 
        scanf("%d", &b[i]);

    printf("Enter number of files: ");
    scanf("%d", &n);
    printf("Enter file sizes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i < n; i++) { 
        int bi = -1;
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                bi = j;  
                break;
            }
        }
        if (bi != -1) {
            frag[i] = b[bi] - p[i];
            b[bi] -= p[i];
        } else {
            frag[i] = -1;
        }
        a[i] = bi;
    }

    printf("\nP.No\tSize\tBlock\tFragment\n");
    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            printf("P%d\t%d\tB%d\t%d\n", i + 1, p[i], a[i] + 1, frag[i]);
        else
            printf("P%d\t%d\tNA\tNA\n", i + 1, p[i]);

    return 0;
}
