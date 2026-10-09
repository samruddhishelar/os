#include <stdio.h>
#include <stdlib.h>
int bit[100];
char fileName[20][20];
int start[20];
int length[20];
int fileCount = 0;
int n;
/* Show Bit Vector */
void showBitVector()
{
int i;
printf("\nBit Vector:\n");
for(i = 0; i < n; i++)
printf("%d ", bit[i]);
printf("\n");
}

void createFile()
{
int size;
int i;
int count = 0;
int first = -1;
printf("Enter file name: ");
scanf("%s", fileName[fileCount]);
printf("Enter number of blocks required: ");
scanf("%d", &size);

for(i = 0; i < n; i++)
{
if(bit[i] == 0)
{
if(first == -1)
first = i;
count++;
}
else
{
first = -1;
count = 0;
}
if(count == size)
break;
}
if(count < size)
{
printf("Not enough consecutive free blocks!\n");
return;
}

for(i = first; i < first + size; i++)
bit[i] = 1;
start[fileCount] = first;
length[fileCount] = size;
printf("File created successfully.\n");
printf("Starting Block = %d\n", first);
printf("Number of Blocks = %d\n", size);
fileCount++;
}

void showDirectory()
{
int i;
printf("\nDirectory:\n");
printf("File\tStart\tLength\n");
for(i = 0; i < fileCount; i++)
{
printf("%s\t%d\t%d\n",
fileName[i],
start[i],
length[i]);
}
}
int main()
{
int i;
int choice;
printf("Enter number of blocks: ");
scanf("%d", &n);

for(i = 0; i < n; i++)
bit[i] = rand() % 2;
while(1)
{
printf("\n--- MENU ---\n");
printf("1. Show Bit Vector\n");
printf("2. Create New File\n");
printf("3. Show Directory\n");
printf("4. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
showBitVector();
break;
case 2:
createFile();
break;
case 3:
showDirectory();
break;
case 4:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}