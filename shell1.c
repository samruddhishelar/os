
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

void count_file(char option, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    int ch, inword = 0;
    int characters = 0, words = 0, lines = 0;
    int last = '\n';

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace((unsigned char)ch))
            inword = 0;
        else if (!inword)
        {
            words++;
            inword = 1;
        }

        last = ch;
    }

    if (characters > 0 && last != '\n')
        lines++;

    fclose(fp);

    if (option == 'c')
        printf("Characters = %d\n", characters);
    else if (option == 'w')
        printf("Words = %d\n", words);
    else if (option == 'l')
        printf("Lines = %d\n", lines);
    else
        printf("Invalid count option\n");
}

int main()
{
    char command[100];
    char *args[20];
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL)
            break;

        int i = 0;
        char *token = strtok(command, " \t\n");

        while (token != NULL && i < 19)
        {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;

        pid = fork();

        if (pid < 0)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            if (strcmp(args[0], "count") == 0)
            {
                if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
                {
                    printf("Usage: count c/w/l filename\n");
                    exit(1);
                }

                count_file(args[1][0], args[2]);
                exit(0);
            }
            else
            {
                execvp(args[0], args);
                perror("Command execution failed");
                exit(1);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}