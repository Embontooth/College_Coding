#include <stdio.h>
#include <stdlib.h>
void srtf(int bt[], int at[], int n)
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
            t++;
            bt[shortest]--;
            if (bt[shortest] == 0)
            {
                ct[shortest] = t;
                iscomp[shortest] = 1;
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
    int at[5] = {2, 5, 1, 0, 4};
    int bt[5] = {6, 2, 8, 3, 4};
    srtf(bt, at, 5);
}