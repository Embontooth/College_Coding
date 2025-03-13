#include <stdio.h>
//Without pre emption
void priCPU(int bt[], int at[], int priority[], int p[], int n){
    int tat[n], ct[n], wt[n];
    for (int i = 0; i < n - 1;i++){
        for (int j = i; j < n - i - 1;j++){
            if(priority[j]>priority[j+1]){
                int temp1 = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp1;
                int temp2 = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp2;
                int temp3 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp3;
                int temp4 = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp4;
            }
        }
    }
    ct[0] = bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    for (int i = 1; i < n; i++){
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int i = 0; i < n;i++){
        printf("Burst time\tCompletion time\tWaiting time\n");
        printf("%d\t%d\t%d\n", bt[i], ct[i], wt[i]);
    }
}
int main(){
    int n == 5;
    int bt[5] = {11, 28, 2, 10, 16};
    int at[5] = {0, 5, 12, 2, 9};
    int priority[5] = {2, 0, 3, 1, 4};
    int p[5];
    for (int i = 0; i < 5;i++){
        p[i] = i;
    }
    priCPU(bt, at, priority, p, n);
}