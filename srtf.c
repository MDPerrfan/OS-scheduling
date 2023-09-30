#include <stdio.h>

struct Process {
    int id;
    int at;
    int bt;
    int rt;
    int ct;
};

void srtf(struct Process a[], int n) {
    int remain = 0, time = 0, ttat = 0, twt = 0;
    int gchart[100];
    int gct[100];
    int gindex = 0;

    while (remain < n) {
        int smallest = -1;
        for (int i = 0; i < n; i++) {
            if (a[i].at <= time && a[i].rt > 0) {
                if (smallest == -1 || a[i].rt < a[smallest].rt) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++;
            continue;
        }

        a[smallest].rt--;
        gchart[gindex] = smallest;
        gct[gindex] = time + 1;
        gindex++;

        if (a[smallest].rt == 0) {
            remain++;
            a[smallest].ct = time + 1;
            twt += a[smallest].ct - a[smallest].at - a[smallest].bt;
            ttat += a[smallest].ct - a[smallest].at;
        }
        time++;
    }
    printf("\nProcess\t|Turnaround Time|Waiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("\nP%d\t|\t%d\t|\t%d\t", a[i].id,
               a[i].ct - a[i].at,
               a[i].ct - a[i].at - a[i].bt);
    }

    printf("\nGantt Chart:\n");
    for (int i = 0; i < gindex; i++) {
        printf("| P%d %d ", a[gchart[i]].id, gct[i]);
    }

    printf("\nAverage Waiting Time: %f", (float)twt / n);
    printf("\nAverage Turnaround Time: %f", (float)ttat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process a[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter arrival time for process %d: ", i + 1);
        scanf("%d", &a[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &a[i].bt);
        a[i].rt = a[i].bt;
        a[i].id = i + 1;
    }
    srtf(a, n);
    return 0;
}


