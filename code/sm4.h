#ifndef HEADER_SM4_H
# define HEADER_SM4_H

#include <inttypes.h>

# define SM4_BLOCK_SIZE    16
# define SM4_KEY_SCHEDULE  32

void sm4_encrypt(uint8_t key[],
    unsigned char plaintext[],
    unsigned char ciphertext[]);

void sm4_decrypt(uint8_t key[],
    unsigned char ciphertext[],
    unsigned char plaintext[]);

#endif

