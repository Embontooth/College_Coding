#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculateSubnet(char* ip,char* subnetMask) {
    char * token = strtok(ip,".");
    int arr1[4],arr2[4];
    int i=0;
    while(token!=NULL){
        int val = atoi(token);
        arr1[i]=val;
        i++;
        token=strtok(NULL,".");
    }
    i=0;
    char * token1 = strtok(subnetMask,".");
    while(token1!=NULL){
        int val = atoi(token1);
        arr2[i]=val;
        i++;
        token1=strtok(NULL,".");
    }
    for(int i=0;i<4;i++){
        int val = arr1[i]&arr2[i];
        printf("%d ",val);
    }
}

int main() {
    char ip[16], subnetMask[16];

    // Input IP address and subnet mask
    printf("Enter IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ip);
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", subnetMask);
    // Calculate the subnet
    calculateSubnet(ip, subnetMask);

    return 0;
}
