#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int a[10], n, key;
int i, j, temp;
int pid;
printf("Enter number of elements: ");
scanf("%d", &n)
printf("Enter elements:\n");
for(i = 0; i < n; i++)
scanf("%d", &a[i]);

for(i = 0; i < n - 1; i++)
{
for(j = i + 1; j < n; j++)
{
if(a[i] > a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
printf("Sorted array: ")
for(i = 0; i < n; i++)
printf("%d ", a[i])
printf("\nEnter element to search: ");
scanf("%d", &key);
pid = fork()
if(pid == 0)
{
int low = 0;
int high = n - 1;
int mid;
int found = 0

while(low <= high)
{
mid = (low + high) / 2
if(a[mid] == key)
{
found = 1;
break;
}
else if(a[mid] < key)
low = mid + 1;
else
high = mid - 1;
if(found)
printf("Element found\n");
else
printf("Element not found\n");
}
else
{
wait(NULL);
printf("Parent process finished\n");
}
}
return 0;
}
