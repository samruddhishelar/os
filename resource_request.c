#include <stdio.h>
int main()
{
int n, m;
int alloc[10][10];
int max[10][10];
int need[10][10];
int available[10];
int request[10];
int i, j;
int process;
int possible = 1;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter number of resources: ");
scanf("%d", &m);

printf("Enter available resources:\n");
for(i = 0; i < m; i++)
scanf("%d", &available[i]);

printf("Enter Allocation Matrix:\n");
for(i = 0; i < n; i++)
{
for(j = 0; j < m; j++)
scanf("%d", &alloc[i][j]);
}

printf("Enter Max Matrix:\n");
for(i = 0; i < n; i++)
{
for(j = 0; j < m; j++)
scanf("%d", &max[i][j]);
}

for(i = 0; i < n; i++)
{
for(j = 0; j < m; j++)
{
need[i][j] = max[i][j] - alloc[i][j];
}
}

printf("\nNeed Matrix:\n");
for(i = 0; i < n; i++)
{
for(j = 0; j < m; j++)
printf("%d ", need[i][j]);
printf("\n");
}

printf("\nEnter process number making request: ");
scanf("%d", &process);
printf("Enter Resource Request:\n");
for(i = 0; i < m; i++)
scanf("%d", &request[i]);

for(i = 0; i < m; i++)
{
if(request[i] > need[process][i])
{
possible = 0;
break;
}
}

if(possible)
{
for(i = 0; i < m; i++)
{
if(request[i] > available[i])
{
possible = 0;
break;
}
}
}
if(possible)
printf("\nRequest can be GRANTED immediately.\n");
else
printf("\nRequest CANNOT be granted immediately.\n");
return 0;
}