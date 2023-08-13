CC=gcc
CXX=g++

DEFINE=
OPTIMIZATION=-O0
DEBUG=-g
RELEASE=-s

CFLAGS=-ansi -pedantic -Wall -static \
	   -pedantic-errors -Wextra -Werror \
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

INCLUDES=-IFdHandler -IWebServer
	
%.o: %.c %.h
	$(CC) $(DEFINE) $(DEBUG) $(CFLAGS) $(INCLUDES) $^ -c -o $@

%.o: %.cpp %.hpp
	$(CXX) $(DEFINE) $(DEBUG) $(CXXFLAGS) $(INCLUDES) $< -c -o $@

