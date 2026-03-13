
#include <stdio.h>

int main() {

    int n, i, completed = 0, current_time = 0;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
    int finished[20] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    while(completed < n) {

        int min = 9999;
        int index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && finished[i] == 0 && bt[i] < min) {
                min = bt[i];
                index = i;
            }
        }

        if(index == -1) {
            current_time++;
        } else {

            ct[index] = current_time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            current_time = ct[index];
            finished[index] = 1;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}

output
 Enter number of processes: 4
Enter Arrival Time and Burst Time for P1: 2
7
Enter Arrival Time and Burst Time for P2: 9
1
Enter Arrival Time and Burst Time for P3: 4
6
Enter Arrival Time and Burst Time for P4: 7

9

PID     AT      BT      CT      TAT     WT
P1      2       7       9       7       0
P2      9       1       10      1       0
P3      4       6       16      12      6
P4      7       9       25      18      9
