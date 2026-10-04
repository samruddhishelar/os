#include <stdio.h>

int main()
{
int ref[] = {8,5,7,8,5,7,2,3,7,3,5,9,4,6,2};
int frames[10];
int freq[10];
int n = 15;
int f;
int i, j;
int fault = 0;
int found;
int pos;

printf("Enter number of frames: ");
scanf("%d", &f);
for(i = 0; i < f; i++)
{
frames[i] = -1;
freq[i] = 0;
}
for(i = 0; i < n; i++)
{
found = 0;

for(j = 0; j < f; j++)
{
if(frames[j] == ref[i])
{
found = 1;
freq[j]++;
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
if(freq[j] > freq[pos])
pos = j;
}
}
frames[pos] = ref[i];
freq[pos] = 1;
}
printf("\n%d : ", ref[i]);
for(j = 0; j < f; j++)
printf("%d ", frames[j]);
}
printf("\n\nTotal Page Faults = %d\n", fault);
return 0;
}