#include <stdio.h>
struct Process
{
int pid, at, bt, ct, tat, wt, done;
};
int main()
{
struct Process p[20];
int n, i;
int time = 0;
int completed = 0;
int min, pos;
float avgwt = 0, avgtat = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
for(i = 0; i < n; i++)
{
p[i].pid = i + 1;
printf("Enter Arrival Time of P%d: ", i + 1);
scanf("%d", &p[i].at);
printf("Enter CPU Burst of P%d: ", i + 1);
scanf("%d", &p[i].bt);
p[i].done = 0;
}
printf("\nGantt Chart:\n");
while(completed < n)
{
min = 9999;
pos = -1;

for(i = 0; i < n; i++)
{
if(p[i].done == 0 &&
p[i].at <= time &&
p[i].bt < min)
{
min = p[i].bt;
pos = i;
}
}
if(pos == -1)
{
time++;
}
else
{
printf("| P%d ", p[pos].pid);
time = time + p[pos].bt;
p[pos].ct = time;
p[pos].tat =
p[pos].ct - p[pos].at;
p[pos].wt =
p[pos].tat - p[pos].bt;
p[pos].done = 1;
avgwt = avgwt + p[pos].wt;
avgtat = avgtat + p[pos].tat;
completed++;
}
}
printf("|\n");
printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
for(i = 0; i < n; i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
p[i].pid,
p[i].at,
p[i].bt,
p[i].ct,
p[i].tat,
p[i].wt);
}
printf("\nAverage Waiting Time = %.2f",
avgwt / n);
printf("\nAverage Turnaround Time = %.2f\n",
avgtat / n);
return 0;
}