TARGETS = x86-simple x64-simple

all: $(TARGETS)

clean:
	rm -f $(TARGETS) *.o


x86%.o: src/x86%.s
	nasm -f elf32 -o $@ $<

x64%.o: src/x64%.s
	nasm -f elf64 -o $@ $<

x86%: x86%.o
	ld -m elf_i386 -s -o $@ $<

x64%: x64%.o
	ld -m elf_x86_64 -s -o $@ $<

osx:
	@sh osx.sh

.PHONY: all clean
