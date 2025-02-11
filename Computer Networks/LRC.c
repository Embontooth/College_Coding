#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* LRC(char inp1[], char inp2[], char inp3[], int n){
    int* lrc = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        lrc[i] = (int)(inp1[i]-'0')^(int)(inp2[i]-'0')^(int)(inp3[i]-'0');
    }
    return lrc;
}
int main() {
    char inp1[5],inp2[5],inp3[5];
    printf("Enter the bits to be transmitted\n");
    scanf(" %s %s %s",inp1,inp2,inp3);
    int* farr = LRC(inp1,inp2,inp3,strlen(inp1));
    printf("The LRC is: ");
    for(int i=0;i<strlen(inp1);i++){
        printf("%d",farr[i]);
    }
    printf("\nThe transmitted bit is: ");
    printf("%s ",inp1);
    printf("%s ",inp2);
    printf("%s ",inp3);
    for(int i=0;i<strlen(inp1);i++){
        printf("%d",farr[i]);
    }
    return 0;
}