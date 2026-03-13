#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    bool completed[n];

    int i;

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Enter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority (lower number = higher priority): ");
        scanf("%d", &pr[i]);

        completed[i] = false;
    }

    int current_time = 0;
    int completed_count = 0;

    while(completed_count < n) {
        int highest_priority = 9999;
        int selected_process = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == false) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    selected_process = i;
                }
            }
        }

        if(selected_process == -1) {
            current_time++;
        }
        else {
            int start_time = current_time;

            ct[selected_process] = start_time + bt[selected_process];
            tat[selected_process] = ct[selected_process] - at[selected_process];
            wt[selected_process] = tat[selected_process] - bt[selected_process];
            rt[selected_process] = start_time - at[selected_process];

            current_time = ct[selected_process];

            completed[selected_process] = true;
            completed_count++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}

//OUTPU
Enter number of processes: 5

Process 1
Enter Process ID: 1
Enter Arrival Time: 0
Enter Burst Time: 3
Enter Priority (lower number = higher priority): 5

Process 2
Enter Process ID: 2
Enter Arrival Time: 2
Enter Burst Time: 3
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
1       0       3       5       3       3       0       0
2       2       3       3       12      10      7       7
3       3       5       2       8       5       0       0
4       4       4       4       16      12      8       8
5       6       1       1       9       3       2       2

Process returned 0 (0x0)   execution time : 121.726 s
Press any key to continue.
