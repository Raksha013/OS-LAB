#include <stdio.h>

int main() {

    int n, i, completed = 0, current_time = 0;
    int pid[20], at[20], bt[20], rt[20], ct[20], tat[20], wt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(completed < n) {

        int min = 9999;
        int index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                index = i;
            }
        }

        if(index == -1) {
            current_time++;
        } else {

            rt[index]--;
            current_time++;

            if(rt[index] == 0) {

                ct[index] = current_time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];

                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}

output
Enter number of processes: 2
Enter Arrival Time and Burst Time for P1: 4
28
Enter Arrival Time and Burst Time for P2: 12
8

PID     AT      BT      CT      TAT     WT
P1      4       28      40      36      8
P2      12      8       20      8       0
