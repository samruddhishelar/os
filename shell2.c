#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
char command[100];
char type;
char filename[50];
char pattern[50];
while(1)
{
printf("$ ");
fgets(command, sizeof(command), stdin);
command[strcspn(command, "\n")] = '\0';
if(strcmp(command, "exit") == 0)
break;
/* search command */
if(strncmp(command, "search ", 7) == 0)
{
sscanf(command, "search %c %s %s",
&type, filename, pattern);
FILE *fp;
char line[200];
int count = 0;
fp = fopen(filename, "r");
if(fp == NULL)
{
printf("File not found\n");
continue;
}
while(fgets(line, sizeof(line), fp))
{
char *p = line;
while((p = strstr(p, pattern)) != NULL)
{
count++;
if(type == 'f')
{
printf("Pattern found\n");
fclose(fp);
goto next;
}
if(type == 'a')
{
printf("Pattern found at position %ld\n",
p - line);
}
p++;
}
}
if(type == 'c')
{
printf("Number of occurrences = %d\n",
count);
}
if(count == 0)
printf("Pattern not found\n");
fclose(fp);
}
else
{

char *args[10];
char *token;
int i = 0;
token = strtok(command, " ");
while(token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
if(fork() == 0)
{
execvp(args[0], args);
printf("Command not found\n");
exit(1);
}
else
{
wait(NULL);
}
}
next:
;
}
return 0;
}