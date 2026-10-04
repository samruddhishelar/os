#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int a[20], n;
int i, j, temp;
int pid;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements:\n");
for(i = 0; i < n; i++)
scanf("%d", &a[i]);
pid = fork();
if(pid < 0)
{
printf("Fork failed");
}
else if(pid == 0)
{

printf("\nChild Process - Insertion Sort\n");
for(i = 1; i < n; i++)
{
temp = a[i];
j = i - 1;
while(j >= 0 && a[j] > temp)
{
a[j + 1] = a[j];
j--;
}
a[j + 1] = temp;
}
printf("Sorted elements: ");
for(i = 0; i < n; i++)
printf("%d ", a[i]);
}
else
{

wait(NULL);

printf("\nParent Process - Bubble Sort\n");
for(i = 0; i < n - 1; i++)
{
for(j = 0; j < n - i - 1; j++)
{
if(a[j] > a[j + 1])
{
temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
}
}
printf("Sorted elements: ");
for(i = 0; i < n; i++)
printf("%d ", a[i]);
}
return 0;
}