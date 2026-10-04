#include <stdio.h>
#include <stdlib.h>
int main()
{
int request[] = {15, 30, 55, 90, 125, 140, 170};
int n = 7;
int head = 100;
int i, j, temp;
int total = 0;

for(i = 0; i < n - 1; i++)
{
for(j = i + 1; j < n; j++)
{
if(request[i] > request[j])
{
temp = request[i];
request[i] = request[j];
request[j] = temp;
}
}
}
printf("Service Order:\n");

for(i = n - 1; i >= 0; i--)
{
if(request[i] < head)
{
printf("%d ", request[i]);
total = total +
abs(head - request[i]);
head = request[i];
}
}
for(i = 0; i < n; i++)
{
if(request[i] > head)
{
printf("%d ", request[i]);
total = total +
abs(head - request[i]);
head = request[i];
}
}
printf("\n\nTotal Head Movement = %d\n",
total);
return 0;
}