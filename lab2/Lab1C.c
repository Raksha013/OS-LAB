#include <stdio.h>

int main()
{
    int n,i,time=0,remain,tq;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],rt[n],ct[n],tat[n],wt[n],flag[n];

    for(i=0;i<n;i++)
    {
        printf("Enter AT & BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
        flag[i]=0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    remain=n;

    while(remain>0)
    {
        int done=1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                done=0;

                if(rt[i]>tq)
                {
                    time=time+tq;
                    rt[i]=rt[i]-tq;
                }
                else
                {
                    time=time+rt[i];
                    rt[i]=0;
                    ct[i]=time;
                    remain--;
                }
            }
        }

        if(done==1)
            time++;
    }

    float avg_tat=0,avg_wt=0;

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT = %.2f",avg_wt/n);

    return 0;
}
