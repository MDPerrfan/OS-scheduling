#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void sjf(struct Process a[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = -1;
        int shortestBurst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i].at <= currentTime &&
                a[i].bt < shortestBurst &&
                a[i].ct == -1) {
                shortest = i;
                shortestBurst = a[i].bt;
            }
        }
        if (shortest == -1) {
            currentTime++;
        } else {
            a[shortest].ct = currentTime + a[shortest].bt;
            a[shortest].tat = a[shortest].ct - a[shortest].at;
            a[shortest].wt = a[shortest].tat - a[shortest].bt;
            currentTime = a[shortest].ct;
            completed++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process a[n];

    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &a[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &a[i].bt);
        a[i].ct = -1;
    }

    sjf(a, n);
    printf("-----------------------------------------\n");
    printf("| Process | Turnaround Time |Waiting Time \n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("|   P%d    |      %2d      |      %2d     \n", a[i].id,
               a[i].tat, a[i].wt);
    }
    printf("------------------------------------------\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].ct>a[j+1].ct){
                struct Process temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
     printf("\nGantt Chart:\n");
     for(int i=0;i<n;i++){
        printf("|P%d %d\t",a[i].id,a[i].ct);
     }
    double avgTurnaroundTime = 0;
    double avgWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += a[i].tat;
        avgWaitingTime += a[i].wt;
    }

    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    printf("\nAverage Turnaround Time: %.2lf\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2lf\n", avgWaitingTime);

    return 0;
}

