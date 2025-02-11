#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int * checksum(int d1[], int d2[], int n){
    int * cs = (int *)malloc((n+1)*sizeof(int));
    int carr = 0;
    for(int i=n;i>0;i--){
        if(d1[i]+d2[i]+carr==0){
            carr = 0;
            cs[i]= 0;
        }
        else if(d1[i]+d2[i]+carr==1){
            carr = 0;
            cs[i]= 1;
        }
        else if(d1[i]+d2[i]+carr==2){
            carr = 1;
            cs[i]= 0;
        }
        else{
            carr = 1;
            cs[i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        if(cs[i]==1){
            cs[i]=0;
        }
        else{
            cs[i]=1;
        }
    }
    return carr*(int)pow(10,n)+cs;
}
int main(){
    int d1[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
    int d2[] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};
    int n = sizeof(d1)/sizeof(d1[0]);
    int* cs = checksum(d1,d2,n);
    printf("The checksum value is: ");
    for(int i=0;i<n;i++){
        printf("%d",cs[i]);
    }
    printf("\nThe transmitted value is: ");
    for(int i=0;i<n;i++){
        printf("%d",d1[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d",d2[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d",cs[i]);
    }
}