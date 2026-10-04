#include <stdio.h>
#include <stdlib.h>
int main()
{
int request[] = {98,183,37,122,14,124,65};
int n = 7;
int visited[7] = {0};
int head = 53;
int total = 0;
int i, j;
int min, pos;
printf("Seek Sequence:\n");
printf("%d", head);
for(i = 0; i < n; i++)
{
min = 9999;
pos = -1;

for(j = 0; j < n; j++)
{
if(visited[j] == 0)
{
int distance = abs(head - request[j]);
if(distance < min)
{
min = distance;
pos = j;
}
}
}
total = total + min;
head = request[pos];
visited[pos] = 1;
printf(" -> %d", head);
}
printf("\nTotal Head Movement = %d", total);
return 0;
}