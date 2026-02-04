#include <stdio.h>

int main()
{
    int p[10], bt[10], wt[10], tat[10];
    int n, i, j;
    int twt = 0, ttat = 0;
    float awt, atat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter process number: ");
        scanf("%d", &p[i]);
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                int temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        twt += wt[i];
        ttat += tat[i];
    }

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);

    return 0;
}
