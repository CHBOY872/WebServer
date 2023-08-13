-include ../define.mk

CSRCMODULES=$(shell find . -name "*.c" | grep -v test.c)
CXXSRCMODULES=$(shell find . -name "*.cpp" | grep -v test.cpp)

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(CPPSRCMODULES) $(CSRCMODULES)
	$(CC) -MM $^ > $@