#include <stdio.h>
#include "print.h"

void print_bytes(unsigned int* buf, int n)
{
  unsigned char* ptr = (unsigned char*)buf;
  int i, j;

  for (i = 0; i <= n/4; i++) {
    if (i > 0 && i % 8 == 0) {
      debug_print("\n");
    }
    for (j = 1; j <= 4; j++) {
      if ((i*4+4-j) < n) {
        debug_print("%.2X", ptr[(i*4)+4-j]);
      }
    }
    debug_print(" ");
  }
  debug_print("\n");
}

