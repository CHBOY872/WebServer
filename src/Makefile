CC=gcc
CXX=g++

OPTIMIZATION=-O0
DEBUG=-g
RELEASE=-s

CFLAGS=-ansi -pedantic -pedantic-errors -Wall -Wextra -Werror \
           -fno-exceptions -fno-rtti -Wno-unused-parameter -Wno-unused-variable \
           -Wno-unused-but-set-variable -Wno-sign-compare \
           -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-label \
           -Wno-unused-value -Wno-unused-result -Wno-strict-aliasing \
           -Wno-format-security -Wno-format-overflow -Wno-format-truncation \
           -Wno-stringop-overflow -Wno-array-bounds -Wno-misleading-indentation \
           -Wno-implicit-fallthrough -Wno-undef -Wno-logical-op \
           -Wno-maybe-uninitialized -Wno-unused-local-typedefs \
           -Wno-unused-private-field -Wno-unused-parameter \
           -Wno-unused-const-variable -Wno-unused-but-set-parameter \
           -Wno-unused-variable -Wno-unused-lambda-capture
CXXFLAGS=$(CFLAGS)

SRCMODULES=$(shell find . -name "*.cpp" | grep -v "main.cpp")
OBJMODULES=$(SRCMODULES:.cpp=.o)

main: main.cpp
	$(CXX) $(DEBUG) $(CXXFLAGS) $< -o $@

ifneq ($(MAKECMDGOALS), clean)
-include deps.mk
endif

deps.mk:
	$(CC) -MM $(SRCMODULES) > $@
