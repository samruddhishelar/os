#include <stdio.h>
#include <unistd.h>
int main()
{
int pid;
pid = fork();
if(pid == 0)
{
printf("Child process\n");
nice(-5);
printf("Higher priority assigned to child\n");
}
else
{
printf("Parent process\n");
}
return 0;
}