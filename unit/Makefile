OBJECTS = test_list test_base64 test_str test_hashtable
LDFLAGS += $(shell pkg-config r_util --libs)
CFLAGS += $(shell pkg-config r_util --cflags)

all: $(OBJECTS)

$(OBJECTS):%:%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
clean:
	rm -f test_list test_base64 test_str test_hashtable

.PHONY: all $(OBJECTS)
