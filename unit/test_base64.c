#include <r_util.h>
#include "minunit.h"

bool test_r_base64_decode(void) {
	char* hello = (char*)r_base64_decode_dyn ("aGVsbG8=", -1);
	mu_assert_streq(hello, "hello", "base64_decode_dyn");
	free (hello);
	mu_end;
}

int test_r_base64_encode(void) {
	char* hello = r_base64_encode_dyn("hello", -1);
	mu_assert_streq(hello, "aGVsbG8=", "base64_encode_dyn");
	free (hello);
	mu_end;
}

int all_tests() {
	mu_run_test(test_r_base64_decode);
	mu_run_test(test_r_base64_encode);
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	return all_tests();
}
