#include <stdio.h>

typedef struct {
    int id, at, bt;
} Process;

void sort(Process p[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j - 1].at) {  
                Process t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
    }

    sort(p, n);  

    int time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;
    int isCompleted[n];  
    for (int i = 0; i < n; i++) isCompleted[i] = 0;

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    while (completed < n) {
        int minIndex = -1;

        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && p[i].at <= time) {
                if (minIndex == -1 || p[i].bt < p[minIndex].bt)
                    minIndex = i;
            }
        }

        if (minIndex == -1) {
            time++;
            continue;
        }

        time += p[minIndex].bt;
        int ct = time;
        int tat = ct - p[minIndex].at;
        int wt = tat - p[minIndex].bt;
        total_wt += wt;
        total_tat += tat;
        isCompleted[minIndex] = 1;
        completed++;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[minIndex].id, p[minIndex].at, p[minIndex].bt, ct, wt, tat);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);

    return 0;
}
