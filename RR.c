#include<stdio.h>
#include<stdlib.h>
int Q[100],head=-1,tail=-1,e;

void enQ(int e)
{
	if(head==-1 && tail==-1)
  {
		tail=0;
		head=0;
	}
	else
		tail=tail+1;
	Q[tail]=e;
}
int deQ()
{
  e=Q[head];
	if(head==tail)
  {
		head=-1;
		tail=-1;
	}
	else
		head=head+1;
	return e;
}
int isQueueEmpty()
{
	return ((tail==-1)&&(head==-1));
}
int main()
{
  int pid[10], at[10], temp_a[10], bt[10], ct[10], wt[10], tat[10], n, pass, sort_p[10], i, temp, bt1[10], tslice, C, j=0;
  float total_tat=0.0, total_wt=0.0;
  printf("Enter the no of processes:  ");
  scanf("%d",&n);
  printf("Enter the value of time slice: ");
  scanf("%d",&tslice);
  printf("\nEnter ATs and BTs\n");
  for(i=0;i<n;i++)
  {
    pid[i]=i+1;
    printf("Process %d:\n",pid[i]);
    scanf("%d%d",&at[i],&bt[i]);
    temp_a[i]=at[i];
    sort_p[i]=pid[i];
    bt1[i]=bt[i];
  }
  for(pass=n-1;pass>=1;pass--)
  {
    for(i=0;i<pass;i++)
    {
      if(temp_a[i]>temp_a[i+1])
      {
        temp=sort_p[i];
        sort_p[i]=sort_p[i+1];
        sort_p[i+1]=temp;

        temp=temp_a[i];
        temp_a[i]=temp_a[i+1];
        temp_a[i+1]=temp;
      }
    }
  }
  C=at[sort_p[0]-1];
  enQ(sort_p[0]-1);
  i=0;
  while(!isQueueEmpty())
  {
    temp=deQ();
        if(bt1[temp]>=tslice)
        {
          bt1[temp]=bt1[temp]-tslice;
          C+=tslice;
          if(bt1[temp]==0)
          {
            ct[temp]=C;
            if(i==0)
            {
              i=1;
              j=1;
            }
            while((j<n)&&at[sort_p[j]-1]<=C)
            {
              enQ(sort_p[j]-1);
              j++;
            }
            if(isQueueEmpty()&&(j<n))
            {
              enQ(sort_p[j]-1);
              C=at[sort_p[j]-1];
              j++;
            }
          }
          else
          {
            if(i==0)
            {
              j=1;
              i=1;
            }
            while((j<n)&&at[sort_p[j]-1]<=C)
            {
              enQ(sort_p[j]-1);
              j++;
            }
            enQ(temp);
            }
          }
          else
          {
            C+=bt1[temp];
            bt1[temp]=0;
            ct[temp]=C;
            if(i==0)
            {
              j=1;
              i=1;
            }
            while((j<n)&&at[sort_p[j]-1]<=C)
            {
              enQ(sort_p[j]-1);
              j++;
            }
            if(isQueueEmpty()&&j<n)
            {
              enQ(sort_p[j]-1);
              C=at[sort_p[j]-1];
              j++;
            }
          }
  }
  for(i=0;i<n;i++)
  {
      tat[i]=ct[i]-at[i];
      wt[i]=tat[i]-bt[i];
      total_tat+=tat[i];
      total_wt+=wt[i];
  }

  printf("\nProcess ID\t\tArrival Time\t\tBurst Time\t\tTurnAround Time\t\tWaiting Time\n");
  for(i=0;i<n;i++)
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",pid[i],at[i],bt[i],tat[i],wt[i]);
  printf("\nAvg. TurnAround Time: %f\nAvg. Waiting Time: %f\n",(total_tat/n),(total_wt/n));
}