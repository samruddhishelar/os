#include <stdio.h>
int main()
{
int pages[] = {3,4,5,6,3,4,7,3,4,5,6,7,2,4,6};
int n = 15;
int frames[10];
int frameSize;
int i, j;
int pointer = 0;
int fault = 0;
int found;
printf("Enter number of frames: ");
scanf("%d", &frameSize);

for(i = 0; i < frameSize; i++)
frames[i] = -1;
printf("\nPage\tFrames\t\tStatus\n");
for(i = 0; i < n; i++)
{
found = 0;

for(j = 0; j < frameSize; j++)
{
if(frames[j] == pages[i])
{
found = 1;
break;
}
}

if(found == 0)
{
frames[pointer] = pages[i];
pointer = (pointer + 1) % frameSize;
fault++;
printf("%d\t", pages[i]);
for(j = 0; j < frameSize; j++)
printf("%d ", frames[j]);
printf("\tPage Fault\n");
}

else
{
printf("%d\t", pages[i]);
for(j = 0; j < frameSize; j++)
printf("%d ", frames[j]);
printf("\tHit\n");
}
}
printf("\nTotal Page Faults = %d\n", fault);
return 0;
}