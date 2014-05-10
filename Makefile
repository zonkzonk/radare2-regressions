# XXX
PULLADDR=https://github.com/radare/radare2-regressions.git

do:
	-git pull ${PULLADDR}
	@sh run_tests.sh

all:
	@sh run_tests.sh
	@sh run_tests.sh t.asm
	@sh run_tests.sh t.archos
	@sh run_tests.sh t.formats
	@sh run_tests.sh t.formats/pe
	@sh run_tests.sh t.formats/elf
	@sh run_tests.sh t.formats/java
	@sh run_tests.sh t.formats/match0

asm:
	@sh run_tests.sh t.asm
	@sh run_tests.sh t.asm/udis86
	@sh run_tests.sh t.asm/capstone

formats:
	@sh run_tests.sh t.formats
	@sh run_tests.sh t.formats/pe
	@sh run_tests.sh t.formats/elf
	@sh run_tests.sh t.formats/java
	@sh run_tests.sh t.formats/match0

udis86:
	@sh run_tests.sh t.asm/udis86

capstone:	
	@sh run_tests.sh t.asm/capstone

broken:
	@cd t ; grep BROKEN=1 * | cut -d : -f1 |sort -u

clean:
	rm -rf tmp

.PHONY: all clean
