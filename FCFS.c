#include <stdio.h>
int main()
{
    int pid[15], at[15], bt[15], n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
 
    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }

    printf("Enter arrival times of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
 
    printf("Enter burst times of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
 
    int i, wt[n];
    wt[0]=0;
    int xt=0;
 
    for(i=1; i<n; i++)
    {
        xt+=bt[i-1];
        wt[i]= xt - at[i];
    }
 
    printf("Process ID     Arrival Time     Burst Time     Waiting Time     TurnAround Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", at[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);

        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");

        twt += wt[i];
 
        tat += (wt[i]+bt[i]);
    }
    float att,awt;
 
    awt = twt/n;
 
    att = tat/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f",att);
}