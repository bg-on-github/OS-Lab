#include<stdio.h>
int main()
{
    int n, i, j, m, temp, time = 0, tbt = 0;
    float avg_wt = 0, avg_tat = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n], at[n], completed[n];
    printf("Enter the arrival time and burst time for processes:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0; 
        tbt += bt[i]; 
    }
    while(time < tbt)
    {
        m = -1;
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(m == -1 || bt[i] < bt[m])
                {
                    m = i; 
                }
            }
        }
        if(m == -1)
        {
            time++; 
            continue;
        }
        wt[m] = time - at[m]; 
        tat[m] = wt[m] + bt[m]; 
        time += bt[m]; 
        completed[m] = 1; 
    }
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);
}