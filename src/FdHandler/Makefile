-include ../define.mk

CSRCMODULES=$(shell find . -name "*.c")
CXXSRCMODULES=$(shell find . -name "*.cpp")

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(CPPSRCMODULES) $(CSRCMODULES)
	$(CC) -MM $^ > $@
