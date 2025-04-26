#include<stdio.h>
#include "Utils.h"


// void printHex(const uint8_t *ptr, int len, char *tag) {
//     printf("%s\ndata[%d]: ", tag, len);
//     for (int i = 0; i < len; ++i) {
//         printf("%.2X ", *ptr++);
//     }
//     printf("\n");
// }


int main(){
    int a=2;
    
    uint8_t ct[16] = {0};
    printHex(ct, 16, "plain data:");
    // printHex(const uint8_t *ptr, int len, char *tag);
    printf("test demo running!\n");
    printf("value a is %d", a);
    return 0;
}