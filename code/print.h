#ifndef SM3PRINT_H
#define SM3PRINT_H

#define DEBUG 0
#define debug_print(...) \
  do { if (DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)

#include <inttypes.h>
#include <stdio.h>

void print_bytes(unsigned* buf, int n);
void print_block(unsigned* buf, int n);
void print_af(int i, uint32_t A, uint32_t B, uint32_t C, uint32_t D,
    uint32_t E, uint32_t F, uint32_t G, uint32_t H);
void print_hash(unsigned* buf);

#endif
