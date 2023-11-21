#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, A, count = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    
    int N[n], alloc[n], max[n], work[n], finish[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter Allocation of P:%d", i + 1);
        scanf("%d", &alloc[i]);
        printf("\nEnter the Maximum of P:%d", i + 1);
        scanf("%d", &max[i]);
        N[i] = max[i] - alloc[i];
        work[i] = alloc[i];
        finish[i] = 0;
    }

    printf("\nEnter the available:");
    scanf("%d", &A);

    while (count != n) {
        int safe = 0; // Flag to check if the system is in a safe state

        for (i = 0; i < n; i++) {
            if (finish[i] == 0 && N[i] <= A) {
                printf("P%d ", i + 1);
                A += alloc[i];
                finish[i] = 1;
                count++;
                safe = 1; // Mark that a process was executed in this iteration
            }
        }

        if (!safe) {
            printf("\nUnsafe state! System has entered a deadlock.\n");
            break;
        }
    }

    return 0;
}
