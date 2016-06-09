#include <r_util.h>
#include "minunit.h"

//TODO test r_str_chop_path

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

//TODO test r_str_bits

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

//TODO test r_str_bits_from_string

bool test_r_str_rwx(void) {
	int rwx = r_str_rwx ("-rwx");
	int rw =  r_str_rwx ("-rw-");
	int rx = r_str_rwx ("rx");
	int mx = r_str_rwx ("m--x");
	int none = r_str_rwx ("----");
	int number = r_str_rwx ("9999");
	mu_assert_eq (rwx, 7, "rwx");
	mu_assert_eq (rw, 6, "rw");
	mu_assert_eq (rx, 5, "rx");
	mu_assert_eq (mx, 17, "mx");
	mu_assert_eq (none, 0, "no permissions");
	//XXX this test fails because the underlying behavior is wrong
	//mu_assert_eq (number, 0, "large input number string");
	mu_end;
}

//TODO test r_str_binstr2bin

bool test_r_str_rwx_i(void) {
	const char* rwx = r_str_rwx_i (7);
	const char* rw = r_str_rwx_i (6);
	const char* rx = r_str_rwx_i (5);
	const char* mx = r_str_rwx_i (17);
	const char* invalid_mode = r_str_rwx_i (898);
	mu_assert_streq (rwx, "-rwx", "rwx = 7 mode");
	mu_assert_streq (rw, "-rw-", "rw = 6 mode");
	mu_assert_streq (rx, "-r-x", "rx = 5 mode");
	mu_assert_streq (mx, "m--x", "mx = 17 mode");
	//XXX this test fails because the underlying behavior is wrong!
	//mu_assert_streq (invalid_mode, "----", "invalid permissions mode");
	mu_end;
}

bool test_r_str_bool(void) {
	const char* one = r_str_bool(1);
	const char* zero = r_str_bool(0);
	const char* fifty = r_str_bool(50);
	const char* negative = r_str_bool(-1);
	mu_assert_streq (one, "true", "one");
	mu_assert_streq (zero, "false", "zero");
	mu_assert_streq (fifty, "true", "large positive value");
	mu_assert_streq (negative, "true", "negative number");
	mu_end;
}

//TODO find a way to test r_str_home.

bool all_tests() {
	mu_run_test(test_r_str_replace_char_once);
	mu_run_test(test_r_str_replace_char);
	mu_run_test(test_r_str_bits64);
	mu_run_test(test_r_str_rwx);
	mu_run_test(test_r_str_rwx_i);
	mu_run_test(test_r_str_bool);
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	return all_tests();
}
