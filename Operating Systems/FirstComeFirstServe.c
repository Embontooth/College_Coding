#include <stdio.h>
#include <stdlib.h>
void fcfs(int bt[], int at[], int n)
{
    int t = 0;
    int ct[n], tat[n], wt[n];
    int comp = 0;
    int iscomp[n];
    for (int i = 0; i < n; i++)
    {
        iscomp[i] = 0;
    }
    while (comp < n)
    {
        int change = 0;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && iscomp[i] == 0)
            {
                t = t + bt[i];
                ct[i] = t;
                comp++;
                iscomp[i] = 1;
                change = 1;
                break;
            }
        }
        if (change == 0)
        {
            t++;
        }
    }
    printf("AT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        printf("%d\t%d\t%d\t%d\t%d\n", at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}
int main()
{
    int bt[4] = {2, 2, 3, 4};
    int at[4] = {0, 1, 5, 6};
    fcfs(bt, at, 4);
}
