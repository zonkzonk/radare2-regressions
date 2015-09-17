#include <r_list.h>
#include "minunit.h"

int tests_run = 0;

char* test_r_list_size(void) {
  // Test that r_list adding and deleting works correctly.
  int i;
  RList* list = r_list_new ();
  intptr_t test = 0x101010;
  // Add 100 items.
  for (i = 0; i < 100; ++i) {
    r_list_append (list, (void*)test);
    mu_assert("error, append gave wrong length", i + 1 == r_list_length (list));
  }
  // Delete 50 of them.
  for (i = 0; i < 50; ++i) {
    intptr_t val = (intptr_t)r_list_pop (list);
    mu_assert("error, pop gave wrong length", 99 - i == r_list_length (list));
  }
  // Purge the list.
  r_list_purge (list);
  mu_assert("error, purge didn't clear list", 0 == r_list_length (list));
  return NULL;
}

char* test_r_list_values(void) {
  RList* list = r_list_new ();
  intptr_t test1 = 0x12345;
  intptr_t test2 = 0x88888;
  r_list_append (list, (void*)test1);
  r_list_append (list, (void*)test2);
  mu_assert("error, first value not 0x88888",
      (intptr_t)0x88888 == (intptr_t)r_list_pop (list));
  mu_assert("error, first value not 0x12345",
      (intptr_t)0x12345== (intptr_t)r_list_pop (list));
  return NULL;
}

char* all_tests() {
  mu_run_test(test_r_list_size);
  mu_run_test(test_r_list_values);
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
