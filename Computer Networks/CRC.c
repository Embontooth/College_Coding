#include <stdio.h>
#include <string.h>
void xorop(int * temp, int * gen, int glen,int ind){
    for(int i=0;i<glen;i++){
        temp[i]=temp[i]^gen[i];
    }
}
void CRC(int *data, int *gen, int dlen, int genlen, int* crc)
{
    int temp[dlen+genlen-1];
    for(int i=0;i<dlen;i++){
        temp[i]=data[i];
    }
    for(int i=dlen;i<dlen+genlen-1;i++){
        temp[i]=0;
    }
    for(int i=0;i<dlen;i++){
        if(temp[i]==1){
            xorop(&temp[i],gen,genlen,i);
        }
    }
    for(int i=0;i<genlen-1;i++){
        crc[i]=temp[dlen+i];
    }
}
int main(){
    int data[] = {1,0,0,1,1};
    int gen[] = {1,0,1,1};
    int datalen = sizeof(data)/sizeof(data[0]);
    int genlen = sizeof(gen)/sizeof(gen[0]);
    int crc[genlen-1];
    CRC(data,gen,datalen,genlen,crc);
    printf("Original data is ");
    for(int i=0;i<datalen;i++){
        printf("%d",data[i]);
    }
    printf("\n");
    printf("The CRC is : ");
    for(int i=0;i<genlen-1;i++){
        printf("%d",crc[i]);
    }
}