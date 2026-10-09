
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process
{
    int pid, at, bt, priority, ct, tat, wt, done;
};

int main()
{
    struct Process p[20];
    int n, i, completed = 0;
    int ctime = 0, pos;
    float avgwt = 0, avgtat = 0;

    srand(time(NULL));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid number of processes!");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &p[i].priority);

        p[i].bt = rand() % 10 + 1;
        p[i].done = 0;
    }

    printf("\nProcess\tBT\tPriority\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\n",
               p[i].pid, p[i].bt, p[i].priority);
    }

    printf("\nGantt Chart:\n");

    while (completed < n)
    {
        pos = -1;

        for (i = 0; i < n; i++)
        {
            if (p[i].done == 0 && p[i].at <= ctime)
            {
                if (pos == -1 ||
                    p[i].priority < p[pos].priority)
                {
                    pos = i;
                }
            }
        }

        if (pos == -1)
        {
            ctime++;
        }
        else
        {
            printf("| P%d ", p[pos].pid);

            ctime += p[pos].bt;
            p[pos].ct = ctime;

            p[pos].tat = p[pos].ct - p[pos].at;
            p[pos].wt = p[pos].tat - p[pos].bt;

            p[pos].done = 1;

            avgwt += p[pos].wt;
            avgtat += p[pos].tat;
            completed++;
        }
    }

    printf("|\n");

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].priority, p[i].ct,
               p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}

