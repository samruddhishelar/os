#include <stdio.h>
int main()
{
int ref[] = {8,5,7,8,5,7,2,3,7,3,5,9,4,6,2};
int n = 15;
int frames;
int page[10];
int i, j, k;
int fault = 0;
int found;
int pos, farthest;
printf("Enter number of frames: ");
scanf("%d", &frames);

for(i = 0; i < frames; i++)
{
page[i] = -1;
}
for(i = 0; i < n; i++)
{
found = 0;

for(j = 0; j < frames; j++)
{
if(page[j] == ref[i])
{
found = 1;
break;
}
}

if(found == 0)
{
fault++;

pos = -1;
for(j = 0; j < frames; j++)
{
if(page[j] == -1)
{
pos = j;
break;
}
}

if(pos == -1)
{
farthest = -1;
for(j = 0; j < frames; j++)
{
for(k = i + 1; k < n; k++)
{
if(page[j] == ref[k])
break;
}
if(k > farthest)
{
farthest = k;
pos = j;
}
}
}
page[pos] = ref[i];
}
printf("\n%d : ", ref[i]);
for(j = 0; j < frames; j++)
{
printf("%d ", page[j]);
}
}
printf("\n\nTotal Page Faults = %d\n", fault);
return 0;
}