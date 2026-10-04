#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Process
{
int pid;
int at;
int bt;
int remaining;
int priority;
int ct;
int tat;
int wt;
};
int main()
{
struct Process p[10];
int n;
int i;
int c_time = 0;
int completed = 0;
int best;
float avgwt = 0;
float avgtat = 0;
srand(time(0));
printf("Enter number of processes: ");
scanf("%d", &n);
for(i = 0; i < n; i++)
{
p[i].pid = i + 1;
printf("\nArrival Time of P%d: ", i + 1);
scanf("%d", &p[i].at);
printf("First CPU Burst of P%d: ", i + 1);
scanf("%d", &p[i].bt);
printf("Priority of P%d: ", i + 1);
scanf("%d", &p[i].priority);
p[i].remaining = p[i].bt;
}
printf("\nGantt Chart:\n");
while(completed < n)
{
best = -1;
/* Find highest priority process */
for(i = 0; i < n; i++)
{
if(p[i].remaining > 0 &&
p[i].at <= c_time)
{
if(best == -1 ||
p[i].priority < p[best].priority)
{
best = i;
}
}
}
/* No process available */
if(best == -1)
{
c_time++;
}
else
{
printf("| P%d ", p[best].pid);
p[best].remaining--;
c_time++;
/* Process completed */
if(p[best].remaining == 0)
{
p[best].ct = c_time;
p[best].tat =
p[best].ct - p[best].at;
p[best].wt =
p[best].tat - p[best].bt;
completed++;
avgwt += p[best].wt;
avgtat += p[best].tat;
}
}
}
printf("|\n");
printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
for(i = 0; i < n; i++)
{
printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
p[i].pid,
p[i].at,
p[i].bt,
p[i].priority,
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