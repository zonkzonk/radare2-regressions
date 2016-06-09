all: test_list test_base64 test_str

LDFLAGS=-lr_util

test_list:
	$(CC) -g -I$(LIBR_INCLUDE) test_list.c $(LIBR_UTIL)/list.c -o test_list $(LDFLAGS)

test_base64:
	$(CC) -g -I$(LIBR_INCLUDE) test_base64.c $(LIBR_UTIL)/base64.c -o test_base64 $(LDFLAGS)

test_str:
	$(CC) -g -I$(LIBR_INCLUDE) test_base64.c $(LIBR_UTIL)/str.c -o test_str $(LDFLAGS)

clean:
	rm test_list test_base64 test_str

.PHONY: all test_list test_base64 test_str
