#include <stdio.h>
struct Process
{
    int pid, at, bt, ct, tat, wt;
};
int main()
{
    struct Process p[20],temp;
    int n, i,j, time = 0;
    float avgwt = 0, avgtat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter CPU Burst of P%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

     for(i=0; i<n-1;i++)
    {
        for(j=i+1; j<n; j++){
            if(p[i].at> p[j].at){
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }


    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++)
    {
        if (time < p[i].at)
            time = p[i].at;
        printf("| P%d ", p[i].pid);
        time = time + p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt = avgwt + p[i].wt;
        avgtat = avgtat + p[i].tat;
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