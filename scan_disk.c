#include <stdio.h>
#include <stdlib.h>
int main()
{
int request[] = {82,170,43,140,24,16,190,65};
int n = 8;
int head = 50;
int total = 0;
int i, j, temp;

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
printf("Seek Sequence:\n");
printf("%d", head);

for(i = n - 1; i >= 0; i--)
{
if(request[i] < head)
{
total = total + abs(head - request[i]);
head = request[i];
printf(" -> %d", head);
}
}

total = total + head;
head = 0;
printf(" -> 0");


for(i = 0; i < n; i++)
{
if(request[i] > head)
{
total = total + abs(head - request[i]);
head = request[i];
printf(" -> %d", head);
}
}
printf("\nTotal Head Movement = %d", total);
return 0;
}