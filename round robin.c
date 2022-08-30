#include<stdio.h>
 
int main()
{
      int i, n, total = 0, x, counter = 0, tq;
      int wt = 0, turnaround_time = 0, at[10], bt[10], temp[10];
      float average_wt, average_turnaround_time;
      printf("Enter Total Number of Processes:\n");
      scanf("%d", &n);
      x = n;
      printf("Enter arrival time and burst time of each Process :\n");
      for(i = 0; i < n; i++)
      {
 
 
            scanf("%d", &at[i]);
            scanf("%d", &bt[i]);
 
            temp[i] = bt[i];
      }
 
      printf("Enter Time Quantum:\n");
      scanf("%d", &tq);
      printf("Process ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= tq && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - tq;
                  total = total + tq;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                  wt = wt + total - at[i] - bt[i];
                  turnaround_time = turnaround_time + total - at[i];
                  counter = 0;
            }
            if(i == n - 1)
            {
                  i = 0;
            }
            else if(at[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      average_wt = wt * 1.0 / n;
      average_turnaround_time = turnaround_time * 1.0 / n;
      printf("\nAverage Waiting Time:\t%f", average_wt);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
}
