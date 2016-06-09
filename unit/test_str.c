#include <r_util.h>
#include "minunit.h"

int tests_run = 0;
char* buf;

char* test_r_str_replace_char_once(void) {
	char* str = strdup ("hello world");
	bool bad = false;
	(void) r_str_replace_char_once (str, 'l', 'x');
	bad |= strcmp ("hexlo world", str);
	mu_assert ("error, replace char once failed", bad == 0);
	free (str);
	return NULL;
}

char* all_tests() {
	mu_run_test(test_r_str_replace_char_once);
	return NULL;
}

int main(int argc, char **argv) {
	buf = malloc (1024);
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	} else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	free (buf);
	return result != 0;
}
