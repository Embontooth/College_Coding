#include <stdio.h>
#include <stdlib.h>
void sjf(int bt[], int at[], int n)
{
    int comp = 0;
    int iscomp[n], tat[n], wt[n], ct[n];
    for (int i = 0; i < n; i++)
    {
        iscomp[i] = 0;
    }
    int t = 0;
    while (comp < n)
    {
        int shortest = -1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && iscomp[i] == 0)
            {
                if (shortest == -1)
                {
                    shortest = i;
                }
                else if (bt[i] < bt[shortest])
                {
                    shortest = i;
                }
            }
        }
        if (shortest == -1)
        {
            t++;
        }
        else
        {
            t += bt[shortest];
            ct[shortest] = t;
            iscomp[shortest] = 1;
            comp++;
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
    int bt[5] = {2, 1, 3, 5, 4};
    int at[5] = {2, 0, 1, 3, 4};
    sjf(bt, at, 5);
}