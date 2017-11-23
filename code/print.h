#ifndef SM4PRINT_H
#define SM4PRINT_H

#define DEBUG 0
#define debug_print(...) \
  do { if (DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)

#include <stdio.h>

void print_bytes(unsigned* buf, int n);

#endif
