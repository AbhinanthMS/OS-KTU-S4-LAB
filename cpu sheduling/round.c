#include <stdio.h>

int main() {
    int n, tq, time = 0, remain;
    printf("Enter number of processes and time quantum: ");
    scanf("%d %d", &n, &tq);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    remain = n;
    while (remain > 0) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;
                int exec = (rt[i] > tq) ? tq : rt[i];
                time += exec;
                rt[i] -= exec;
                if (rt[i] == 0) {
                    remain--;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
        if (done) time++;
    }

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", total_wt / n, total_tat / n);
    return 0;
}