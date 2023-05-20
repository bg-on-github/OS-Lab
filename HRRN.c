#include <stdio.h>
struct process
{
	int no;
	int at, bt, ct, wt, tt;
	int completed;
} p[10];

int n;
void sortByArrival()
{
	struct process temp;
	int i, j;
	for (i = 0; i < n - 1; i++)
  {
		for (j = i + 1; j < n; j++)
    {
			if (p[i].at > p[j].at)
      {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void main()
{
	int i, j, t, sum_bt = 0;
	printf("Enter number of processes: ");
  scanf("%d", &n);
	float avgwt = 0, avgtt = 0;
  printf("Enter AT, BT:\n");
	for (i = 0; i < n; i++)
  {
    printf("Process %d\n", (i+1));
		p[i].no = i;
		scanf("%d", &p[i].at);
		scanf("%d", &p[i].bt);
		p[i].completed = 0;
		sum_bt += p[i].bt;
	}
	sortByArrival();
	printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
	for (t = p[0].at; t < sum_bt;)
  {
		float hrr = -9999;
		float temp;
		int loc;
		for (i = 0; i < n; i++)
    {
			if (p[i].at <= t && p[i].completed != 1)
      {
				temp = (p[i].bt + (t - p[i].at)) / p[i].bt;
				if (hrr < temp)
        {
					hrr = temp;
					loc = i;
				}
			}
		}
		t += p[loc].bt;
		p[loc].wt = t - p[loc].at - p[loc].bt;
		p[loc].tt = t - p[loc].at;
		avgtt += p[loc].tt;
		p[loc].completed = 1;
		avgwt += p[loc].wt;
		printf("\n%d\t\t%d\t\t", p[loc].no, p[loc].at);
		printf("%d\t\t%d\t\t%d", p[loc].bt, p[loc].wt, p[loc].tt);
	}
	printf("\nAverage waiting time:%f\n", avgwt / n);
	printf("Average Turnaround time:%f\n", avgtt / n);
}