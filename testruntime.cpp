#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hc128.h" // Assuming hc128.h is the header file containing the HC-128 implementation
#include <sys/time.h>
#define NUM_TESTS 5

void measureEncryptionTime(uint8 *key, uint8 *iv, uint8 *message, uint64 msglength) {
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    HC128_State state;


    for (int i = 0; i < NUM_TESTS; i++) {
        Initialization(&state, key, iv);
        EncryptMessage(&state, message, message, msglength);
    }

   gettimeofday(&stop, NULL);
    printf("took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec)/NUM_TESTS); 

}

void measureDecryptionTime(uint8 *key, uint8 *iv, uint8 *ciphertext, uint64 msglength) {
   struct timeval stop, start;
  gettimeofday(&start, NULL);
    HC128_State state;


    for (int i = 0; i < NUM_TESTS; i++) {
        Initialization(&state, key, iv);
        DecryptMessage(&state, ciphertext, ciphertext, msglength);
    }

    gettimeofday(&stop, NULL);
    printf("took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec)/NUM_TESTS); 

}

int main() {
    uint8 key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    uint8 iv[16] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    uint8 message[1024]; // Example message of 1024 bytes, you can change the size as needed

    // Initialize message with random bytes
    for (int i = 0; i < 1024; i++) {
        message[i] = rand() % 256; // Random byte (0-255)
    }

    uint64 msglength = sizeof(message);

    printf("Testing encryption time:\n");
    measureEncryptionTime(key, iv, message, msglength);

    printf("\nTesting decryption time:\n");
    measureDecryptionTime(key, iv, message, msglength);

    return 0;
}