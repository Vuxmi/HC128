#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hc128.h" // Assuming hc128.h is the header file containing the HC-128 implementation

#include <sys/time.h>

int main() {
    // Example key, IV, and message

/* here, do your time-consuming job */
//do stuff

    uint8 key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    uint8 iv[16] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    uint8 message[] = "hethongnhungiotk66daihocbachkhoahanoi";
    uint64 msglength = strlen((char*)message);
    printf("Message: ");
    for(int i=0;i<msglength;i++)
    {
        printf("%c",message[i]);
    }
    printf("\n");
    printf("Key: ");
    for(int i=0;i<16;i++)
    {
        printf("%x ",key[i]);
    }
    printf("\n");
    printf("IV: ");
    for(int i=0;i<16;i++)
    {
        printf("%x ",iv[i]);
    }
    printf("\n");
    uint8 ciphertext[msglength];
    // uint8 key2[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    // Encrypt the message
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    HC128(key, iv, message, ciphertext, msglength);

    //uint8 ciphertext2[] = {0x43, 0x85, 0x06, 0x74, 0x32, 0xA4, 0x5C, 0xA4, 0x49, 0xFC, 0x6B, 0x82, 0x7D, 0xD7, 0xAD, 0xE2, 0xF2, 0xEE, 0x56, 0x6C, 0x9A, 0x53, 0x48, 0x55, 0xA2, 0x80, 0x19, 0xF2, 0x66, 0x6F, 0x41, 0x1A, 0x54, 0xE4, 0x90, 0x6B, 0x5B};
    //uint64 msglength1 = sizeof(ciphertext2);
    //char plaintxt[]={'\0'};
    //HC128_Decrypt(key, iv,ciphertext2 ,plaintxt,msglength1);
   


//do stuff

    
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
    printf("Ciphertext: ");
    for (int i = 0; i < msglength; i++) {
        printf("%02X ", ciphertext[i]);
    } 
    /* gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
     printf("Plain txt: ");
     for (int i = 0; i < msglength1; i++) {
        printf("%c", plaintxt[i]);
     } */
}
