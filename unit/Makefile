OBJECTS = $(patsubst %.c,%,$(wildcard *.c))
LDFLAGS += $(shell pkg-config --libs r_util)
CFLAGS += $(shell pkg-config --cflags r_util) -g

all: $(OBJECTS)

$(OBJECTS):%:%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECTS)

.PHONY: all $(OBJECTS)
