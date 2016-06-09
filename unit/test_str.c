#include <r_util.h>
#include "minunit.h"

bool test_r_str_replace_char_once(void) {
	char* str = strdup ("hello world");
	(void) r_str_replace_char_once (str, 'l', 'x');
	mu_assert_streq (str, "hexlo world", "error, replace char once failed");
	free (str);
	mu_end;
}

bool test_r_str_replace_char(void) {
	char* str = strdup ("hello world");
	(void) r_str_replace_char (str, 'l', 'x');
	mu_assert_streq (str, "hexxo worxd", "error, replace char multi failed");
	free (str);
	mu_end;
}

bool all_tests() {
	mu_run_test(test_r_str_replace_char_once);
	mu_run_test(test_r_str_replace_char);
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	return all_tests();
}
