#include <r_list.h>
#include "minunit.h"

bool test_r_list_size(void) {
	// Test that r_list adding and deleting works correctly.
	int i;
	RList* list = r_list_new ();
	intptr_t test = 0x101010;
	// Add 100 items.
	for (i = 0; i < 100; ++i) {
		r_list_append (list, (void*)test);
		mu_assert_eq (r_list_length (list), i + 1, "r_list_length failed on append");
	}
	// Delete 50 of them.
	for (i = 0; i < 50; ++i) {
		(void)r_list_pop (list);
		mu_assert_eq(99 - i, r_list_length (list), "r_list_length failed on pop");
	}
	// Purge the list.
	r_list_purge (list);
	mu_assert_eq(0, r_list_length (list), "r_list_length failed on purged list");
	r_list_free (list);
	mu_end;
}

bool test_r_list_values(void) {
	RList* list = r_list_new ();
	intptr_t test1 = 0x12345;
	intptr_t test2 = 0x88888;
	r_list_append (list, (void*)test1);
	r_list_append (list, (void*)test2);
	int top1 = (intptr_t)r_list_pop (list);
	int top2 = (intptr_t)r_list_pop (list);
	mu_assert_eq(top1, 0x88888, "first value not 0x88888");
	mu_assert_eq(top2, 0x12345, "first value not 0x12345");
	r_list_free (list);
	mu_end;
}

bool test_r_list_join(void) {
	RList* list1 = r_list_new ();
	RList* list2 = r_list_new ();
	intptr_t test1 = 0x12345;
	intptr_t test2 = 0x88888;
	r_list_append (list1, (void*)test1);
	r_list_append (list2, (void*)test2);
	int joined = r_list_join (list1, list2);
	mu_assert_eq(joined, 1, "r_list_join of two lists");
	mu_assert_eq(r_list_length (list1), 2, "r_list_join two single element lists result length is 1");
	r_list_free (list1);
	r_list_free (list2);
	mu_end;
}


bool test_r_list_free(void) {
	RList* list = r_list_newf ((void*)0x9999);
	mu_assert_eq((int)(intptr_t)list->free, 0x9999, "r_list_newf function gets set properly");
	r_list_free (list);
	mu_end;
}

bool test_r_list_del_n(void) {
	RList* list = r_list_new ();
	intptr_t test1 = 0x12345;
	intptr_t test2 = 0x88888;
	r_list_append (list, (void*)test1);
	r_list_append (list, (void*)test2);
	mu_assert_eq (r_list_length (list), 2,
			"list is of length 2 when adding 2 values");
	r_list_del_n (list, 0);
	int top1 = (intptr_t)r_list_pop (list);
	mu_assert_eq(top1, 0x88888,
			"error, first value not 0x88888");
	r_list_free (list);
	mu_end;
}

bool test_r_list_sort(void) {
	RList* list = r_list_new ();
	char* test1 = "AAAA";
	char* test2 = "BBBB";
	char* test3 = "CCCC";
	// Put in not sorted order.
	r_list_append (list, (void*)test1);
	r_list_append (list, (void*)test3);
	r_list_append (list, (void*)test2);
	// Sort.
	r_list_sort (list, (RListComparator)strcmp);
	// Check that the list is actually sorted.
	mu_assert_streq (list->head->data, "AAAA", "first value in sorted list");
	mu_assert_streq (list->head->n->data, "BBBB", "second value in sorted list");
	mu_assert_streq (list->head->n->n->data, "CCCC", "third value in sorted list");
	r_list_free (list);
	mu_end;
}

int all_tests() {
	mu_run_test(test_r_list_size);
	mu_run_test(test_r_list_values);
	mu_run_test(test_r_list_join);
	mu_run_test(test_r_list_free);
	mu_run_test(test_r_list_del_n);
	mu_run_test(test_r_list_sort);
	return 0;
}

int main(int argc, char **argv) {
	return all_tests();
}
