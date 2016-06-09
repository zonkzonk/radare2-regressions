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

bool test_r_str_bits64(void) {
	char buf[65];
	(void)r_str_bits64 (buf, 0);
	mu_assert_streq (buf, "00000000", "binary of 0");
	(void)r_str_bits64 (buf, 1);
	mu_assert_streq (buf, "00000001", "binary of 1");
	(void)r_str_bits64 (buf, 2);
	mu_assert_streq (buf, "00000010", "binary of 2");
	mu_end;
}

bool all_tests() {
	mu_run_test(test_r_str_replace_char_once);
	mu_run_test(test_r_str_replace_char);
	mu_run_test(test_r_str_bits64);
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	return all_tests();
}
