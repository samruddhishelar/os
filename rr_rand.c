
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, limit, total = 0, x, time_quantum;
    int arrival_time[10], burst_time[10], temp[10];
    int wait_time[10] = {0}, tat[10] = {0};
    int completed[10] = {0};
    int current_time = 0, done = 0, found;
    float avgwt = 0, avgtat = 0;

    srand(time(NULL));

    printf("Enter Total Number of Processes: ");
    scanf("%d", &limit);

    if (limit < 1 || limit > 10)
    {
        printf("Invalid number of processes!\n");
        return 1;
    }

    x = limit;

    for (i = 0; i < limit; i++)
    {
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        burst_time[i] = rand() % 10 + 1;
        temp[i] = burst_time[i];

        printf("Random Burst Time of P%d: %d\n",
               i + 1, burst_time[i]);
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);

    if (time_quantum <= 0)
    {
        printf("Invalid time quantum!\n");
        return 1;
    }

    printf("\nGantt Chart:\n");
   

    while (done < limit)
    {
        found = 0;

        for (i = 0; i < limit; i++)
        {
            if (temp[i] > 0 && arrival_time[i] <= current_time)
            {
                found = 1;

                if (temp[i] > time_quantum)
                {
                    current_time += time_quantum;
                    temp[i] -= time_quantum;
                }
                else
                {
                    current_time += temp[i];
                    temp[i] = 0;
                    completed[i] = current_time;
                    done++;
                }

                printf("| P%d ", i + 1, current_time);
            }
        }

        if (found == 0)
        {
            current_time++;

           
        }
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < limit; i++)
    {
        tat[i] = completed[i] - arrival_time[i];
        wait_time[i] = tat[i] - burst_time[i];

        avgwt += wait_time[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, arrival_time[i], burst_time[i],
               completed[i], tat[i], wait_time[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / limit);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / limit);

    return 0;
}

