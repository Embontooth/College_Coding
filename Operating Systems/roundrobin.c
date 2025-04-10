#include <stdio.h>
#include <stdlib.h>
void roundrobin(int bt[], int at[], int tq, int n)
{
    int ct[n], wt[n], tat[n], bt1[n];
    int comp = 0;
    for (int i = 0; i < n; i++)
    {
        bt1[i] = bt[i];
    }
    int t = 0;
    while (comp < n)
    {
        int done = -1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && bt[i] > 0)
            {
                done = 0;
                if (bt[i] > tq)
                {
                    t += tq;
                    bt[i] -= tq;
                }
                else
                {
                    t += bt[i];
                    ct[i] = t;
                    bt[i] = 0;
                    comp++;
                }
            }
        }
        if (done == -1)
        {
            t++;
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
    int bt[3] = {5, 3, 1};
    int at[3] = {0, 1, 2};
    int tq = 2;
    roundrobin(bt, at, tq, 3);
}