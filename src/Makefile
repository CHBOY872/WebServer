-include define.mk

OBJMODULES=FdHandler/FdHandler.o \

FdHandler/FdHandler.o:
	cd FdHandler && make

main: main.cpp $(OBJMODULES)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(INCLUDES) $^ -o $@

clean:
	rm $(OBJMODULES)