#include<stdio.h>
void main()
{
  int min,n,i,j,k=1,at[20],bt[20],wt[20],ct[20],tat[20],pid[20],pri[20],temp,pass,temp_a[20],temp_pri[20],sort_p[20];
  float total_tat=0.0,total_wt=0.0;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter arrival, burst times and priority of the %d processes (in order):\n",n);
  for(i=0;i<n;i++)
  {
    pid[i]=i+1;
    printf("Process %d\n",pid[i]);
    scanf("%d%d%d",&at[i],&bt[i],&pri[i]);
    temp_pri[i]=pri[i];
    temp_a[i]=at[i];
    sort_p[i]=pid[i];
  }
  for(pass=n-1;pass>=1;pass--)
  {
    for(i=0;i<pass;i++)
    {
      if((temp_a[i]>temp_a[i+1])||((temp_a[i]==temp_a[i+1])&&(temp_pri[i]>temp_pri[i+1])))
      {
        temp=temp_pri[i];
        temp_pri[i]=temp_pri[i+1];
        temp_pri[i+1]=temp;
        temp=temp_a[i];
        temp_a[i]=temp_a[i+1];
        temp_a[i+1]=temp;
        temp=sort_p[i];
        sort_p[i]=sort_p[i+1];
        sort_p[i+1]=temp;
      }
    }
  }
  ct[sort_p[0]-1]=at[sort_p[0]-1]+bt[sort_p[0]-1];
  for(i=0;i<n;i++)
  {
    if(i>0)
    {
      temp=ct[sort_p[i-1]-1]>at[sort_p[i]-1]?ct[sort_p[i-1]-1]:at[sort_p[i]-1];
      ct[sort_p[i]-1]=temp+bt[sort_p[i]-1];
    }
    min=k;
    for(j=k;j<n;j++)
    {
      if(ct[sort_p[i]-1]>=at[sort_p[j]-1]&&temp_pri[j]<temp_pri[min])
      {
        temp=temp_pri[j];
        temp_pri[j]=temp_pri[min];
        temp_pri[min]=temp;
        temp=temp_a[j];
        temp_a[j]=temp_a[min];
        temp_a[min]=temp;
        temp=sort_p[j];
        sort_p[j]=sort_p[min];
        sort_p[min]=temp;
      }
    }
    k++;
  }
  for(i=0;i<n;i++)
  {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    total_tat+=tat[i];
    total_wt+=wt[i];
	}
  printf("\nProcess\t\tArrival Time\tPriority\tBurst Time\tWaiting Time\tTurnAround Time\t\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",pid[i],at[i],pri[i],bt[i],wt[i],tat[i]);
  }
  printf("\nAverage Waiting Time = %f\nAverage Turnaround Time = %f\n",(total_wt/n),(total_tat/n));
}