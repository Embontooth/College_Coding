#include <stdio.h>
void hainoi(int n, char from, char via, char to){
    if(n>0){
        hanoi(n-1, from, to, via);
        printf("Disk %d moved from %c to %c\n",n,from,to);
        hanoi(n-1, via, from , to);
    }
    else{
        return;
    }
}
int main(){
    int n;
    printf("Enter the number of disks");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}