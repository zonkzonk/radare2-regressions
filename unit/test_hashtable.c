#include <r_util.h>
#include "minunit.h"

bool test_r_hashtable_insert_lookup(void) {
	RHashTable* ht = r_hashtable_new ();
	char* test1_key = "AAAA";
	char* test2_key = "BBBB";
	char* test3_key = "CCCC";
	char* test1_data = "1111";
	char* test2_data = "2222";
	char* test3_data = "3333";
	char* data_lookup;
	mu_assert ("insert first key-value",
			r_hashtable_insert (ht, r_str_hash (test1_key), test1_data));
	mu_assert ("insert second key-value",
			r_hashtable_insert (ht, r_str_hash (test2_key), test2_data));
	mu_assert ("insert third key-value",
			r_hashtable_insert (ht, r_str_hash (test3_key), test3_data));
	data_lookup = r_hashtable_lookup (ht, r_str_hash (test1_key));
	mu_assert_streq (data_lookup, test1_data, "AAAA key value lookup");
	data_lookup = r_hashtable_lookup (ht, r_str_hash (test2_key));
	mu_assert_streq (data_lookup, test2_data, "AAAA key value lookup");
	data_lookup = r_hashtable_lookup (ht, r_str_hash (test3_key));
	mu_assert_streq (data_lookup, test3_data, "AAAA key value lookup");
	r_hashtable_free (ht);
	mu_end;
}

bool test_r_hashtable_removal_lookup(void) {
	RHashTable* ht = r_hashtable_new ();
	char* test1_key = "AAAA";
	char* test1_data = "1111";
	char* data_lookup;
	// First insert AAAA.
	mu_assert ("insert first key-value",
			r_hashtable_insert (ht, r_str_hash (test1_key), test1_data));
	// Check we can look it up.
	data_lookup = r_hashtable_lookup (ht, r_str_hash (test1_key));
	mu_assert_streq (data_lookup, test1_data, "AAAA key value lookup");
	// Now remove it, make sure it's really gone.
	r_hashtable_remove (ht, r_str_hash (test1_key));
	mu_assert_eq (
			(int)(intptr_t)r_hashtable_lookup (ht, r_str_hash (test1_key)), 0,
			"lookup of removed key");
	r_hashtable_free (ht);
	mu_end;
}

int all_tests() {
	mu_run_test(test_r_hashtable_insert_lookup);
	mu_run_test(test_r_hashtable_removal_lookup);
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	return all_tests();
}
