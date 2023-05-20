#include <stdio.h>
int main()
{
  printf("Enter number of processes and then resources:\n");
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
  printf("Enter the allocation matrix:\n");
  int alloc[n][m];
  for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
      scanf("%d", &alloc[i][j]);
  }
  printf("Enter the MAX matrix:\n");
	int max[n][m];
  for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
      scanf("%d", &max[i][j]);
  }
  printf("Finally, enter the availability matrix:\n");
	int avail[m];
  for (int i = 0; i < m; i++)
    scanf("%d", &avail[i]);
	int f[n], ans[n], ind = 0;
	for (int k = 0; k < n; k++)
		f[k] = 0;
	int need[n][m];
	for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	for (int k = 0; k < n; k++)
  {
		for (int i = 0; i < n; i++)
    {
			if (f[i] == 0)
      {
				int flag = 0;
				for (int j = 0; j < m; j++)
        {
					if (need[i][j] > avail[j])
          {
						flag = 1;
						break;
					}
				}

				if (flag == 0)
        {
					ans[ind++] = i;
					for (int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
	printf("Hence, a safe sequence could be shown as:\n");
	for (int i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d\n", ans[n - 1]);
	return 0;
}