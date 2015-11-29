TDIR=$(shell uname)-$(shell uname -m)

all:
ifndef TRAVIS
	@[ -d "$(TDIR)" ] && ( cd .. && sh run_tests.sh t.archos/$(TDIR) ) || true
endif
