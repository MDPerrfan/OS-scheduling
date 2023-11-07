#include <stdio.h>

int main() {
    int n, ts;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int at[n], bt[n], temp_bt[n];
    for (int i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        temp_bt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &ts);
    int wt = 0, tat = 0;
    int done, t = 0;
    printf("Gantt Chart: ");
    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (temp_bt[i] > 0) {
                done = 0;
                if (temp_bt[i] > ts) {
                    t += ts;
                    temp_bt[i] -= ts;
                    printf("P%d -> ", i + 1);
                } else {
                    t += temp_bt[i];
                    wt += t - at[i] - bt[i];
                    tat += t - at[i];
                    temp_bt[i] = 0;
                    printf("P%d -> ", i + 1);
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    float avg_wt = (float)wt / n;
    float avg_tat = (float)tat / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    return 0;
}
