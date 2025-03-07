//Without Pre-emption (SJF)
void sjf(int bt[], int p[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i -1 ;j++){
            if(bt[j]>bt[j+1]){
                int temp1 = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp1;
                int temp2 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp2;
            }
        }
    }
    int ct[n], wt[n], tat[n];
    ct[0] = bt[0];
    tat[0] = ct[0];
    wt[0] = tat[0] - bt[0];
    for (int i = 1; i < n;i++){
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int i = 0; i < n;i++){
        printf("Burst time\tCompletion time\tWaiting time\n");
        printf("%d\t%d\t%d\n", bt[i], ct[i], wt[i]);
    }
}
int main(){
    int n = 4;
    int bt[4] = {6, 8, 7, 3};
    int p[4];
    for (int i = 0; i < 4;i++){
        p[i] = i;
    }
    sjf(bt, p, n);
}


//With Pre-emption (SRTF)
#include <stdio.h>
void srtf(int bt[], int at[], int p[], int n){
    int tat[n], wt[n], ct[n],bt1[n];
    int iscompleted[n];
    for(int i=0;i<n;i++){
        bt1[i]=bt[i];
        iscompleted[i]=0;
    }
    int comp = 0;
    int t = 0;
    while(comp<n){
        int shortest = -1;
        for (int i = 0; i < n;i++){
            if(iscompleted[i]==0 && at[i]<=t){
                if(shortest==-1){
                    shortest = i;
                }
                else if(bt[i]<bt[shortest]){
                    shortest = i;
                }
            }
        }
        if(shortest!=-1){
            bt[shortest]--;
            if(bt[shortest]==0){
                iscompleted[shortest] = 1;
                comp++;
                ct[shortest] = t+1;
            }
        }
        t++;
    }
    for (int i = 0; i < n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt1[i];
        printf("Burst time\tCompletion time\tWaiting time\n");
        printf("%d\t%d\t%d\n", bt1[i], ct[i], wt[i]);
    }
}

int main(){
    int n = 5;
    int bt[5] = {6,2,8,3,4};
    int p[5];
    int at[5] = {2, 5, 1, 0, 4};
    for (int i = 0; i < 5;i++){
        p[i] = i;
    }
    srtf(bt, at, p, n);
}
