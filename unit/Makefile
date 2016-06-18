OBJECTS = test_list test_base64 test_str test_hashtable test_debruijn
LDFLAGS += $(shell pkg-config --libs r_util)
CFLAGS += $(shell pkg-config --cflags r_util) -g

all: $(OBJECTS)

$(OBJECTS):%:%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
clean:
	rm -f $(OBJECTS)

.PHONY: all $(OBJECTS)
