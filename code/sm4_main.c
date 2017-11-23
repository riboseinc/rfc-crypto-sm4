#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sm4.h"
#include "print.h"

typedef struct {
  unsigned char* key;
  unsigned char* message;
  unsigned char* expected;
  int iterations;
  bool encrypt;
} test_case;

int sm4_run_example(test_case tc)
{
  unsigned char input[SM4_BLOCK_SIZE] = {0};
  unsigned char output[SM4_BLOCK_SIZE] = {0};
  int i;

  debug_print("-----------------------"
      " Message Input m Begin "
      "-------------------------\n");
  print_bytes((unsigned int*)tc.message, SM4_BLOCK_SIZE);
  debug_print("----------------------- "
      "Message Input m End "
      "---------------------------\n");

  if (tc.encrypt)
  {
    debug_print("----------------------- "
        "Encrypt "
        "---------------------------\n");
    memcpy(input, tc.message, SM4_BLOCK_SIZE);
    for (i = 0; i != tc.iterations; ++i)
    {
      sm4_encrypt(tc.key,
          (unsigned char*)input,
          (unsigned char*)output);
      memcpy(input, output, SM4_BLOCK_SIZE);
    }
  }
  else
  {
    debug_print("----------------------- "
        "Decrypt "
        "---------------------------\n");
    memcpy(input, tc.message, SM4_BLOCK_SIZE);
    for (i = 0; i != tc.iterations; ++i)
    {
      sm4_decrypt(tc.key,
          (unsigned char*)input,
          (unsigned char*)output);
      memcpy(input, output, SM4_BLOCK_SIZE);
    }
  }

  debug_print("+++++++++++++++++++++++++++++++"
      " RESULT "
      "++++++++++++++++++++++++++++++++\n");
  debug_print("RESULTS:\n");
  debug_print(" Expected:\n");
  print_bytes((unsigned int*)tc.expected, SM4_BLOCK_SIZE);

  debug_print(" Output:\n");
  print_bytes((unsigned int*)output, SM4_BLOCK_SIZE);

  return memcmp(
    (unsigned char*)output,
    (unsigned char*)tc.expected,
    SM4_BLOCK_SIZE
  );
}

int main(int argc, char **argv)
{

  int i;
  unsigned char key[SM4_BLOCK_SIZE];
  unsigned char block[SM4_BLOCK_SIZE];

  test_case tests[4] = {0};

  /*
   * This test vector comes from Example 1 of GB/T 32907-2016,
   */
  static const unsigned int gbt32907k1[SM4_BLOCK_SIZE] = {
    0x01234567, 0x89abcdef,
    0xfedcba98, 0x76543210
  };
  static const unsigned int gbt32907m1[SM4_BLOCK_SIZE] = {
    0x01234567, 0x89abcdef,
    0xfedcba98, 0x76543210
  };
  static const unsigned int gbt32907e1[SM4_BLOCK_SIZE] = {
    0x681edf34, 0xd206965e,
    0x86b3e94f, 0x536e4246
  };
  test_case gbt32907t1 = {
    (unsigned char*)gbt32907k1,
    (unsigned char*)gbt32907m1,
    (unsigned char*)gbt32907e1,
    1,
    true
  };
  tests[0] = gbt32907t1;

  /*
   * This test vector comes from Example 2 from GB/T 32907-2016.
   * After 1,000,000 iterations.
   */
  static const unsigned int gbt32907e2[SM4_BLOCK_SIZE] = {
    0x595298c7, 0xc6fd271f,
    0x0402f804, 0xc33d3f66
  };
  test_case gbt32907t2 = {
    (unsigned char*)gbt32907k1,
    (unsigned char*)gbt32907m1,
    (unsigned char*)gbt32907e2,
    1000000,
    true
  };
  tests[1] = gbt32907t2;

  /*
   * This test vector reverses Example 1 of GB/T 32907-2016.
   * After decrypting 1 iteration.
   */
  test_case gbt32907t3 = {
    (unsigned char*)gbt32907k1,
    (unsigned char*)gbt32907e1,
    (unsigned char*)gbt32907m1,
    1,
    false
  };
  tests[2] = gbt32907t3;

  /*
   * This test vector reverses Example 2 of GB/T 32907-2016.
   * After decrypting 1,000,000 iterations.
   */
  test_case gbt32907t4 = {
    (unsigned char*)gbt32907k1,
    (unsigned char*)gbt32907e2,
    (unsigned char*)gbt32907m1,
    1000000,
    false
  };
  tests[3] = gbt32907t4;

// tag::skipdoc[]
  /* TODO: add more examples */
// end::skipdoc[]

  for (i = 0; i < 4; ++i)
  {
    printf("sm4_example[%2i]: %s\n", i,
      sm4_run_example(tests[i]) ?  "FAIL" : "PASS");
  }

  return 0;
}

