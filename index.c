#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct File
{
    char name[20];
    int start;
    int blocks[20];
    int count;
};

int main()
{
    int bit[MAX] = {0};
    struct File f[20];
    int n, choice;
    int fileCount = 0;
    int i, j, count;
    char name[20];

    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    while (1)
    {
        printf("\n\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nBit Vector:\n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", bit[i]);
            }
        }

        else if (choice == 2)
        {
            printf("\nEnter file name: ");
            scanf("%s", name);
            printf("Enter number of blocks: ");
            scanf("%d", &count);
            strcpy(f[fileCount].name, name);
            f[fileCount].count = count;
            j = 0;
            for (i = 0; i < n && j < count; i++)
            {
                if (bit[i] == 0)
                {
                    bit[i] = 1;
                    f[fileCount].blocks[j] = i;
                    j++;
                }
            }
            if (j < count)
            {
                printf("Not enough free blocks!");
                for (i = 0; i < j; i++)
                    bit[f[fileCount].blocks[i]] = 0;
            }
            else
            {
                f[fileCount].start = f[fileCount].blocks[0];
                fileCount++;
                printf("File created successfully.");
            }
        }

        else if (choice == 3)
        {
            printf("\n\nFile\tStart\tBlocks\n");
            for (i = 0; i < fileCount; i++)
            {
                printf("%s\t%d\t",
                       f[i].name,
                       f[i].start);
                for (j = 0; j < f[i].count; j++)
                {
                    printf("%d ", f[i].blocks[j]);
                }
                printf("\n");
            }
        }

        else if (choice == 4)
        {
            printf("Program ended.");
            break;
        }
        else
        {
            printf("Invalid choice!");
        }
    }
    return 0;
}