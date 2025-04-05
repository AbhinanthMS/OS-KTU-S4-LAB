#include <stdio.h>

typedef struct {
    int id, at, bt, pr;
} Process;

void sort(Process p[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((p[j].pr > p[j + 1].pr && p[j].at <= p[j + 1].at) || (p[j].at > p[j + 1].at)) {
                Process t = p[j]; p[j] = p[j + 1]; p[j + 1] = t;
            }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].id = i + 1;
    }

    sort(p, n);
    int time = 0, wt, tat, ct;
    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        time = (time >= p[i].at) ? time + p[i].bt : p[i].at + p[i].bt;
        ct = time;
        tat = ct - p[i].at;
        wt = tat - p[i].bt;
        total_wt += wt;
        total_tat += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pr, ct, wt, tat);
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n,", total_tat / n);
    return 0;
}