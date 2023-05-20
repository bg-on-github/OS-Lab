#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_burst_time(int arr[][2], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i][1] > arr[j][1]) {
                swap(&arr[i][0], &arr[j][0]);
                swap(&arr[i][1], &arr[j][1]);
            }
        }
    }
}

int main() {
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int arrival_time[100], burst_time[100], waiting_time[100], turnaround_time[100];
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    int arr[n][2];
    for(i = 0; i < n; i++) {
        arr[i][0] = arrival_time[i];
        arr[i][1] = burst_time[i];
    }
    sort_by_burst_time(arr, n);
    for(i = 0; i < n; i++) {
        arrival_time[i] = arr[i][0];
        burst_time[i] = arr[i][1];
    }
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    for(i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1] - arrival_time[i] + arrival_time[i-1];
        if(waiting_time[i] < 0)
        {
            waiting_time[i] = 0;
        }
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    
    // Calculate average waiting time and average turnaround time
    for(i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Print results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    
    return 0;
}