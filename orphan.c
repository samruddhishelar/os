#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
int pid;
pid = fork();
if(pid < 0)
{
printf("Fork failed\n");
}
else if(pid == 0)
{
printf("Child process started\n");
printf("Child PID = %d\n", getpid());
printf("Parent PID = %d\n", getppid());
sleep(5);
printf("\nAfter parent terminates:\n");
printf("Child PID = %d\n", getpid());
printf("New Parent PID = %d\n", getppid());
}
else
{
printf("Parent process\n");
printf("Parent PID = %d\n", getpid());
sleep(2);
printf("Parent process terminating...\n");
exit(0);
}
return 0;
}