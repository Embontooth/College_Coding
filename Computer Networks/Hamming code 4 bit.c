#include <stdio.h>

int main() {
    int d1 = 1, d2 = 0, d3 = 1, d4 = 1;
    int p1, p2, p4;
    p1 = d1 ^ d2 ^ d4; 
    p2 = d1 ^ d3 ^ d4; 
    p4 = d2 ^ d3 ^ d4; 
    printf("Hamming code for 1011 is: %d%d%d%d%d%d%d\n", p1, p2, d1, p4, d2, d3, d4);
    return 0;
}