#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int rt[n];              // remaining time
    int ct[n], tat[n], wt[n], resp[n];
    int started[n];

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);

        printf("Enter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority (lower number = higher priority): ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
        started[i] = 0;
    }

    int current_time = 0;
    int completed = 0;

    while(completed < n) {

        int highest_priority = 9999;
        int selected = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && rt[i] > 0) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    selected = i;
                }
            }
        }

        if(selected == -1) {
            current_time++;
        }
        else {

            if(started[selected] == 0) {
                resp[selected] = current_time - at[selected];
                started[selected] = 1;
            }

            rt[selected] = rt[selected] - 1;
            current_time++;

            if(rt[selected] == 0) {

                ct[selected] = current_time;

                tat[selected] = ct[selected] - at[selected];

                wt[selected] = tat[selected] - bt[selected];

                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i], resp[i]);
    }

    return 0;
}



// OUTPUT
Enter number of processes: 5

Process 1
Enter Process ID: 1
Enter Arrival Time: 0
Enter Burst Time: 3
Enter Priority (lower number = higher priority): 5

Process 2
Enter Process ID: 2
Enter Arrival Time: 2
Enter Burst Time: 2
Enter Priority (lower number = higher priority): 3

Process 3
Enter Process ID: 3
Enter Arrival Time: 3
Enter Burst Time: 5
Enter Priority (lower number = higher priority): 2

Process 4
Enter Process ID: 4
Enter Arrival Time: 4
Enter Burst Time: 4
Enter Priority (lower number = higher priority): 4

Process 5
Enter Process ID: 5
Enter Arrival Time: 6
Enter Burst Time: 1
Enter Priority (lower number = higher priority): 1

PID     AT      BT      PR      CT      TAT     WT      RT
1       0       3       5       15      15      12      0
2       2       2       3       10      8       6       0
3       3       5       2       9       6       1       0
4       4       4       4       14      10      6       6
5       6       1       1       7       1       0       0

Process returned 0 (0x0)   execution time : 154.840 s
