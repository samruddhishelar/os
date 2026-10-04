#include <stdio.h>
#include <stdlib.h>
int bit[100];
char filename[20][20];
int start[20], end[20];
int fileCount = 0;
int n;
void showBitVector() {
int i;
printf("\nBit Vector:\n");
for(i = 0; i < n; i++)
printf("%d ", bit[i]);
printf("\n");
}
void createFile() {
int size, i, count = 0;
int blocks[100];
printf("Enter file name: ");
scanf("%s", filename[fileCount]);
printf("Enter number of blocks required: ");
scanf("%d", &size);
for(i = 0; i < n && count < size; i++) {
if(bit[i] == 0) {
blocks[count++] = i;
}
}
if(count < size) {
printf("Not enough free blocks!\n");
return;
}
for(i = 0; i < size; i++)
bit[blocks[i]] = 1;
start[fileCount] = blocks[0];
end[fileCount] = blocks[size - 1];
printf("File created successfully.\n");
printf("Allocated blocks: ");
for(i = 0; i < size; i++)
printf("%d ", blocks[i]);
printf("\n");
fileCount++;
}
void showDirectory() {
int i;
printf("\nDirectory:\n");
printf("File\tStart\tEnd\n");
for(i = 0; i < fileCount; i++) {
printf("%s\t%d\t%d\n",
filename[i],
start[i],
end[i]);
}
}
int main() {
int i, choice;
printf("Enter number of blocks: ");
scanf("%d", &n);
/* Randomly allocate some blocks */
for(i = 0; i < n; i++)
bit[i] = rand() % 2;
while(1) {
printf("\n--- MENU ---\n");
printf("1. Show Bit Vector\n");
printf("2. Create New File\n");
printf("3. Show Directory\n");
printf("4. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch(choice) {
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