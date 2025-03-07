#include <stdio.h>
//Without Arrival Time
void fcfs(int bt[], int n){
    int ct[n];  //Completion time is the same as turn around time here
    int wt[n];
    ct[0] = bt[0];
    wt[0] = ct[0] - bt[0];
    printf("Burst time\tCompletion time\tWaiting time\n");
    printf("%d\t%d\t%d\n", bt[0], ct[0], wt[0]);
    for (int i = 1; i < n;i++){
        ct[i] = ct[i - 1] + bt[i];
        wt[i] = ct[i] - bt[i];
        printf("%d\t%d\t%d\n", bt[i], ct[i], wt[i]);
    }
}
void fcfswithAT(int bt[], int at[], int n){
    int ct[n], wt[n], tat[n];
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    printf("Burst time\tCompletion time\tTurn-around Time\tWaiting time\n");
    printf("%d\t%d\t%d\t%d\n", bt[0], ct[0], tat[0], wt[0]);
    for (int i = 1; i < n;i++){
        if(at[i]>ct[i-1]){
            ct[i] = at[i] + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }
        else{
            ct[i] = ct[i-1] + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }
        printf("%d\t%d\t%d\t%d\n", bt[i], ct[i], tat[i], wt[i]);
    }
}
int main(){
    int n = 4;
    int bt[4] = {2, 2, 3, 4};
    fcfs(bt, n);
    int at[4] = {0, 1, 5, 6};
    fcfswithAT(bt, at, n);
}
//With Arrival Time