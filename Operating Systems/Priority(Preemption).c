#include <stdio.h>
#include <stdlib.h>
void prioritys(int bt[], int at[], int pri[], int n)
{
    int comp = 0;
    int iscomp[n], tat[n], wt[n], ct[n], bt1[n];
    for (int i = 0; i < n; i++)
    {
        iscomp[i] = 0;
        bt1[i] = bt[i];
    }
    int t = 0;
    while (comp < n)
    {
        int priority = -1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && iscomp[i] == 0)
            {
                if (priority == -1)
                {
                    priority = i;
                }
                else if (pri[i] < pri[priority])
                {
                    priority = i;
                }
            }
        }
        if (priority == -1)
        {
            t++;
        }
        else
        {
            t++;
            bt[priority]--;
            if (bt[priority] == 0)
            {
                ct[priority] = t;
                iscomp[priority] = 1;
                comp++;
            }
        }
    }
    printf("AT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt1[i];
        printf("%d\t%d\t%d\t%d\t%d\n", at[i], bt1[i], ct[i], tat[i], wt[i]);
    }
}
int main()
{
    int bt[5] = {11, 28, 2, 10, 16};
    int pri[5] = {2, 0, 3, 1, 4};
    int at[5] = {0, 5, 12, 2, 9};
    prioritys(bt, at, pri, 5);
}