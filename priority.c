#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Process
{
int pid;
int at;
int bt;
int priority;
int ct;
int tat;
int wt;
int done;
};
int main()
{
struct Process p[10];
int n, i;
int c_time = 0;
int completed = 0;
int pos, best;
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

p[i].bt = p[i].bt + rand() % 5;
p[i].done = 0;
}
printf("\nGantt Chart:\n");
while(completed < n)
{
pos = -1;

for(i = 0; i < n; i++)
{
if(p[i].done == 0 && p[i].at <= c_time)
{
if(pos == -1 ||
p[i].priority < p[pos].priority)
{
pos = i;
}
}
}
if(pos == -1)
{
c_time++;
}
else
{
printf("| P%d ", p[pos].pid);
c_time = c_time + p[pos].bt;
p[pos].ct = c_time;
p[pos].tat =
p[pos].ct - p[pos].at;
p[pos].wt =
p[pos].tat - p[pos].bt;
p[pos].done = 1;
avgwt += p[pos].wt;
avgtat += p[pos].tat;
completed++;
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