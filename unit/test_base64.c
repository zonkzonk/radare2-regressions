#include <r_util.h>
#include "minunit.h"

int tests_run = 0;

char* test_r_base64_decode(void) {
  char* hello = (char*)r_base64_decode_dyn ("aGVsbG8=", 0);
  mu_assert("error, decode of b64(hello) failed", strcmp(hello, "hello") == 0);
  return NULL;
}

char* all_tests() {
  mu_run_test(test_r_base64_decode);
  return NULL;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
