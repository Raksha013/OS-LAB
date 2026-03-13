#include<stdio.h>

int main()
{
    int n,i,time=0,remain,highest;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],pr[n],ct[n],tat[n],wt[n],done[n];

    for(i=0;i<n;i++)
    {
        printf("Enter AT, BT and Priority for P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        done[i]=0;
    }

    remain=n;

    while(remain>0)
    {
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0)
            {
                if(highest==-1 || pr[i] < pr[highest])
                    highest=i;
            }
        }

        if(highest==-1)
        {
            time++;
        }
        else
        {
            time = time + bt[highest];
            ct[highest] = time;
            done[highest] = 1;
            remain--;
        }
    }

    float avg_tat=0,avg_wt=0;

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT = %.2f",avg_wt/n);

    return 0;
}
