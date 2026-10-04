#include <stdio.h>
int main()
{
int ref[] = {3,5,7,2,5,1,2,3,1,3,5,3,1,6,2};
int n = 15;
int frames[10];
int counter[10];
int f;
int i, j;
int time = 0;
int fault = 0;
int found;
int pos;

printf("Enter number of frames: ");
scanf("%d", &f);
for(i = 0; i < f; i++)
{
frames[i] = -1;
counter[i] = 0;
}
for(i = 0; i < n; i++)
{
found = 0;
time++;

for(j = 0; j < f; j++)
{
if(frames[j] == ref[i])
{
found = 1;
counter[j] = time;
break;
}
}

if(found == 0)
{
fault++;

pos = -1;
for(j = 0; j < f; j++)
{
if(frames[j] == -1)
{
pos = j;
break;
}
}

if(pos == -1)
{
pos = 0;
for(j = 1; j < f; j++)
{
if(counter[j] < counter[pos])
pos = j;
}
}
frames[pos] = ref[i];
counter[pos] = time;
}
printf("\n%d : ", ref[i]);
for(j = 0; j < f; j++)
printf("%d ", frames[j]);
}
printf("\n\nTotal Page Faults = %d\n", fault);
return 0;
}