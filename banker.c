#include<stdio.h>

int main()
{
    int n, m;
    int allocation[20][20], max[20][20], need[20][20], available[20];
    int finish[20] = {0}, safe[20], count=0;
    int i, j, k, choice;

    printf("Enter no of processes:");
    scanf("%d",&n);

    printf("Enter no. of resources:");
    scanf("%d", &m);

    printf("Allocation Matrix:");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("max Matrix:");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
           scanf("%d",&max[i][j]);
        }
    }

    printf("need Matrix:");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {

             need[i][j] = max[i][j]-allocation[i][j];
        }
    }

    printf("Available Matrix:");
    
        for(j=0; j<m; j++)
        {
            scanf("%d",&available[j]);
        }

    do{
        printf("----MENU----");
        printf("\n1.Display allocation and max matrix\n 2. Display need matrix\n 3. Display Available\n 4.Check safe sequence\n5.Exit");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:   printf("Allocation Matrix:");
                      for(i=0; i<n; i++)
                     {
                      for(j=0; j<m; j++)
                       {
                           printf("%d",allocation[i][j]);
                        }
                        printf("\n");
                       }

                        printf("max Matrix:");
                      for(i=0; i<n; i++)
                     {
                      for(j=0; j<m; j++)
                       {
                           printf("%d",max[i][j]);
                        }
                        printf("\n");
                       }
                       break;

            case 2:  printf("need Matrix:");
                      for(i=0; i<n; i++)
                     {
                      for(j=0; j<m; j++)
                       {
                           printf("%d",need[i][j]);
                        }
                        printf("\n");
                       }
                       break;

            case 3:    printf("Available Matrix:");
    
                         for(j=0; j<m; j++)
                           {
                              printf("%d",available[j]);
                            }
                            break;

            case 4:   count =0;
                      while(count < n)
                      {
                        int found =0;

                        for(i=0; i<n; i++)
                        {
                            if(finish[i]==0)
                            {
                                int possible =1;


                                for(j = 0; j<m; j++)
                                {
                                    if(need[i][j] > available[j])
                                    {
                                        possible =0;
                                        break;
                                    }
                                }

                                if(possible){
                                    for(j=0; j<m; j++)
                                    available[j] += allocation[i][j];
                                    safe[count++]=i;
                                    finish[i] =1;
                                    found =1;
                                }
                            }
                            
                        }

                        if(!found)
                        break;
                      }
                      if(count ==n)
                      {
                        printf("\n System is in safe state");
                        printf("Safe sequence:");
                        for(i=0; i<n ;i++)
                        printf("P%d",safe[i]);
                         printf("\n");
                      }
                      else{
                        printf("System is not in safe state");
                      }
                      break;

            case 5:   printf("EXITT");
                      break;

            default:  printf("Invalid choice");
        }  

    }while(choice != 5);
    return 0;
}