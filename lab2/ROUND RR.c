#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n], resp[n];
    int visited[n];

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);

        printf("Enter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
        visited[i] = 0;
        resp[i] = -1;
    }

    int queue[100];
    int front = 0, rear = 0;

    int current_time = 0;
    int completed = 0;

    float total_wt = 0, total_tat = 0;

    while(completed < n) {

        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if(front == rear) {
            current_time++;
            continue;
        }

        int p = queue[front++];

        if(resp[p] == -1)
            resp[p] = current_time - at[p];

        if(rt[p] > tq) {

            rt[p] -= tq;
            current_time += tq;

            for(int i = 0; i < n; i++) {
                if(at[i] <= current_time && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }

            queue[rear++] = p;
        }
        else {

            current_time += rt[p];
            rt[p] = 0;

            ct[p] = current_time;

            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            total_wt += wt[p];
            total_tat += tat[p];

            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i],
               ct[i], tat[i], wt[i], resp[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}


//output
Enter number of processes: 5
Enter Time Quantum: 2

Process 1
Enter Process ID: 1
Enter Arrival Time: 0
Enter Burst Time: 5

Process 2
Enter Process ID: 2
Enter Arrival Time: 1
Enter Burst Time: 3

Process 3
Enter Process ID: 3
Enter Arrival Time: 3
Enter Burst Time: 1

Process 4
Enter Process ID: 4
Enter Arrival Time: 2
Enter Burst Time: 2

Process 5
Enter Process ID: 5
Enter Arrival Time: 4
Enter Burst Time: 3

PID     AT      BT      CT      TAT     WT      RT
1       0       5       13      13      8       0
2       1       3       12      11      8       1
3       3       1       9       6       5       5
4       2       2       6       4       2       2
5       4       3       14      10      7       5

Average Waiting Time = 6.00
Average Turnaround Time = 8.80
