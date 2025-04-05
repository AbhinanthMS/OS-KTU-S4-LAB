#include <stdio.h>
typedef struct
{
    int id, at, bt;
    
}process;

void sort(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;

    printf("enter the number of processes:\t");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d :\t", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
    }
    sort(p, n);

    int time = 0, wt, tat, ct;
    float total_tat = 0, total_wt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\twt\n");
    for (int i = 0; i < n; i++)
    {
        time = (time > p[i].at) ? time + p[i].bt : p[i].at + p[i].bt;
        ct = time;
        tat = ct - p[i].at;
        wt = tat - p[i].bt;
        total_tat += tat;
        total_wt += wt;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, ct, tat, wt);
    }

    printf("Average TURNAROUND TIME :%.2f\n", total_tat / n);
    printf("Average WAITING TIME :%.2f", total_wt / n);

    return 0;
}
 