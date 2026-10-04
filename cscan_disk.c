#include <stdio.h>
#include <stdlib.h>
int main()
{
int request[] = {15,45,75,105,135,165,195,80};
int n = 8;
int diskSize;
int head;
int i, j, temp;
int total = 0;
printf("Enter disk size: ");
scanf("%d", &diskSize);
printf("Enter starting head position: ");
scanf("%d", &head);

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
printf("\nC-SCAN Seek Sequence:\n");
printf("%d", head);

for(i = 0; i < n; i++)
{
if(request[i] >= head)
{
total = total + abs(head - request[i]);
head = request[i];
printf(" -> %d", head);
}
}

total = total + (diskSize - 1 - head);
head = diskSize - 1;
printf(" -> %d", head);

total = total + (diskSize - 1);
head = 0;
printf(" -> %d", head);

for(i = 0; i < n; i++)
{
if(request[i] < 100)
{
total = total + abs(head - request[i]);
head = request[i];
printf(" -> %d", head);
}
}
printf("\n\nTotal Head Movement = %d cylinders\n", total);
return 0;
}