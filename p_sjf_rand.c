
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int rem;
    int ct;
    int tat;
    int wt;
};

int main()
{
    struct Process p[10];
    int n, i;
    int c_time = 0;
    int completed = 0;
    int pos;
    float avgwt = 0;
    float avgtat = 0;

    srand(time(0));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 10)
    {
        printf("Invalid number of processes!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);

        p[i].bt = rand() % 10 + 1;

        printf("Random CPU Burst of P%d: %d\n",
               i + 1, p[i].bt);

        p[i].rem = p[i].bt;
    }

    printf("\nGantt Chart:\n");

    while (completed < n)
    {
        pos = -1;

        for (i = 0; i < n; i++)
        {
            if (p[i].rem > 0 && p[i].at <= c_time)
            {
                if (pos == -1 ||
                    p[i].rem < p[pos].rem)
                {
                    pos = i;
                }
            }
        }

        if (pos == -1)
        {
            c_time++;
        }
        else
        {
            printf("| P%d ", p[pos].pid);

            p[pos].rem--;
            c_time++;

            if (p[pos].rem == 0)
            {
                p[pos].ct = c_time;

                p[pos].tat =
                    p[pos].ct - p[pos].at;

                p[pos].wt =
                    p[pos].tat - p[pos].bt;

                avgwt += p[pos].wt;
                avgtat += p[pos].tat;

                completed++;
            }
        }
    }

    printf("|\n");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
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

