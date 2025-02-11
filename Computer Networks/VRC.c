#include <stdio.h>

int calculateVRC(int data) {
    int count=0;
    while(data>0){
        int c = data%10;
        if(c==1){
            count++;
        }
        data=data/10;
    }
    if(count%2==0){
        return 0;
    }
    else{
        return 1;
    }
}
int main() {
    int data;

    printf("Enter the data bits: ");
    scanf("%d", &data);

    int i = calculateVRC(data);

    printf("The VRC bit is: %d\n", i);
    
    data=data*10+i;
    printf("The data with VRC is: %d\n", data);
    return 0;
}