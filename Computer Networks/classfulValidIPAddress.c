#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char * ip = (char *)malloc(16*sizeof(char));
    scanf("%s",ip);
    char * token = strtok(ip,".");
    int flag=0;
    int first = atoi(token);
    while(token!=NULL){
        int value=atoi(token);
        if(value>255){
            printf("Invalid IP\n");
            flag=1;
            break;
        }
        token = strtok(NULL,".");
    }
    if(flag==0){
        printf("Valid IP\n");
        if(first>=0&&first<=127){
            printf("Class A");
        }
        else if(first>=128&&first<=191){
            printf("Class B");
        }
        else if(first>=192&&first<=223){
            printf("Class C");
        }
        else if(first>=224&&first<=239){
            printf("Class D");
        }
        else if(first>=240&&first<=255){
            printf("Class E");
        }
    }
    return 0;
}